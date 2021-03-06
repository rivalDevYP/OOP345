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
	class String
	{		
		const int MAX = 3;
		char str[3+1];
	public:
		String(const char* incomingStr);
		//~String(); //is this destructor required?
		void display(std::ostream& obj) const;
	};
	std::ostream& operator << (std::ostream& os, const String& refToStringObj);
}

#endif //SICT_PROCESS_H