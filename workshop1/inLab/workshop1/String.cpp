/*
	program: String.cpp
	programmer: Yathavan, Parameshwaran
	course: OOP345
	date: 2019-01-14
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.h"

extern int INITIAL; //external linkage (reaching out to another member function in another translation unit)

namespace sict
{
	String::String(const char *incomingStr) //recieves an unmodifiable reference to a c-style string
	{
		if (incomingStr == nullptr) //if the incoming string is empty
		{
			str[0] = '\0'; //initialize to safe empty state
		}
		else //if not empty
		{
			//str = new char[3]; //allocating dynamic memory
			strncpy(str, incomingStr, 3); //copying first 3 characters from incomingStr to str
			str[3] = '\0'; //setting the last block of memory of str as nullbyte
		}
	}

	//String::~String() //is this destructor required?
	//{
	//	delete[]str; //deallocating previously allocated dynamic memory
	//}

	void String::display(std::ostream & obj) const //display member function
	{
		static int itemNum = INITIAL;
		itemNum++;
		obj << itemNum << ": " << this->str;
		
	}

	std::ostream & operator<<(std::ostream & os, const String & refToStringObj) //ostream helper
	{
		refToStringObj.display(os);
		return os;
	}
}