/*
	program: w1.cpp
	programmer: Yathavan, Parameshwaran
	course: OOP345
	date: 2019-01-14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "process.h"
#include "String.h"

namespace sict
{
	int INITIAL = 2;
}

int main(int argc, char* argv[])
{
		
	if (argc <= 1) //if num of args equal/less 1
	{
		std::cout << "***Insufficient number of arguments***" << std::endl; //print message
		return 1; //exit with error code
	}
	else //if num of args not less that or equal to 1
	{
		for (int i = 1; i < argc; ++i) //increment while keeping less than num of args
		{
			std::cout << argv[i] << " "; //print arg with a space
		}
		std::cout << std::endl; //print new line
	}
	for (int i = 1; i < argc; ++i) //increment while keeping less than num of args
	{
		sict::process(argv[i]); //calls process func
	}
	return 0;	
}