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

	Notifications::Notifications(size_t maxElements) : mesObj(maxElements > 0 ? new const Message*[maxElements] {nullptr} : nullptr)
	{
		if (maxElements > 0)
		{
			maxAddr = maxElements;
			numAddr = 0;
		}
	}

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

	Notifications::Notifications(const Notifications & incomingObj)
	{
		this->mesObj = nullptr;
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
				if (incomingObj.mesObj[index] != nullptr)
				{
					this->mesObj[index] = incomingObj.mesObj[index];
				}				
			}
		}
		return *this;
	}

	Notifications::Notifications(Notifications && incomingObj)
	{
		this->mesObj = nullptr;
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
					this->mesObj[index] = nullptr;
				}
				this->mesObj = nullptr;
			}
			/*for (int index = 0; index < this->numAddr; index++)
			{
				if (incomingObj.mesObj[index] != nullptr)
				{
					this->mesObj[index] = incomingObj.mesObj[index];
				}				
			}*/	
			if (incomingObj.mesObj != nullptr)
			{
				this->mesObj = incomingObj.mesObj;
			}
			incomingObj.mesObj = nullptr;
		}
		return *this;
	}

	Notifications & Notifications::operator+=(const Message & msg)
	{
		if (this->numAddr < this->maxAddr)
		{
			for (int index = 0; index < maxAddr; ++index)
			{
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

	Notifications & Notifications::operator-=(const Message & msg)
	{
		int temp = this->numAddr;

		for (int index = 0; index < temp; index++)
		{
			if (this->mesObj[index] == &msg)
			{
				this->mesObj[index] = nullptr;
				numAddr--;
				/*for (int i = 0; i < (maxAddr - numAddr); i++)
				{
					this->mesObj[index+i] = this->mesObj[index - 1];
				}*/
			}
		}
		return *this;
	}

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

	size_t Notifications::size() const
	{
		return numAddr;
	}

	std::ostream & operator<<(std::ostream & os, Notifications & incomingObj)
	{
		incomingObj.display(os);
		return os;
	}
}


