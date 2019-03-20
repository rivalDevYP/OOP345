//	program		:	Product.cpp
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 13, 2019
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

	//ostream overload, prints iProduct object to output
	std::ostream& operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}

	//3 arg. constructor, initializes TaxableProduct object
	TaxableProduct::TaxableProduct(size_t incomingProductNum, double incomingPrice, char incomingTaxStatus) : Product(incomingProductNum, incomingPrice)
	{
		taxableStatus = incomingTaxStatus;
	}

	//overloaded price query
	double TaxableProduct::price() const
	{
		if (this->taxableStatus != '\n')
		{
			double newPrice = this->myPrice / 100;

			double addTax{ 0.0f };

			if (taxableStatus == 'H')
			{
				addTax = newPrice * HST;
			}
			else if (taxableStatus == 'P')
			{
				addTax = newPrice * PST;
			}

			return (this->myPrice + addTax);
		}
		else
		{
			return this->myPrice;
		}
	}

	//overloaded display query
	void TaxableProduct::display(std::ostream & os) const
	{
		int fieldWidth = FW;
		std::string temp;

		if (this->taxableStatus == '\n')
		{
			int fieldWidth = FW;

			os << this->myProductNum
				<< std::setw(fieldWidth)
				<< this->myPrice
				<< " " << std::endl;
		}
		else
		{
			if (this->taxableStatus == 'H')
				temp = "HST";
			if (this->taxableStatus == 'P')
				temp = "PST";

			os << this->myProductNum
				<< std::setw(fieldWidth)
				<< this->myPrice
				<< " "
				<< temp
				<< " " << std::endl;
		}
	}

	//readRecord, reads records from incoming file object
	iProduct* readRecord(std::ifstream& file)
	{
		std::string temp;
		size_t proNum{ 0 };
		double priceVar{ 0.0f };
		char taxableStatus{ '\n' };

		std::getline(file, temp, '\n');

		if (!temp.empty())
		{
			if (temp.length() >= 13)
			{
				int positionOfFirstSpace = temp.find_first_of(' ');
				int positionOfLastSpace = temp.find_last_of(' ');
				proNum = std::stoi(temp.substr(0, positionOfFirstSpace));
				priceVar = std::stod(temp.substr(positionOfFirstSpace, 6));
				taxableStatus = temp.at(temp.length()-1);
				temp.clear();

				return new TaxableProduct(proNum, priceVar, taxableStatus);
			}
			else
			{
				proNum = std::stoi(temp.substr(0, temp.find_first_of(' ')));
				priceVar = std::stod(temp.substr(temp.find_first_of(' '), temp.length()));
				temp.clear();

				return new Product(proNum, priceVar);
			}

			return new Product(proNum, priceVar);
		}
		else
		{
			throw("end of file met!");
		}
	}
}
