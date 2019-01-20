/*
program: String.cpp
programmer: Yathavan, Parameshwaran
course: OOP345
date: 2019-01-14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"

extern int INITIAL; //external linkage (reaching out to another member function in another translation unit)

namespace sict
{
	String::String(const char *incomingStr) //recieves an unmodifiable reference to a c-style string
	{
		if (incomingStr != nullptr) //checking existance of incomingStr
		{
			if (incomingStr[0] == '\0') //if the incoming string is empty
			{
				str[0] = '\0'; //initialize to safe empty state
			}
			else //if not empty
			{
				str = new char[strlen(incomingStr)+1];
				//std::strncpy(str, incomingStr, (std::strlen(incomingstr)+1); //copying characters from incomingStr to str
				
			}
		}
		else
		{
			str[0] = '\0';
		}
	}

	//String::~String() //is this destructor required?
	//{
	//	delete[]str; //deallocating previously allocated dynamic memory
	//}

	void String::display(std::ostream & obj) const //display member function
	{
		//static int itemNum = INITIAL;
		//itemNum++;
		//INITIAL++;
		obj << this->str;

	}

	std::ostream & operator<<(std::ostream & os, const String & refToStringObj) //ostream helper
	{
		static int itemNum = INITIAL;
		std::cout << itemNum << ": ";
		itemNum++;
		refToStringObj.display(os);
		return os;
	}
}
