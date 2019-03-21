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

		//private query, used to calculate and return deviation, mean, correlation, and the y-intercept
		T calculateValues(std::string identifier) const
		{
			double xMean{ 0.0f };
			double yMean{ 0.0f };
			double XstandardDeviation{ 0.0f };
			double YstandardDeviation{ 0.0f };
			double XYcorrelation{ 0.0f };
			double XYslope{ 0.0f };
			double Yintercept{ 0.0f };

			double accumulatedX = std::accumulate(xValue.begin(), xValue.end(), 0.0);
			double accumulatedY = std::accumulate(yValue.begin(), yValue.end(), 0);

			//calculating mean
			xMean = accumulatedX / xValue.size();
			yMean = accumulatedY / yValue.size();

			//calculating standard deviation for x
			{
				double temp{ 0.0f };
				for (size_t index = 0; index < xValue.size(); index++)
				{
					temp += pow((xValue.at(index) - xMean), 2);
				}
				XstandardDeviation = std::sqrt(temp / (xValue.size() - 1));
			}

			//calculating standard deviation for y
			{
				double temp{ 0.0f };
				for (size_t index = 0; index < yValue.size(); index++)
				{
					temp += pow((yValue.at(index) - yMean), 2);
				}
				YstandardDeviation = std::sqrt(temp / (yValue.size() - 1));
			}

			//calculating correlation
			{
				double temp{ 0.0f };
				for (size_t index = 0; index < xValue.size(); index++)
				{
					temp += (xValue.at(index) - xMean)*(yValue.at(index) - yMean);
				}
				double temp2 = temp / (XstandardDeviation * YstandardDeviation);
				double temp3 = temp2 / (xValue.size() - 1);
				XYcorrelation = temp3;
			}

			//calculating slope
			XYslope = XYcorrelation * (YstandardDeviation / XstandardDeviation);

			//calculating Y-intercept
			Yintercept = yMean - (XYslope*xMean);

			if (identifier == "slope")
				return XYslope;
			else if (identifier == "yintercept")
				return Yintercept;
			else if (identifier == "yssd")
				return YstandardDeviation;
			else if (identifier == "xssd")
				return XstandardDeviation;
			else if (identifier == "xmean")
				return xMean;
			else if (identifier == "ymean")
				return yMean;
			else
				throw("wtf do u want!?");
		}

	public:

		//single argument constructor, initializes object with values from incoming file 
		DataTable(std::ifstream &incomingFileObject)
		{
			xValue.clear();
			yValue.clear();
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
				std::sort(this->yValue.begin(), this->yValue.end());
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

			T median;
			if ((yValue.size() % 2) != 0)
				median = yValue.at(yValue.size() / 2);
			else
				median = (yValue.at((yValue.size()/2) - 1) + yValue.at((yValue.size()/2) + 1)) / 2;


			os << "\nStatistics" << "\n----------" << std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y mean "
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth+1)
				<< std::setprecision(myPrecision) << calculateValues("ymean")
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y sigma"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth+1)
				<< std::setprecision(myPrecision) << calculateValues("yssd")
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "y median"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth + 1)
				<< std::setprecision(myPrecision) << median 
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "slope"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth + 1)
				<< std::setprecision(myPrecision) << calculateValues("slope")
				<< std::endl;

			os << std::right << std::fixed
				<< std::setw(myFieldWidth + 1)
				<< "intercept"
				<< std::setw(4)
				<< "="
				<< std::right << std::fixed << std::setw(myFieldWidth + 1)
				<< std::setprecision(myPrecision) << calculateValues("yintercept")
				<< std::endl;
		}
	};
}

#endif //SICT_DATA_TABLE_H
