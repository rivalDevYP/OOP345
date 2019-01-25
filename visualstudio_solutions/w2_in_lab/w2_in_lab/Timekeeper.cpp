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
	Timekeeper::Timekeeper()
	{
		objectCreationCount++;
	}

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
		std::strncpy(recordObj[numOfRecords].message, incomingStr, (strlen(incomingStr) + 1));
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		recordObj[numOfRecords].durationTimePiece = milliseconds;
		numOfRecords++;
	}

	void Timekeeper::report(std::ostream& ostrObj) const
	{
		for (int index = 0; index < numOfRecords; index++)
		{
			ostrObj << recordObj[index].message;
			recordObj[index].durationTimePiece.count();
			ostrObj << recordObj[index].timeUnits << std::endl;
		}
	}
}
