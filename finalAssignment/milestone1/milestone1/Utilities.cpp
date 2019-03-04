//	program    : Utilities.cpp
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#include <iostream>
#include "Utilities.h"

namespace sict
{
	//default constructor
	Utilities::Utilities()
	{

	}

	//destructor
	Utilities::~Utilities()
	{
		delete[]this->myToken;
		this->myToken = nullptr;
	}

	//copy constructor
	Utilities::Utilities(const Utilities & incomingObj)
	{
		*this = incomingObj;
	}

	//copy assignment operator
	Utilities & Utilities::operator=(const Utilities & incomingObj)
	{
		if (this != &incomingObj)
		{
			this->myDelim = incomingObj.myDelim;
			this->myFieldWidth = incomingObj.myFieldWidth;
			this->numOfTokens = incomingObj.numOfTokens;

			delete[]myToken;
			if (incomingObj.myToken != nullptr)
			{
				for (int index = 0; index < incomingObj.numOfTokens; index++)
				{
					this->myToken[index] = incomingObj.myToken[index];
				}
			}
			else
			{
				myToken = nullptr;
			}
		}
	}


	//move constructor
	Utilities::Utilities(Utilities && incomingObj)
	{
		*this = std::move(incomingObj);
	}

	//move assignment operator
	Utilities & Utilities::operator=(Utilities && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->myDelim = incomingObj.myDelim;
			this->myFieldWidth = incomingObj.myFieldWidth;
			this->numOfTokens = incomingObj.numOfTokens;

			incomingObj.myDelim = '\0';
			incomingObj.myFieldWidth = 0;
			incomingObj.numOfTokens = 0;

			delete[]this->myToken;
			if (incomingObj.myToken != nullptr)
			{
				this->myToken = incomingObj.myToken;
				incomingObj.myToken = nullptr;
			}
			else
			{
				this->myToken = nullptr;
			}
		}
	}

	//extracts tokens based on incoming params
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos)
	{
		//increment numOfTokens each time a new token is extracted and added to the string
		return std::string();
	}

	//returns local delimiter character
	const char Utilities::getDelimiter() const
	{
		return this->myDelim;
	}

	//returns field width for current object
	size_t Utilities::getFieldWidth() const
	{
		return this->myFieldWidth;
	}

	//sets delimiter character based on incoming param
	void Utilities::setDelimiter(const char d)
	{
		this->myDelim = d;
	}

	//sets field width for current object based on incoming param
	void Utilities::setFieldWidth(size_t t)
	{
		this->myFieldWidth = t;
	}
}