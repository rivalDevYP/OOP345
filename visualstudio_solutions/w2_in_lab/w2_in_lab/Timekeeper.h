/*
program: Timekeeper.h
programmer: yathavan, parameshwaran
date: January 21, 2019
description: workshop 2 in lab portion
*/

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <chrono>

namespace sict
{
	class Timekeeper
	{
		const int max = 10; 
		static int numOfRecords; 
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct record 
		{
			std::chrono::steady_clock::duration durationTimePiece; 
			char* message; 
			char* timeUnits; 
		};	
		record recordObj[10]; 
		static int objectCreationCount;
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* incomingStr);
		void report(std::ostream& ostrObj) const;
	};
}

#endif //SICT_TIMEKEEPER_H
