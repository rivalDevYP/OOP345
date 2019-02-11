// program: MessagePack.cpp
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#include <iostream>
#include <string>

#include "MessagePack.h"

namespace sict
{
	//default constructor, sets object to safe empty state
	MessagePack::MessagePack()
	{
		mesobg = nullptr;
	}

	//2 arg constructor, recieves reference to array of Message objects and a value defining size of array
	MessagePack::MessagePack(Message & incomingObj, size_t sizeOfArray)
	{
		if (sizeOfArray > 0)
		{
			mesobg = new Message*[sizeOfArray];
			for (size_t index = 0; index < sizeOfArray; index++)
			{
				*mesobg[index] = incomingObj[index];
			}
		}
		


	}

	//destructor
	MessagePack::~MessagePack()
	{

	}

	//copy constructor
	MessagePack::MessagePack(const MessagePack & incomingObj)
	{

	}

	//copy assignment operator
	MessagePack & MessagePack::operator=(const MessagePack & incomingObj)
	{

		// TODO: insert return statement here
	}

	//move constructor
	MessagePack::MessagePack(MessagePack && incomingObj)
	{

	}

	//move assignment operator
	MessagePack & MessagePack::operator=(MessagePack && incomingObj)
	{
		// TODO: insert return statement here
	}

	//display query, prints object to output stream
	void MessagePack::display(std::ostream & os) const
	{

	}

	//size query, returns number of Message objects stored in current object
	size_t MessagePack::size() const
	{
		return size_t();
	}

	//output stream operator overload, calls display on incoming MessagePack object passing reference to output stream
	std::ostream operator<<(std::ostream & os, const MessagePack & incomingObj)
	{
		incomingObj.display(os);
		return os;
	}
}