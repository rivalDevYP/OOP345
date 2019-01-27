/*
program: Text.cpp
programmer: yathavan, parameshwaran
date: January 21, 2019
description: workshop 2 in lab portion
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "Text.h"

using namespace std;

namespace sict
{
	//constructor; called when Text object created
	Text::Text()
	{
		numOfStringsCurrentlyStored = 0;
		strArray = nullptr;
	}

	//1-arg constructor; recieves name of file; reads file and stores each line in a string
	Text::Text(const char * incomingStr)
	{
		ifstream fileptr(incomingStr);
		int lineCount = 0;
		string bufferOne;
		if (fileptr.is_open())
		{
			while (!fileptr.eof() && fileptr.good()) 
			{
				getline(fileptr, bufferOne, '\n'); 
				bufferOne.clear(); 
				lineCount++; 
			}
			numOfStringsCurrentlyStored = (lineCount-1);
			if (fileptr.eof()) 
			{
				fileptr.clear();
				fileptr.seekg(0, fileptr.beg);
			}

			strArray = new string[lineCount];
			int index = 0;
			while (!fileptr.eof() && fileptr.good()) 
			{
				getline(fileptr, strArray[index], '\n'); 
				index++; 
			}
		}
	}

	//copy constructor
	Text::Text(const Text & incomingTextObj) 
	{
		strArray = nullptr;
		*this = incomingTextObj; 		
	}

	//move constructor
	Text::Text(Text && incomingObj)
	{
		this->strArray = nullptr;
		*this = move(incomingObj);
	}

	//move assignment operator
	Text & Text::operator=(Text && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->numOfStringsCurrentlyStored = incomingObj.numOfStringsCurrentlyStored;
			incomingObj.numOfStringsCurrentlyStored = 0;
			if (this->strArray != nullptr)
			{
				delete[]this->strArray;
				strArray = nullptr;
			}
			this->strArray = new string[incomingObj.strArray->length()];
			for (long unsigned int index = 0; index < incomingObj.strArray->length(); index++)
			{
				this->strArray[index] = incomingObj.strArray[index];
			}
			delete[]incomingObj.strArray;
			incomingObj.strArray = nullptr;
		}
		return *this;
	}

	//copy assignment operator
	Text & Text::operator=(const Text & incomingObj) 
	{
		if (this != &incomingObj) 
		{
			this->numOfStringsCurrentlyStored = incomingObj.numOfStringsCurrentlyStored; 
			delete[]this->strArray;
			this->strArray = nullptr;
			this->strArray = new string[incomingObj.strArray->length()]; 
			for (long unsigned int index = 0; index < incomingObj.strArray->length(); index++)
			{
				this->strArray[index] = incomingObj.strArray[index];
			}
		}
		return *this;
	}

	//destructor; called when object reaches end of scope 
	Text::~Text()
	{	
		delete[]this->strArray;
		this->strArray = nullptr;
	}

	//returns number of records stored in current object
	size_t Text::size() const
	{
		return (this->numOfStringsCurrentlyStored);
	}
}


