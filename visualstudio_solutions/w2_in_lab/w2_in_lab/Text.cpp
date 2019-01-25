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
			while (!fileptr.eof() && fileptr.good()) 
			{
				std::getline(fileptr, bufferOne, '\n'); 
				bufferOne.clear(); 
				lineCount++; 
			}
			if (fileptr.eof()) 
			{
				fileptr.clear();
				fileptr.seekg(0, fileptr.beg);
			}
			
			strArray = new std::string[lineCount];
			int index = 0;
			while (!fileptr.eof() && fileptr.good()) 
			{
				std::getline(fileptr, strArray[index], '\n'); 
				index++; 
			}
		}
	}

	Text::Text(const Text & incomingTextObj) 
	{
		*this = incomingTextObj; 
	}

	Text & Text::operator=(const Text & incomingObj) 
	{
		if (this != &incomingObj) 
		{
			this->numOfStringsCurrentlyStored = incomingObj.numOfStringsCurrentlyStored; 
			delete[]this->strArray; 
			this->strArray = nullptr; 
			this->strArray = new std::string[incomingObj.strArray->length()]; 
			this->strArray = incomingObj.strArray; 
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
