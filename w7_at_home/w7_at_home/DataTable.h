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

			T accumulatedX = [&](T& incomingArr) -> T { return (std::accumulate(incomingArr.begin(), incomingArr.end(), 0.0)); };

			//T accumulatedY = [=]() { return (std::accumulate(yValue.begin(), yValue.end(), 0.0)); };

			// T xMean = [=]() { return (accumulatedX / xValue.size()); };

			// T yMean = [=]() { return (accumulatedY / yValue.size()); };

			// T XstandardDeviation = [=]() {
			// 	T temp{0.0f};
			// 	for (size_t index = 0; index < xValue.size(); index++)
			// 	{
			// 		temp += pow((xValue.at(index) - xMean), 2);
			// 	}
			// 	return (std::sqrt(temp / (xValue.size() - 1)));
			// };

			// T YstandardDeviation = [=]() {
			// 	T temp{0.0f};
			// 	for (size_t index = 0; index < yValue.size(); index++)
			// 	{
			// 		temp += pow((yValue.at(index) - yMean), 2);
			// 	}
			// 	return (std::sqrt(temp / (yValue.size() - 1)));
			// };

			// T XYcorrelation = [=]() {
			// 	T temp{0.0f};
			// 	for (size_t index = 0; index < xValue.size(); index++)
			// 	{
			// 		temp += (xValue.at(index) - xMean) * (yValue.at(index) - yMean);
			// 	}
			// 	T temp2 = temp / (XstandardDeviation * YstandardDeviation);
			// 	T temp3 = temp2 / (xValue.size() - 1);
			// 	return (temp3);
			// };

			// T XYslope = [=]() { return (XYcorrelation * (YstandardDeviation / XstandardDeviation)); };

			// T Yintercept = [=]() {
			// 	return (yMean - (XYslope * xMean));
			// };

			// T median = [=]() {
			// 	std::deque<T> temp;
			// 	temp = yValue;
			// 	size_t sizeOfVector = std::size(temp);
			// 	std::sort(temp.begin(), temp.end());
			// 	return (temp.at(sizeOfVector / 2));
			// };

			int numOfRecords{ 0 };

		public:

			//single argument constructor, initializes object with values from incoming file 
			DataTable(std::ifstream &incomingFileObject)
			{
				std::string temp;

				T tempNum{ 0 };
				T tempPrice{ 0.0f };

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
						<< " y"
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
				// int myPrecision = ND;

				os << "\nStatistics" << "\n----------" << std::endl;

				os << accumulatedX(yValue) std::endl;
				// os << std::left << std::setw(12) << "  y mean" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << yMean << std::endl;
    			// os << std::left << std::setw(12) << "  y sigma" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << YstandardDeviation << std::endl;
    			// os << std::left << std::setw(12) << "  y median" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::fixed << std::setprecision(4) << median << std::endl;
    			// os << std::left << std::setw(12) << "  slope" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << XYslope << std::endl;
    			// os << std::left << std::setw(12) << "  intercept" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << Yintercept << std::endl;
			}
		};
}

#endif //SICT_DATA_TABLE_H
