/*
	program: Text.h
	programmer: yathavan, parameshwaran
	date: January 21, 2019
	description: workshop 2 in lab portion
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Timekeeper.h"
#include "Text.h"

using namespace std;

namespace sict
{
	Text::Text()
	{
		strArray = nullptr;
	}
	Text::Text(const char * incomingStr)
	{
		std::ifstream fileptr(incomingStr);
		int lineCount = 0;
		std::string bufferOne;
		if (fileptr.is_open())
		{
			while (!fileptr.eofbit) //while eofbit(error flag for end of file) has not been met yet
			{
				std::getline(fileptr,bufferOne,'\n');
				bufferOne.clear();
				lineCount++;
			}

		}
	}
	Text::Text(const Text & incomingTextObj)
	{
		*this = incomingTextObj; //copy constructor called when new object created from existing object, make life easier by just calling copy assignment operator on the object that you are recieving while keeping (*this) as the left hand operand ('this' returns the address of the current object) so basically you are saying copy rhs over to lhs, in other words, copy incomingObj over to the current object
	}
	Text & Text::operator=(const Text & incomingObj)
	{
		if (this != &incomingObj)
		{
			numOfStringsCurrentlyStored = incomingObj.numOfStringsCurrentlyStored;
			delete[]strArray;
			strArray = nullptr;
			strArray = new std::string[incomingObj.strArray->length];
			strArray = incomingObj.strArray;
		}
		return *this;
	}
	Text::~Text()
	{
		delete[]strArray;
		strArray = nullptr;
	}
	size_t Text::size() const
	{
		return size_t();
	}
}
