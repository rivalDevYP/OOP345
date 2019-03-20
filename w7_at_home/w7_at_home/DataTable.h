//	program		:	DataTable.h
//	programmer	:	Yathavan, Parameshwaran
//	date 		:	March 15, 2019
// 	professor	:	Chris, Szalwinski

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#define _CRT_SECURE_NO_WARNINGS

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
		std::deque<T> xValue;
		std::deque<T> yValue;

		int numOfRecords{ 0 };

		//private query, used to calculate and return sample standard deviation
		T deviatedValues() const
		{
			T mean, deviation, variableVariance;
			std::deque<T> variation;

			T accumulatedValues = std::accumulate(yValue.begin(), yValue.end(), 0);
			mean = accumulatedValues / yValue.size();

			for (long unsigned int index = 0; index < yValue.size(); index++)
			{
				variation.push_back(
					(yValue.at(index) - mean)*(yValue.at(index) - mean)
				);
			}
			T accumulationOfVariances = std::accumulate(variation.begin(), variation.end(), 0);

			variableVariance = accumulationOfVariances / (variation.size() - 1);

			deviation = sqrt(variableVariance);

			return deviation;
		}

		//private query, used to calculate and return slope
		T slopeIntercept(int selectorKey) const
		{
			T Exy{};
			for (int index = 0; index < xValue.size(); index++)
			{
				Exy = Exy+xValue.at(index)*yValue.at(index);
			}

			T accumulatedXs = std::accumulate(xValue.begin(), xValue.end(), 0);
			T accumulatedYs = std::accumulate(yValue.begin(), yValue.end(), 0);

			T accumulatedXsSquared = (accumulatedXs*accumulatedXs);

			T intercept = ((accumulatedYs*accumulatedXsSquared) - (accumulatedXs)*(Exy))/(xValue.size()*accumulatedXsSquared)-powl(accumulatedXs,2);
			T slope = xValue.size()*(Exy)-(accumulatedXs*accumulatedYs) / ((xValue.size()*(accumulatedXsSquared)) - powl(accumulatedXs, 2));

			if (selectorKey == 1)
				return slope;
			else
				return intercept;

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

					xValue.push_back(tempPrice);
					yValue.push_back(tempNum);

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
						<< std::setprecision(myPrecision) << xValue.at(index)
						<< std::setw(myFieldWidth)
						<< std::setprecision(myPrecision) << yValue.at(index)
						<< std::endl;
				}
			}
		}

		//display query, displays the calculated statistics of the object's values
		void displayStatistics(std::ostream &os) const
		{
			int myFieldWidth = FW;
			int myPrecision = ND;

			T accumulatedValues = std::accumulate(yValue.begin(), yValue.end(), 0);

			T intercept;

			std::sort(yValue.begin(), yValue.end(),std::greater<T>());
			T median = yValue[yValue.size() / 2];


			os << "\nStatistics" << "\n----------" << std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y mean "
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth+1)
				<< std::setprecision(myPrecision) << accumulatedValues / yValue.size() 
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y sigma"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth+1)
				<< std::setprecision(myPrecision) << deviatedValues() 
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y median"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth + 1)
				<< std::setprecision(myPrecision) << median // change to calculate median
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "slope"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth + 1)
				<< std::setprecision(myPrecision) << slopeIntercept(1)
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "intercept"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth + 1)
				<< std::setprecision(myPrecision) << slopeIntercept(2)
				<< std::endl;
		}
	};
}

#endif //SICT_DATA_TABLE_H
