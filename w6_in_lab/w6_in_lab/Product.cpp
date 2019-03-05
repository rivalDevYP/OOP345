#include "Product.h"

namespace sict
{
	extern int FW;

	Product::Product(long incomingProductNum, double incomingPrice)
	{
		this->myProductNum = incomingProductNum;
		this->myPrice = incomingPrice;
	}

	double Product::price() const
	{
		return this->myPrice;
	}

	void Product::display(std::ostream & os) const
	{
		os << std::right << std::setw(FW) 
			<< this->myPrice 
			<< std::right << std::setw(FW) 
			<< this->myProductNum 
			<< std::endl;
	}


	//global functions

	iProduct* readRecord(std::ifstream& file)
	{
		static int callCount{ 0 };
		long proNum{ 0 };
		double price{ 0.0f };
		std::string temppstr;
		std::string* tempStr;
		int index{ 0 };

		if (file.is_open() && callCount == 0)
		{
			size_t counter{ 0 };
			while (!file.eof() && file.good())
			{
				std::getline(file, temppstr, '\n');
				temppstr.clear();
				counter++;
			}
			if (file.eof())
			{
				file.clear();
				file.seekg(0, file.beg);
			}
			tempStr = new std::string[counter];
			while (!file.eof() && file.good())
			{
				std::getline(file, tempStr[index], '\n');
			}
		}
		proNum = std::stol(tempStr[callCount++].substr(0, tempStr[callCount++].find(' ')));
		price = std::stod(tempStr[callCount++].substr(tempStr[callCount++].find(' '), tempStr[callCount++].length()));
		return &Product(proNum, price);
	}

	std::ostream& sict::operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
}