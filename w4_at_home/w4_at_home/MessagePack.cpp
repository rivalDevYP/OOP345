// program: MessagePack.cpp
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#include <iostream>
#include <string>

#include "Message.h"
#include "MessagePack.h"


namespace sict
{
	//default constructor, sets object to safe empty state
	MessagePack::MessagePack()
	{
		mesobg = nullptr;
		incrementObjectNum();
	}

	//2 arg constructor, recieves reference to array of Message objects and a value defining size of array
	MessagePack::MessagePack(Message & incomingObj, size_t sizeOfArray)
	{
		// [pointer, pointer, pointer]
		if (sizeOfArray > 0)
		{
			mesobg = new Message*[sizeOfArray];
			*mesobg = &incomingObj;
		}
	}

	//destructor
	MessagePack::~MessagePack()
	{
		delete[]*mesobg;
		*mesobg = nullptr;
	}

	//copy constructor
	MessagePack::MessagePack(const MessagePack & incomingObj)
	{
		this->mesobg = nullptr;
		*this = incomingObj;
	}

	//copy assignment operator
	MessagePack & MessagePack::operator=(const MessagePack & incomingObj)
	{
		if (this != &incomingObj)
		{
			numOfObjects = incomingObj.numOfObjects;
			if (*mesobg != nullptr)
			{
				delete[] this->mesobg;
				this->mesobg = nullptr;
			}
			this->mesobg = new Message*[size()];
			this->mesobg = incomingObj.mesobg;			
		}
		return *this;
	}

	//move constructor
	MessagePack::MessagePack(MessagePack && incomingObj)
	{
		this->mesobg = nullptr;
		*this = std::move(incomingObj);
	}

	//move assignment operator
	MessagePack & MessagePack::operator=(MessagePack && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->numOfObjects = incomingObj.numOfObjects;
			incomingObj.numOfObjects = 0;
			if (this->mesobg != nullptr)
			{
				delete[]this->mesobg;
				this->mesobg = nullptr;
			}
			this->mesobg = incomingObj.mesobg;
			incomingObj.mesobg = nullptr;
		}
		return *this;
	}

	//display query, prints object to output stream
	void MessagePack::display(std::ostream & os) const
	{
		for (int index = 0; index < size(); index++)
		{
			mesobg[index]->display(os);
		}		
	}

	//size query, returns number of Message objects stored in current object
	size_t MessagePack::size() const
	{
		return numOfObjects;
	}

	void MessagePack::incrementObjectNum()
	{
		numOfObjects++;
	}

	//output stream operator overload, calls display on incoming MessagePack object passing reference to output stream
	std::ostream& operator<<(std::ostream & os, const MessagePack & incomingObj)
	{
		incomingObj.display(os);
		return os;
	}
}