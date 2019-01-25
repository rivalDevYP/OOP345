/*
program: Timekeeper.cpp
programmer: yathavan, parameshwaran
date: January 21, 2019
description: workshop 2 in lab portion
*/

#include <iostream>
#include <chrono>
#include <string>
#include <cstring>

#include "Timekeeper.h"

using namespace std;

namespace sict
{
    Timekeeper::Timekeeper()
    {
		numOfRecords = 0;
		record->messageString = nullptr;
		record->unitsOfTime = nullptr;
    }

    Timekeeper::~Timekeeper()
    {
		delete[]record->messageString;
		record->messageString = nullptr;
		delete[]record->unitsOfTime;
		record->unitsOfTime = nullptr;
    }

    Timekeeper::Timekeeper (Timekeeper& incomingObj)
    {
		*this = incomingObj;
    }

    Timekeeper& Timekeeper::operator=(const Timekeeper& incomingObj)
    {
		if (this != &incomingObj)
		{
			//shallow copy
			numOfRecords = incomingObj.numOfRecords;
			startTime = incomingObj.startTime;
			endTime = incomingObj.endTime;
			record->durationTime = incomingObj.record->durationTime;
			//deallocating 
			delete[]record->messageString;
			delete[]record->unitsOfTime;
			record->messageString = nullptr;
			record->unitsOfTime = nullptr;
			//allocating
			record->messageString = new char[strlen(incomingObj.record->messageString) + 1];
			record->unitsOfTime = new char[strlen(incomingObj.record->unitsOfTime) + 1];
			//copying over
			strcpy(record->messageString, incomingObj.record->messageString);
			strcpy(record->unitsOfTime, incomingObj.record->unitsOfTime);
		}
		return *this;			
	}

    void Timekeeper::start() 
    {
        startTime = chrono::steady_clock::now();
    }

    void Timekeeper::stop()
    {
        endTime = chrono::steady_clock::now();
    }

    void Timekeeper::recordEvent(const char* incomingStr)
    {

    }

	void Timekeeper::report(std::ostream& incoming_ostream_object) const
	{

	}
}


