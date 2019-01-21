/*
	program: Timekeeper.h
	programmer: yathavan, parameshwaran
	date: January 21, 2019
	description: workshop 2 in lab portion
*/

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>

namespace sict
{
	class Timekeeper
	{
		const int max = 10;
		char* message;
		char* timeUnits;
		std::chrono::steady_clock::time_point startTimePiece;
		std::chrono::steady_clock::time_point endTimePiece;
		std::chrono::steady_clock::time_point durationTimePiece;
		int numOfRecords;
		static int objectCreationCount;

	public:
		Timekeeper();
		void start() const;
		void stop() const;
		void recordEvent() const;
		void report() const;
	};
}

#endif //SICT_TIMEKEEPER_H