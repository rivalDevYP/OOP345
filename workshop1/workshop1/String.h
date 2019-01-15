/*
	program: String.h
	programmer: Yathavan, Parameshwaran
	course: OOP345
	date: 2019-01-14
*/

#ifndef SICT_PROCESS_H
#define SICT_PROCESS_H

#include <iostream>
#include <cstring>


namespace sict
{
	const int sizeOfString = 3;
	class String
	{		
		char str[sizeOfString+1];
	public:
		String(const char* incomingStr);
		void display(std::ostream& obj) const;
	};
	std::ostream& operator << (std::ostream& os, const String& refToStringObj);
}

#endif //SICT_PROCESS_H