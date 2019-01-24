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
			while (!fileptr.eof() && fileptr.good()) //while eofbit(error flag for end of file) has not been met yet
			{
				std::getline(fileptr, bufferOne, '\n'); //extract line into bufferOne
				bufferOne.clear(); //clear out the bufferOne (we're just counting lines at this point)
				lineCount++; //increment line count by one
			}
			//at this point, you've read down the file counting the lines
			//you are now at the end of the file, you now gotta climb back up :)
			if (fileptr.eof()) //eof returns true if end of file has been reached
			{
				//first, clear the eof flag
				fileptr.clear();
				//next, go to the beginning of the file
				fileptr.seekg(0, fileptr.beg);
			}
			//you now have the number of lines in the file, now allocate dynamic memory for the string pointer
			strArray = new std::string[lineCount];
			int index = 0;
			while (!fileptr.eof() && fileptr.good()) //while eofbit(error flag for end of file) has not been met yet
			{
				std::getline(fileptr, strArray[index], '\n'); //reading line and storing in array of string objects
				index++; //incrementing the value that holds the current position of string array
			}
		}
	}
	Text::Text(const Text & incomingTextObj)
	{
		*this = incomingTextObj; //copy constructor called when new object created from existing object, make life easier by just calling copy assignment operator on the object that you are recieving while keeping (*this) as the left hand operand ('this' returns the address of the current object) so basically you are saying copy rhs over to lhs, in other words, copy incomingObj over to the current object
	}
	Text & Text::operator=(const Text & incomingObj)
	{
		if (this != &incomingObj) //check for self-assignment (you don't wanna copy over to the same object)
		{
			this->numOfStringsCurrentlyStored = incomingObj.numOfStringsCurrentlyStored; //shallow copy over non resource variables
			delete[]this->strArray; //deallocate any previously allocated memory
			this->strArray = nullptr; //good practice?
			this->strArray = new std::string[incomingObj.strArray->length]; //allocate new memory for the size of the incomingObject's pointer(s)
			this->strArray = incomingObj.strArray; //copy over the resource data from the source object to the freshly allocated pointer of the current object
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
		return this->strArray->length();
	}
}
