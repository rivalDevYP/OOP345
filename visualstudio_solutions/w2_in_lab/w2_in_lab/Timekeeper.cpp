/*
program: Timekeeper.cpp
programmer: yathavan, parameshwaran
date: January 21, 2019
description: workshop 2 in lab portion
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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

	void sict::Timekeeper::start()
	{
		startTime = std::chrono::steady_clock::now();
	}

	void sict::Timekeeper::stop()
	{
		endTime = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* incomingStr) 
	{
		/*
		   a modifier that receives the address of a C-style null terminated string that holds the description of the event � this function copies the address of the description into the next time record, calculates the duration of the event and copies it into the next time record, copies the address of the literal string containing a description of the units of time into the next time records, and increments the instance variable that identifies the next empty time record.

		   - recieves c-style string that contains description of the event (incomingStr)
		   - copy address of incomingStr into next-time record
		   - calculate duration of event (hint: subtract timepoint objects) and insert that into the next-time record as well
		   - and then increment the instance variable that identifies the next-time record
		   */

		std::strncpy(recordObj[numOfRecords].message, incomingStr, (strlen(incomingStr) + 1));
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		recordObj[numOfRecords].durationTimePiece = milliseconds;

		numOfRecords++;
	}

	void Timekeeper::report(std::ostream& ostrObj) const
	{
		/*
		   a query that receives a reference to an std::ostream object, inserts the title �Execution Times:� into the object and inserts each of the time records stored in the Timekeeper object 
		   */
		for (int index = 0; index < numOfRecords; index++)
		{
			ostrObj << recordObj[index].message;
			recordObj[index].durationTimePiece.count();
			ostrObj << recordObj[index].timeUnits << std::endl;
		}
	}
}
