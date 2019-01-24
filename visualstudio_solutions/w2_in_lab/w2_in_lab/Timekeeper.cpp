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

	/*std::chrono::steady_clock::time_point Timekeeper::start()
	{
		return std::chrono::steady_clock::time_point();
	}

	std::chrono::steady_clock::time_point Timekeeper::end()
	{
		return std::chrono::steady_clock::time_point();
	}*/

	void sict::Timekeeper::start() const
	{
		startTime = chrono::steady_clock::now();
	}

	void sict::Timekeeper::stop() const
	{
		endTime = chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* incomingStr) const
	{
		std::strncpy(recordObj[numOfRecords].message, incomingStr, (strlen(incomingStr) + 1));
		recordObj[numOfRecords].durationTimePiece;
		numOfRecords++;
	}

	void Timekeeper::report(std::ostream& ostrObj) const
	{
		
	}

	
	

}
