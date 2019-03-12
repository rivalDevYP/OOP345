//	program		:	Product.cpp
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 5, 2019
//	professor	:	Chris, Szalwinski

#include "Product.h"

extern int FW;

namespace sict
{
	Product::Product()
	{

	}

	//2 arg. constructor, initialized object w/ incoming params
	Product::Product(long incomingProductNum, double incomingPrice)
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
		static int callCount{ 0 };
		long proNum{ 0 };
		double price{ 0.0f };
		char taxableStatus{ '\0' };
		std::string temppstr;
		static std::string* tempStr;
		int index{ 0 };

		if (file.is_open() && callCount == 0)
		{
			size_t counter{ 0 };

			if (file.eof())
			{
				file.clear();
				file.seekg(0, file.beg);
			}

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
				std::getline(file, tempStr[index++], '\n');
			}
		}
		if (tempStr[callCount].length() < 13)
		{
			proNum = std::stol(tempStr[callCount].substr(0, tempStr[callCount].find(' ')));
			price = std::stod(tempStr[callCount].substr(tempStr[callCount].find(' '), tempStr[callCount].length()));
			callCount++;
			return new Product(proNum, price);
		}
		else
		{
			proNum = std::stol(tempStr[callCount].substr(0, tempStr[callCount].find(' ')));
			price = std::stod(tempStr[callCount].substr(tempStr[callCount].find(' '), tempStr[callCount].length()));
			taxableStatus = tempStr[callCount].at(12);
			callCount++;
			return new TaxableProduct(proNum, price, taxableStatus);
		}
	}

	//ostream overload, prints iProduct object to output
	std::ostream& operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
	TaxableProduct::TaxableProduct(unsigned int incomingProNum, double incomingPrice, char incomingTaxType) : Product(incomingProNum, incomingPrice)
	{
		isTaxable = incomingTaxType;
	}
	double TaxableProduct::price() const
	{
		if (isTaxable == 'H')
		{
			double tempPrice = this->price();
			double tax = (tempPrice / 100) * HST;
			return tempPrice + tax;
		}
		else if (isTaxable == 'P')
		{
			double tempPrice = this->price();
			double tax = (tempPrice / 100) * PST;
			return tempPrice + tax;
		}
	}
	void TaxableProduct::display(std::ostream & os) const
	{
		os << isTaxable;
	}
}
