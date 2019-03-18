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

namespace sict
{
	int FW;

	template <typename T>
		class DataTable
		{
			std::deque<T> myPrice;
			std::deque<int> myProductNum;
			int numOfRecords{0};
			std::deque<std::string> extractedFileContents;

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

						tempNum = std::stoi(temp.substr(0, positionFirstSpace));
						tempPrice = std::stod(temp.substr(positionFirstSpace, temp.length()));

						extractedFileContents.push_back(temp);
						myProductNum.push_back(tempNum);
						myPrice.push_back(tempPrice);

						temp.clear();
						tempNum = 0;
						tempPrice = 0.0f;

						numOfRecords++;
					}

					// # use if need to go back to beginning of the file
					// if (incomingFileObject.eof()) //if end of file met
					// {
					//     incomingFileObject.clear(); //clear any error flags
					//     incomingFileObject.seekg(0, incomingFileObject.beg); //go back to the beginning of the file
					// }
				}
			}

			void displayData(std::ostream &os) const
			{
				if (extractedFileContents.empty())
				{
					throw("ERROR: container is empty!");
				}
				else
				{
					int myFieldWidth = FW;

					os << std::right
						<< std::setw(myFieldWidth)
						<< "x "
						<< std::setw(myFieldWidth)
						<< "y"
						<< std::endl;

					for (int index = 0; index < extractedFileContents.size(); index++)
					{
						os << std::setprecision(4)
							<< std::right
							<< std::setw(myFieldWidth)
							<< myPrice.at(index)
							<< " "
							<< myProductNum.at(index)
							<< std::endl;
					}
				}
			}

			void displayStatistics(std::ostream &os) const
			{
				int myFieldWidth = FW;

				os << "y mean"
					<< std::setw(myFieldWidth)
					<< " = "
					<< std::accumulate(myProductNum.begin(), myProductNum.end(), 0)
					<< '\n'
					<< "y sigma"
					<< std::setw(myFieldWidth)
					<< " = "
					<< (std::accumulate(myProductNum.begin(), myProductNum.end(), 0) / myProductNum.size())
					<< std::endl;
			}
		};
} // namespace sict

#endif //SICT_DATATABLE_H
