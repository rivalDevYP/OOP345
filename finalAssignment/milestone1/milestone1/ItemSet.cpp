//	program    : ItemSet.cpp
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#include <iostream>
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
		size_t beginningOfStr = 0;
		size_t positionOfFirstDelim = incomingStr.find_first_of(this->myDelim);
		std::string newStr = incomingStr.substr(positionOfFirstDelim + 1, incomingStr.length());
		size_t positionOfSecondDelim = newStr.find_first_of(this->myDelim);
		std::string newStr1 = newStr.substr(positionOfSecondDelim + 1, newStr.length());
		size_t positionOfThirdDelim = newStr1.find_first_of(this->myDelim);


		//call extract token from utilities using the positions

		this->myName = helper.extractToken(incomingStr, beginningOfStr);
		this->mySerialNum = std::stol(helper.extractToken(newStr,beginningOfStr));
		this->myQuantity = std::stoi(helper.extractToken(newStr1, beginningOfStr));
		//this->myDescription = helper.extractToken(newStr1, positionOfThirdDelim);

		
	}

	ItemSet::ItemSet(ItemSet && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->myName = incomingObj.myName;
			this->myDescription = incomingObj.myDescription;
			this->mySerialNum = incomingObj.mySerialNum;
			this->myQuantity = incomingObj.myQuantity;
			this->myDelim = incomingObj.myDelim;

			incomingObj.myName.clear();
			incomingObj.myDescription.clear();
			incomingObj.mySerialNum = 0;
			incomingObj.myQuantity = 0;
			incomingObj.myDelim = '\0';
		}
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
			os << std::left << std::setw(helper.getFieldWidth()) << this->myName << " " <<
				std::setw(5) << this->mySerialNum << " " <<
				std::setw(3) << this->myQuantity << " " <<
				this->myDescription << std::endl;
		}
		else
		{
			os << std::left << std::setw(helper.getFieldWidth()) << this->myName << " " <<
				std::setw(5) << this->mySerialNum << std::endl;
		}
	}
}