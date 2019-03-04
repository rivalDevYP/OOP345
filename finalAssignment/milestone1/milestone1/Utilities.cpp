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

	}

	//copy constructor
	Utilities::Utilities(const Utilities & incomingObj)
	{

	}

	//copy assignment operator
	Utilities & Utilities::operator=(const Utilities & incomingObj)
	{
		// TODO: insert return statement here
	}

	//move constructor
	Utilities::Utilities(Utilities && incomingObj)
	{

	}

	//move assignment operator
	Utilities & Utilities::operator=(Utilities && incomingObj)
	{
		// TODO: insert return statement here
	}

	//extracts tokens based on incoming params
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos)
	{
		return std::string();
	}

	//returns local delimiter character
	const char Utilities::getDelimiter() const
	{
		return 0;
	}

	//returns field width for current object
	size_t Utilities::getFieldWidth() const
	{
		return size_t();
	}

	//sets delimiter character based on incoming param
	void Utilities::setDelimiter(const char d)
	{

	}

	//sets field width for current object based on incoming param
	void Utilities::setFieldWidth(size_t t)
	{

	}
}