//	program    : ItemSet.cpp
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#include <iostream>
#include <string>
#include <iomanip>
#include "ItemSet.h"

namespace sict
{
	ItemSet::ItemSet()
	{
		this->myName.clear();
		this->myDescription.clear();
		this->myDelim = helper.getDelimiter();
	}

	ItemSet::ItemSet(std::string & incomingStr)
	{
		size_t positionOfFirstDelim = incomingStr.find_first_of(this->myDelim);
		std::string newStr = incomingStr.substr(positionOfFirstDelim + 1, incomingStr.length());
		size_t positionOfSecondDelim = newStr.find_first_of(this->myDelim);
		std::string newStr1 = newStr.substr(positionOfSecondDelim + 1, newStr.length());
		size_t positionOfThirdDelim = newStr1.find_first_of(this->myDelim);

		this->myName = incomingStr.substr(0, positionOfFirstDelim);
		this->mySerialNum = std::stol(newStr.substr(0, positionOfSecondDelim));
		this->myQuantity = std::stoi(newStr1.substr(0, positionOfThirdDelim));
		this->myDescription = newStr1.substr(positionOfThirdDelim + 1, newStr1.length());

		setFieldWidth(myName.length());
	}

	const std::string & ItemSet::getName() const
	{
		return this->myName;
	}

	const unsigned int ItemSet::getSerialNumber() const
	{
		return this->mySerialNum;
	}

	const unsigned int ItemSet::getQuantity() const
	{
		return this->myQuantity;
	}

	ItemSet & ItemSet::operator--()
	{
		this->myQuantity--;
		this->mySerialNum++;
		return *this;
	}

	void ItemSet::display(std::ostream & os, bool full) const
	{
		if (full)
		{
			os << std::left << std::setw(getFieldWidth()) << this->myName << " " <<
				std::setw(5) << this->mySerialNum << " " <<
				std::setw(3) << this->myQuantity << " " <<
				this->myDescription << std::endl;
		}
		else
		{
			os << std::left << std::setw(getFieldWidth()) << this->myName << " " <<
				std::setw(5) << this->mySerialNum << std::endl;
		}
	}

	void ItemSet::setFieldWidth(int incomingWidth) 
	{ 
		if (incomingWidth > myFieldWidth) 
		{
			myFieldWidth = incomingWidth;
		}
	}

	int ItemSet::getFieldWidth() 
	{ 
		return myFieldWidth; 
	}
}