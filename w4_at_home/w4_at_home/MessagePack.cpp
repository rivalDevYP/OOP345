#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MessagePack.h"

namespace sict
{
	MessagePack::MessagePack()
	{
		objectRef = nullptr;
		numObj = 0;
	}

	MessagePack::MessagePack(Message** incomingArr, size_t numOfElements)
	{
		if (numOfElements > 0)
		{
			objectRef = new Message[numOfElements];
			for (int index = 0; index < numOfElements; index++)
			{
				if (!incomingArr[index]->empty())
				{
					objectRef[index] = *incomingArr[index];
					numObj++;
				}
			}
		}
	}

	MessagePack::~MessagePack()
	{
		delete[]this->objectRef;
		this->objectRef = nullptr;
	}

	MessagePack::MessagePack(const MessagePack & incomingObj)
	{
		this->objectRef = nullptr;
		*this = incomingObj;
	}

	MessagePack & MessagePack::operator=(const MessagePack & incomingObj)
	{
		if (this != &incomingObj)
		{
			this->numObj = incomingObj.numObj;
			if (this->objectRef != nullptr)
			{
				delete[]this->objectRef;
				this->objectRef = nullptr;
			}
			this->objectRef = new Message[incomingObj.numObj];
			for (int index = 0; index < numObj; index++)
			{
				this->objectRef[index] = incomingObj.objectRef[index];
			}
		}
		return *this;
	}

	MessagePack::MessagePack(const MessagePack && incomingObj)
	{
		*this = std::move(incomingObj);
	}

	MessagePack& MessagePack::operator=(MessagePack && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->numObj = incomingObj.numObj;
			incomingObj.numObj = 0;
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


	void MessagePack::display(std::ostream & os) const
	{
		if (!this->objectRef->empty())
		{
			this->objectRef->display(os);
		}
		
	}

	size_t MessagePack::size() const
	{
		return numObj;
	}

	std::ostream & operator<<(std::ostream & os, MessagePack & msgPackObj)
	{
		msgPackObj.display(os);
		return os;
	}
}
