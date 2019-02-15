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
		mesObj = nullptr;
		maxAddr = 0;
		numAddr = 0;
	}

	//2 arg constructor, allocates memory for object
	Notifications::Notifications(size_t maxElements) : mesObj(maxElements > 0 ? new const Message*[maxElements] {nullptr} : nullptr)
	{
		if (maxElements > 0)
		{
			maxAddr = maxElements;
			numAddr = 0;
		}
	}

	//destructor, deallocates any previously allocated memory
	Notifications::~Notifications()
	{
		for (int index = 0; index < numAddr; index++)
		{
			if (mesObj[index] != nullptr)
			{
				mesObj[index] = nullptr;
			}			
		}
		if (mesObj != nullptr)
		{
			delete[]mesObj;
			mesObj = nullptr;
		}		
	}

	//copy constructor
	Notifications::Notifications(const Notifications & incomingObj)
	{
		this->mesObj = nullptr;
		*this = incomingObj;
	}

	//copy assignment operator
	Notifications & Notifications::operator=(const Notifications & incomingObj)
	{
		if (this != &incomingObj)
		{
			this->maxAddr = incomingObj.maxAddr;
			this->numAddr = incomingObj.numAddr;
			if (this->mesObj != nullptr)
			{
				for (int index = 0; index < this->numAddr; index++)
				{
					delete[]this->mesObj[index];
					this->mesObj[index] = nullptr;
				}
				delete[]this->mesObj;
				this->mesObj = nullptr;
			}
			mesObj = new const Message*[incomingObj.maxAddr];
			for (int index = 0; index < incomingObj.numAddr; index++)
			{
				if (incomingObj.mesObj[index] != nullptr)
				{
					this->mesObj[index] = incomingObj.mesObj[index];
				}				
			}
		}
		return *this;
	}

	//move constructor
	Notifications::Notifications(Notifications && incomingObj)
	{
		this->mesObj = nullptr;
		*this = std::move(incomingObj);
	}

	//move assignment operator
	Notifications & Notifications::operator=(Notifications && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->maxAddr = incomingObj.maxAddr;
			incomingObj.maxAddr = 0;
			this->numAddr = incomingObj.numAddr;
			incomingObj.numAddr = 0;
			if (this->mesObj != nullptr)
			{
				for (int index = 0; index < this->numAddr; index++)
				{
					this->mesObj[index] = nullptr;
				}
				this->mesObj = nullptr;
			}
			if (incomingObj.mesObj != nullptr)
			{
				this->mesObj = incomingObj.mesObj;
			}
			incomingObj.mesObj = nullptr;
		}
		return *this;
	}

	//plus equals operator overload, adds an object to the current object
	Notifications & Notifications::operator+=(const Message & msg)
	{
		if (this->numAddr < this->maxAddr)
		{
			for (int index = 0; index < maxAddr; ++index)
			{
				if (msg.empty())
				{
					//index--;
					break;
				}
				if (mesObj[index]==nullptr)
				{
					this->mesObj[index] = &msg;
					this->numAddr++;
					break;
					//TODO: if message is empty, don't increment
				}
			}
			
		}
		return *this;
	}

	//minus equals operator overload, removes an object from current object 
	Notifications & Notifications::operator-=(const Message & msg)
	{
		int temp = this->numAddr;

		for (int index = 0; index < temp; index++)
		{
			if (this->mesObj[index] == &msg)
			{
				this->mesObj[index] = nullptr;
				numAddr--;
			}
		}
		return *this;
	}

	//display query, prints object to output stream
	void Notifications::display(std::ostream & os) const
	{
		for (int index = 0; index < this->maxAddr; index++)
		{
			if (this->mesObj[index] != nullptr)
			{
				this->mesObj[index]->display(os);
			}
			
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


