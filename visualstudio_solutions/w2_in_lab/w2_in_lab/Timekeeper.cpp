/*
	program: Timekeeper.cpp
	programmer: yathavan, parameshwaran
	date: January 21, 2019
	description: workshop 2 in lab portion
*/

#include <iostream>
#include <string>
#include <chrono>
#include "Timekeeper.h"
#include "Text.h"

using namespace std;

namespace sict
{
	/*Timekeeper::record::record()
	{
		this->message = nullptr;
		this->timeUnits = nullptr;
	}*/

	Timekeeper::Timekeeper()
	{
		objectCreationCount++;
	}

	void Timekeeper::start() const
	{
		
	}

	void Timekeeper::stop() const
	{

	}

	void Timekeeper::recordEvent(const char* incomingStr) const
	{
		std::strncpy(recordObj[numOfRecords].message, incomingStr, (strlen(incomingStr) + 1));
		numOfRecords++;
	}

	void Timekeeper::report(std::ostream& ostrObj) const
	{
		
	}

	
	

}
