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
		newObjectCreated();
    }

	void Timekeeper::newObjectCreated()
	{
		numberOfObjectsCreated++;
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
		record->durationTime=chrono::duration_cast
    }

	void Timekeeper::report(std::ostream& incoming_ostream_object) const
	{

	}
}


