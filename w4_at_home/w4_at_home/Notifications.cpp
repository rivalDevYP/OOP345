// program: Notifications.cpp 
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// date: February 14, 2019

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Notifications.h"

namespace sict
{
	//default constructor, sets object to safe empty state
	Notifications::Notifications()
	{

	}

	//2 arg constructor, allocates memory for object
	Notifications::Notifications(size_t maxElements) : mesObj(maxElements > 0 ? new const Message*[maxElements] {nullptr} : nullptr)
	{
		maxAddr = maxElements;
	}

	//destructor, deallocates any previously allocated memory
	Notifications::~Notifications()
	{
		delete[]mesObj;
	}

	//copy constructor
	Notifications::Notifications(const Notifications & incomingObj)
	{
		*this = incomingObj;
	}

	//copy assignment operator
	Notifications & Notifications::operator=(const Notifications & incomingObj) 
	{
		if (this != &incomingObj)
		{
			this->numAddr = incomingObj.numAddr;
			delete[]this->mesObj;
			if (maxAddr > 0) 
			{
				mesObj = new const Message*[incomingObj.maxAddr];
				for (unsigned int index = 0; index < incomingObj.maxAddr; index++)
				{
					this->mesObj[index] = incomingObj.mesObj[index];
				}
			}
			else 
			{
				for (unsigned int index = 0; index < incomingObj.maxAddr; index++)
				{
					this->mesObj[index] = nullptr;
				}
			}
			
		}
		return *this;
	}

	//move constructor
	Notifications::Notifications(Notifications && incomingObj)
	{
		*this = std::move(incomingObj);
	}

	//move assignment operator
	Notifications & Notifications::operator=(Notifications && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->maxAddr = incomingObj.maxAddr;
			this->numAddr = incomingObj.numAddr;
			incomingObj.maxAddr = 0;
			incomingObj.numAddr = 0;
			delete[]this->mesObj;
			if (incomingObj.mesObj != nullptr) 
			{	
				this->mesObj = incomingObj.mesObj; 
				incomingObj.mesObj = nullptr; 
			}
		}
		return *this;
	}

	//plus equals operator overload, adds an object to the current object
	Notifications & Notifications::operator+=(const Message & msg)
	{
		if (this->numAddr < this->maxAddr)
			if (!msg.empty())
				mesObj[numAddr++] = &msg;
		return *this;
	}

	//minus equals operator overload, removes an object from current object 
	Notifications & Notifications::operator-=(const Message & msg)
	{
		unsigned int temp = this->numAddr;

		for (unsigned int index = 0; index < temp; index++)  
		{
			if (this->mesObj[index] == &msg)
			{
				this->mesObj[index] = nullptr;
				numAddr--;
				for (unsigned int i = index+1; i < maxAddr; i++)
				{
					this->mesObj[i-1] = this->mesObj[i];
				}
			}
		}
		return *this;
	}

	//display query, prints object to output stream
	void Notifications::display(std::ostream & os) const
	{
		for (unsigned int index = 0; index < this->numAddr; index++)
		{
			this->mesObj[index]->display(os);
		}		
	}

	//size query, returns current number of objects
	size_t Notifications::size() const
	{
		return numAddr;
	}

	//ostream operator overload, calls display query whilst passing reference to ostream object
	std::ostream & operator<<(std::ostream & os, Notifications & incomingObj)
	{
		incomingObj.display(os);
		return os;
	}
}


