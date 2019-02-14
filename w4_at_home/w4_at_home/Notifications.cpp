#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Notifications.h"


namespace sict
{
	Notifications::Notifications()
	{
		mesObj = nullptr;
		maxAddr = 0;
		numAddr = 0;
	}

	Notifications::Notifications(size_t maxElements) : (maxElements > 0 ? mesObj = new const Message*[maxElements] : nullptr)
	{
		if (maxElements > 0)
		{
			maxAddr = maxElements;
		}
	}

	Notifications::~Notifications()
	{
		for (int index = 0; index < numAddr; index++)
		{
			delete[]mesObj[index];
			mesObj[index] = nullptr;
		}
		delete[]mesObj;
		mesObj = nullptr;
	}

	Notifications::Notifications(const Notifications & incomingObj)
	{
		*this = incomingObj;
	}

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
				this->mesObj[index] = incomingObj.mesObj[index];
			}
		}
		return *this;
	}

	Notifications::Notifications(const Notifications && incomingObj)
	{
		*this = std::move(incomingObj);
	}

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
					delete[]this->mesObj[index];
					this->mesObj[index] = nullptr;
				}
				delete[]this->mesObj;
				this->mesObj = nullptr;
			}
			for (int index = 0; index < this->numAddr; index++)
			{
				this->mesObj[index] = incomingObj.mesObj[index];
			}
			
		}
	}

	Notifications & Notifications::operator+=(const Message & msg)
	{
		if (this->numAddr < this->maxAddr)
		{
			this->mesObj[numAddr + 1] = &msg;
		}
		return *this;
	}

	Notifications & Notifications::operator-=(const Message & msg)
	{
		for (int index = 0; index < this->numAddr; index++)
		{
			if (this->mesObj[index] = &msg)
			{
				this->mesObj[index] = nullptr;
				for (int i = 0; i < (maxAddr - numAddr); i++)
				{
					this->mesObj[index+i] = this->mesObj[index - 1];
				}
			}
		}
		return *this;
	}

	void Notifications::display(std::ostream & os) const
	{
		for (int index = 0; index < numAddr; index++)
		{
			this->mesObj[index]->display(os);
		}		
	}

	size_t Notifications::size() const
	{
		return numAddr;
	}

	std::ostream & operator<<(std::ostream & os, Notifications & incomingObj)
	{
		incomingObj.display(os);
	}
}


