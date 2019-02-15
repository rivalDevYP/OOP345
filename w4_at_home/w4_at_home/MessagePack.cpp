// program: MessagePack.cpp 
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// date: February 14, 2019

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MessagePack.h"

namespace sict
{
	//default constructor, sets object to safe empty state
	MessagePack::MessagePack()
	{
		objectRef = nullptr;
		numObj = 0;
	}

	//two argument constructor, initializes object to incoming Message array
	MessagePack::MessagePack(Message** incomingArr, size_t numOfElements)
	{
		numObj = 0;
		maxObj = numOfElements;
		if (numOfElements > 0)
		{
			objectRef = new Message[numOfElements];
			for (size_t index = 0; index < numOfElements; index++)
			{
				if (!incomingArr[index]->empty())
				{
					objectRef[index] = *incomingArr[index];		
					numObj++;
				}
			}
		}
	}

	//destructor, deallocates any previously allocated memory
	MessagePack::~MessagePack()
	{
		delete[]this->objectRef;
		this->objectRef = nullptr;
	}

	//copy constructor
	MessagePack::MessagePack(const MessagePack & incomingObj)
	{
		this->objectRef = nullptr;
		*this = incomingObj;
	}

	//copy assignment operator
	MessagePack & MessagePack::operator=(const MessagePack & incomingObj)
	{
		if (this != &incomingObj)
		{
			this->numObj = incomingObj.numObj;
			this->maxObj = incomingObj.maxObj;
			if (this->objectRef != nullptr)
			{
				delete[]this->objectRef;
				this->objectRef = nullptr;
			}
			this->objectRef = new Message[incomingObj.numObj];
			for (size_t index = 0; index < numObj; index++)
			{
				this->objectRef[index] = incomingObj.objectRef[index];
			}
		}
		return *this;
	}

	//move constructor
	MessagePack::MessagePack(MessagePack && incomingObj)
	{
		this->objectRef = nullptr;
		*this = std::move(incomingObj);
	}

	//move assignment operator
	MessagePack& MessagePack::operator=(MessagePack && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->numObj = incomingObj.numObj;
			this->maxObj = incomingObj.maxObj;
			incomingObj.numObj = 0;
			incomingObj.maxObj = 0;
			if (this->objectRef != nullptr)
			{
				delete[]this->objectRef;
				this->objectRef = nullptr;
			}
			this->objectRef = incomingObj.objectRef;
			incomingObj.objectRef = nullptr;
		}
		return *this;
	}

	//display query, prints object to output stream
	void MessagePack::display(std::ostream & os) const
	{
		for (size_t index = 0; index < maxObj; index++)
		{
			if (!objectRef[index].empty())
			{
				this->objectRef[index].display(os);
			}			
		}		
	}

	//size query, returns number of objects currently stored
	size_t MessagePack::size() const
	{
		return numObj;
	}

	//ostream operator overload, calls display query whilst passing reference to ostream object 
	std::ostream & operator<<(std::ostream & os, MessagePack & msgPackObj)
	{
		msgPackObj.display(os);
		return os;
	}
}
