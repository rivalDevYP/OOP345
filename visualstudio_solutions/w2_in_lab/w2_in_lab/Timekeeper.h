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
		const int max = 10; //maximum number of record objects at 10
		static int numOfRecords; //The number records currently stored
		//std::chrono::steady_clock::time_point start(); //The start time for the current event 
		//std::chrono::steady_clock::time_point end(); //The end time for the current event 
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct record //array of records 
		{
			std::chrono::steady_clock::duration durationTimePiece; //duration of the recorded event 
			char* message; //address of a C-style null-terminated string containing a message in a literal string
			char* timeUnits; //address of a C-style null-terminated string containing the predefined units of time
			//record();
		};	
		record recordObj[10]; //array of records 
		static int objectCreationCount;
	public:
		Timekeeper();
		void start() const;
		void stop() const;
		void recordEvent(const char* incomingStr) const;
		void report(std::ostream& ostrObj) const;
	};
}

#endif //SICT_TIMEKEEPER_H