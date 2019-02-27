//	program    : ItemSet.cpp
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#include <iostream>
#include "ItemSet.h"

namespace sict
{
	//default constructor
	ItemSet::ItemSet()
	{

	}

	//destructor
	ItemSet::~ItemSet()
	{

	}

	//copy constructor
	ItemSet::ItemSet(const ItemSet & incomingObj)
	{

	}

	//copy assignment operator
	ItemSet & ItemSet::operator=(const ItemSet & incomingObj)
	{
		// TODO: insert return statement here
	}

	//move constructor
	ItemSet::ItemSet(ItemSet && incomingObj)
	{

	}

	//move assignment operator
	ItemSet & ItemSet::operator=(ItemSet && incomingObj)
	{
		// TODO: insert return statement here
	}

	//1 arg. constructor
	ItemSet::ItemSet(std::string & incomingStr)
	{

	}

	//query, returns name
	const std::string & ItemSet::getName() const
	{
		// TODO: insert return statement here
	}

	//query, returns serial number
	const unsigned int ItemSet::getSerialNumber() const
	{
		return 0;
	}

	//query, returns quantity
	const unsigned int ItemSet::getQuantity() const
	{
		return 0;
	}

	//decrement operator overload, reduces stock, increases serial number
	ItemSet & ItemSet::operator--()
	{
		// TODO: insert return statement here
	}
}