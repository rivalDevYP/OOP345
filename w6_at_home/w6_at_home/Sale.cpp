//	program		:	Sale.cpp
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 13, 2019
//	professor	:	Chris, Szalwinski

#include "Sale.h"

extern int FW;

namespace sict
{
	//1 arg. constructor, recieves file name to extract fields from
	Sale::Sale(const char* incomingFileName)
	{
		std::ifstream fileptr(incomingFileName);
		if (fileptr.good())
		{
			std::string temp;
			for (int index = 0; index < 10; index++)
			{
				try {
					proObj.push_back(readRecord(fileptr));
				}
				catch (const char* errMsg) {
					break;
				}
			}
		}
		else
		{
			throw("file not found...");
		}
	}

	//display query, prints products to output
	void Sale::display(std::ostream& os) const
	{
		int field = FW;
		double totalPrice{ 0.0 };

		os << std::right << std::setw(field) << "\nProduct No"
			<< std::right << std::setw(field) << "  Cost"
			<< std::right << " " << "Taxable"
			<< std::endl;

		for (size_t index = 0; index < proObj.size(); index++)
		{
			os << std::right << std::setw(field) << std::fixed << std::setprecision(2);
			proObj.at(index)->display(os);

			totalPrice = totalPrice + proObj.at(index)->price();
		}

		os << std::right
			<< std::setw(field)
			<< "Total" << std::setw(field)
			<< totalPrice
			<< std::endl;
	}
}
