//	program		:	DataTable.h
//	programmer	:	Yathavan, Parameshwaran
//	date 		:	March 15, 2019
// professor	:	Chris, Szalwinski

#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <algorithm>
#include <numeric>

extern int FW;
extern int ND;

namespace sict
{
	template <typename T>
		class DataTable
		{
			std::deque<T> myPrice;
			std::deque<T> myProductNum;

			int numOfRecords{0};

		public:
			DataTable(std::ifstream &incomingFileObject)
			{
				std::string temp;

				int tempNum{0};
				double tempPrice{0.0f};

				if (incomingFileObject.is_open())
				{
					while (!incomingFileObject.eof() && incomingFileObject.good()) //while end of file has not been met and object still good
					{
						std::getline(incomingFileObject, temp, '\n'); //extracting string line by line

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
					os << "Data Values " << "\n------------" << std::endl;
					
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

			void displayStatistics(std::ostream &os) const
			{
				int myFieldWidth = FW;
				int myPrecision = ND;

				T accumulatedValues = std::accumulate(myPrice.begin(), myPrice.end(), 0);

				os << "\n\nStatistics" << "\n----------" << std::endl;

				os << std::right << std::fixed
					<< std::setw(myFieldWidth+1)
					<< "y mean "
					<< std::setw(4)
					<< "="
					<< std::right << std::fixed << std::setw(myFieldWidth)
					<< std::setprecision(myPrecision) << accumulatedValues
					<< std::endl;

				os << std::right << std::fixed
					<< std::setw(myFieldWidth+1) 
					<< "y sigma"
					<< std::setw(4)
					<< "="
					<< std::right << std::fixed << std::setw(myFieldWidth)
					<< std::setprecision(myPrecision) << accumulatedValues / myPrice.size()
					<< std::endl;
			}
		};
}

#endif //SICT_DATATABLE_H
