//	program		:	DataTable.h
//	programmer	:	Yathavan, Parameshwaran
//	date 		:	March 15, 2019
// 	professor	:	Chris, Szalwinski

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <math.h>

extern int FW;
extern int ND;

namespace sict
{
	template <typename T>
	class DataTable
	{
		std::deque<T> myPrice;
		std::deque<T> myProductNum;

		int numOfRecords{ 0 };

		//private query, used to calculate and return sample standard deviation
		T deviatedValues() const
		{
			T mean, deviation, variableVariance;
			std::deque<T> variation;

			T accumulatedValues = std::accumulate(myProductNum.begin(), myProductNum.end(), 0);
			mean = accumulatedValues / myProductNum.size();

			for (long unsigned int index = 0; index < myProductNum.size(); index++)
			{
				variation.push_back(
					(myProductNum.at(index) - mean)*(myProductNum.at(index) - mean)
				);
			}
			T accumulationOfVariances = std::accumulate(variation.begin(), variation.end(), 0);

			variableVariance = accumulationOfVariances / (variation.size() - 1);

			deviation = sqrt(variableVariance);

			return deviation;
		}

	public:

		//single argument constructor, initializes object with values from incoming file 
		DataTable(std::ifstream &incomingFileObject)
		{
			std::string temp;

			int tempNum{ 0 };
			double tempPrice{ 0.0f };

			if (incomingFileObject.is_open())
			{
				while (!incomingFileObject.eof() && incomingFileObject.good()) 
				{
					std::getline(incomingFileObject, temp, '\n');

					int positionFirstSpace = temp.find_first_of(' ');

					tempPrice = std::stof(temp.substr(0, positionFirstSpace));
					tempNum = std::stof(temp.substr(positionFirstSpace, temp.length()));

					myPrice.push_back(tempPrice);
					myProductNum.push_back(tempNum);

					temp.clear();
					tempNum = 0;
					tempPrice = 0.0f;

					numOfRecords++;
				}
			}
		}

		//display query, prints contents of deque to display
		void displayData(std::ostream &os) const
		{
			int myFieldWidth = FW;
			int myPrecision = ND;

			if (numOfRecords == 0)
			{
				throw("ERROR: container is empty!");
			}
			else
			{
				os << "Data Values" << "\n------------" << std::endl;

				os << std::right << std::fixed
					<< std::setw(myFieldWidth)
					<< "x"
					<< std::setw(myFieldWidth)
					<< "y"
					<< std::endl;

				for (int index = 0; index < numOfRecords; index++)
				{
					os << std::right << std::fixed
						<< std::setw(myFieldWidth)
						<< std::setprecision(myPrecision) << myPrice.at(index)
						<< std::setw(myFieldWidth)
						<< std::setprecision(myPrecision) << myProductNum.at(index)
						<< std::endl;
				}
			}
		}

		//display query, displays the calculated statistics of the object's values
		void displayStatistics(std::ostream &os) const
		{
			int myFieldWidth = FW;
			int myPrecision = ND;

			T accumulatedValues = std::accumulate(myProductNum.begin(), myProductNum.end(), 0);

			os << "\nStatistics" << "\n----------" << std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y mean "
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth+1)
				<< std::setprecision(myPrecision) << accumulatedValues / myProductNum.size()
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y sigma"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth+1)
				<< std::setprecision(myPrecision) << deviatedValues()
				<< std::endl;
		}
	};
}

#endif //SICT_DATA_TABLE_H
