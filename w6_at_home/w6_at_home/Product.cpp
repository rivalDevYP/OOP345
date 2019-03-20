//	program		:	Product.cpp
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 5, 2019
//	professor	:	Chris, Szalwinski

#include "Product.h"

extern int FW;

namespace sict
{
	Product::Product() {}

	//2 arg. constructor, initialized object w/ incoming params
	Product::Product(size_t incomingProductNum, double incomingPrice)
	{
		this->myProductNum = incomingProductNum;
		this->myPrice = incomingPrice;
	}

	//price query, returns price
	double Product::price() const
	{
		return this->myPrice;
	}

	//display query, prints product description to output
	void Product::display(std::ostream & os) const
	{
		int fieldWidth = FW;

		os << this->myProductNum
			<< std::setw(fieldWidth)
			<< this->myPrice
			<< " " << std::endl;
	}

	//readRecord, reads records from incoming file object
	iProduct* readRecord(std::ifstream& file)
	{
		std::string temp;
		size_t proNum{ 0 };
		double priceVar{ 0.0f };

		std::getline(file, temp, '\n');

		if (!temp.empty())
		{
			proNum = std::stoi(temp.substr(0, temp.find_first_of(' ')));
			priceVar = std::stod(temp.substr(temp.find_first_of(' '), temp.length()));
			temp.clear();
			return new Product(proNum, priceVar);
		}
		else
		{
			throw("end of file met!");
		}
	}

	//ostream overload, prints iProduct object to output
	std::ostream& operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
}
