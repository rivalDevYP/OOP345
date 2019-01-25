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
		
    }

    Timekeeper::~Timekeeper()
    {
		
    }

    Timekeeper::Timekeeper (Timekeeper& incomingObj)
    {
		*this = incomingObj;
    }

    Timekeeper& Timekeeper::operator=(const Timekeeper& incomingObj)
    {
		if (this != &incomingObj)
		{

		}
        //check for self-assignment
		//shallow copy
		//deallocate
		//reallocate
		//copy over to new
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
}