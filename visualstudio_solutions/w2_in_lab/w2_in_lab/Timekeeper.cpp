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
		static int numberOfObjectsCreated = 0;
		numOfRecords = 0;
		record->messageString = nullptr;
		record->unitsOfTime = nullptr;
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
		int counter = 0;
		record[counter].messageString = incomingStr;
		auto returnTime = record->durationTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
		record[counter].durationTime = endTime - startTime;
		counter++;
    }

	void Timekeeper::report(std::ostream& incoming_ostream_object) const
	{
		incoming_ostream_object << "Execution Times:" << std::endl;
		for (int index = 0; index < maxNumOfRecords; index++)
		{
			incoming_ostream_object << record[index].messageString 
				<< "  " 
				<< record[index].durationTime.count() 
				<< " " 
				<< record[index].unitsOfTime 
				<< std::endl;
		}
	}
}


