/*
	program: String.cpp
	programmer: Yathavan, Parameshwaran
	course: OOP345
	date: 2019-01-14
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.h"
namespace sict
{
	extern int INITIAL; //external linkage (reaching out to another member function in another translation unit)

	String::String(const char *incomingStr) //recieves an unmodifiable reference to a c-style string
	{
		if (incomingStr == nullptr) //if the incoming string is empty
		{
			str[0] = '\0'; //initialize to safe empty state
		}
		else //if not empty
		{
			strncpy(str, incomingStr, sizeOfString); //copy over the string to our local var
		}
	}

	void String::display(std::ostream & obj) const //display member function
	{
		obj << str; //calls ostream helper
	}


	std::ostream & operator<<(std::ostream & os, const String & incomingObj) //ostream helper
	{
		int itemNum = INITIAL;
		os << itemNum << ": " << incomingObj << std::endl; // TODO there is an error over here
		return os;
	}
}