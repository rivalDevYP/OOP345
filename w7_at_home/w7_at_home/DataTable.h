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

			T accumulatedX{};
			T accumulatedY{};
			T xMean{};
			T yMean{};
			T XstandardDeviation{};
			T YstandardDeviation{};
			T XYcorrelation{};
			T XYslope{};
			T Yintercept{};
			T median{};

			int numOfRecords{ 0 };

		public:

			//single argument constructor, initializes object with values from incoming file 
			DataTable(std::ifstream &incomingFileObject)
			{
				xValue.clear();
				yValue.clear();
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
				
				accumulatedX = std::accumulate(xValue.begin(), xValue.end(), 0.0);
				accumulatedY = std::accumulate(yValue.begin(), yValue.end(), 0.0);

				xMean = accumulatedX / xValue.size();
				yMean = accumulatedY / yValue.size();

				{
					T temp{ 0.0f };
					for (size_t index = 0; index < xValue.size(); index++)
					{
						temp += pow((xValue.at(index) - xMean), 2);
					}
					XstandardDeviation = std::sqrt(temp / (xValue.size() - 1));
				}

				{
					T temp{ 0.0f };
					for (size_t index = 0; index < yValue.size(); index++)
					{
						temp += pow((yValue.at(index) - yMean), 2);
					}
					YstandardDeviation = std::sqrt(temp / (yValue.size() - 1));
				}

				{
					T temp{ 0.0f };
					for (size_t index = 0; index < xValue.size(); index++)
					{
						temp += (xValue.at(index) - xMean)*(yValue.at(index) - yMean);
					}
					T temp2 = temp / (XstandardDeviation * YstandardDeviation);
					T temp3 = temp2 / (xValue.size() - 1);
					XYcorrelation = temp3;
				}

				{
					std::deque<T> temp;
					temp = yValue;
					std::sort(temp.begin(), temp.end());
					if ((temp.size() % 2) != 0)
						median = temp.at(temp.size() / 2);
					else
						median = (temp.at((temp.size() / 2) - 1) + temp.at((temp.size() / 2) + 1)) / 2;
				}
				
				XYslope = XYcorrelation * (YstandardDeviation / XstandardDeviation);

				Yintercept = yMean - (XYslope*xMean);
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
				int myPrecision = ND;

				os << "\nStatistics" << "\n----------" << std::endl;

				os << std::left << std::setw(12) << "  y mean" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << yMean << std::endl;
    			os << std::left << std::setw(12) << "  y sigma" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << YstandardDeviation << std::endl;
    			os << std::left << std::setw(12) << "  y median" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << median << std::endl;
    			os << std::left << std::setw(12) << "  slope" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << XYslope << std::endl;
    			os << std::left << std::setw(12) << "  intercept" << std::left << std::setw(3) << "=" << std::right << std::setw(7) << std::setprecision(myPrecision) << Yintercept << std::endl;
			}
		};
}

#endif //SICT_DATA_TABLE_H
