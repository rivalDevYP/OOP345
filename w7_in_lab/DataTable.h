//	program		:	DataTable.h
//	programmer	:	Yathavan, Parameshwaran
//	date 		:	March 15, 2019
// professor	:	Chris, Szalwinski

#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H

#include <iostream>
#include <fstream>
#include <deque>

namespace sict
{
	class DataTable
	{
		std::deque<double> myPrice;
		std::deque<int> myProductNum;
		int numOfRecords{0};
		std::deque<std::string> extractedFileContents;

	public:
		DataTable(std::ifstream& incomingFileObject);
		void displayData(std::ostream& os) const;
		void displayStatistics(std::ostream& os) const;
	};
}

#endif //SICT_DATATABLE_H
