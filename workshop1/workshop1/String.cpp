/*
	program: String.cpp
	programmer: Yathavan, Parameshwaran
	course: OOP345
	date: 2019-01-14
*/

#include <iostream>
#include "String.h"
namespace sict
{
	extern int INITIAL;
	String::String(const char *incomingStr)
	{
		if (incomingStr == nullptr)
		{
			str == '\0';
		}
		else
		{
			strncpy(str, incomingStr, 3);
		}
	}

	void String::display(std::ostream & obj) const
	{
		obj << str;
	}


	std::ostream & operator<<(std::ostream & os, const String & incomingObj)
	{
		int itemNum = INITIAL;
		os << itemNum << ": " << incomingObj << std::endl;
	}
}