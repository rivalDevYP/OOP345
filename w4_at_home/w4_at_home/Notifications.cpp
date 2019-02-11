// program: Notifications.cpp
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#include <iostream>
#include "Notifications.h"

namespace sict
{
	//default constructor, sets object to safe empty state
	Notifications::Notifications() : MesObj(nullptr)
	{
		maxNum = 0;
		currentNum = 0;
	}

	//1 arg constructor, recieves maximum number of elements in aggregations
	Notifications::Notifications(const int maxNumber) : (maxNum > 0 ? MesObj = new const Message*[maxNumber] : nullptr)
	{
		if (maxNumber >= 1)
		{

		}
	}

	//destructor
	Notifications::~Notifications()
	{

	}

	//copy constructor
	Notifications::Notifications(const Notifications & incomingObj)
	{

	}

	//copy assignment operator
	Notifications & Notifications::operator=(const Notifications & incomingObj)
	{
		// TODO: insert return statement here
	}

	//move constructor
	Notifications::Notifications(const Notifications && incomingObj)
	{

	}

	//move assignment operator
	Notifications && Notifications::operator=(const Notifications && incomingObj)
	{
		// TODO: insert return statement here
	}

	//plus_equal operator overload
	Notifications & Notifications::operator+=(const Message & msg)
	{
		// TODO: insert return statement here
	}

	//minus_equal operator overload
	Notifications & Notifications::operator-=(const Message & msg)
	{
		// TODO: insert return statement here
	}

	//display query, prints object to output
	void Notifications::display(const std::ostream & os) const
	{

	}

	//size query, returns number of Message objects pointed to by current object
	size_t Notifications::size() const
	{
		return size_t();
	}

	//output stream overload, calls display query on incoming object passing reference to output stream
	std::ostream & operator<<(std::ostream & os, Notifications & incomingObj)
	{
		// TODO: insert return statement here
	}
}