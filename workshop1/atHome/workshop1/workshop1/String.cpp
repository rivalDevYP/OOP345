/*
program: String.cpp
programmer: Yathavan, Parameshwaran
course: OOP345
date: 2019-01-14
purpose: "to take user input, and print the first 3 characters of each word user inputs"
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"

extern int INITIAL; //external linkage (reaching out to another member function in another translation unit)

namespace sict
{
	String::String()
	{
		str[0] = '\0';
	}

	String::String(const char *incomingStr) //recieves an unmodifiable reference to a c-style string
	{
		if (incomingStr[0] == '\0') //if the incoming string is empty
		{
			str[0] = '\0'; //initialize to safe empty state
		}
		else //if not empty
		{
			str = new char[strlen(incomingStr) + 1]; //allocating dynamic memory to the size of incomingStr length plus one for nullbyte
			//std::strncpy(str, incomingStr, (strlen(incomingStr)+1));//copying first 3 characters from incomingStr to str
			std::strncpy(str, incomingStr, (strlen(incomingStr) + 1));
		}
	}

	//String::~String() //is this destructor required?
	//{
	//	delete[]str; //deallocating previously allocated dynamic memory
	//}

	void String::display(std::ostream & obj) const //display member function
	{
		obj << this->str;
	}

	std::ostream & operator<<(std::ostream & os, const String & refToStringObj) //ostream helper
	{
		static int itemNum = INITIAL;
		refToStringObj.display(os);
		itemNum++;
		return os;
	}
}
