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
    const int maxNumOfRecords = 10;
    class Timekeeper
    {
        int numOfRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

        /* typedef */ struct 
        {
            char* messageString;
            char* unitsOfTime;
            std::chrono::steady_clock::duration durationTime;
        } record[maxNumOfRecords];

    public:
        Timekeeper();
        ~Timekeeper();
        Timekeeper (Timekeeper& incomingObj);
        Timekeeper& operator=(const Timekeeper& incomingObj);
        void start();
        void stop();
        void recordEvent(const char* incomingStr);
    };
}

#endif //SICT_TIMEKEEPER_H