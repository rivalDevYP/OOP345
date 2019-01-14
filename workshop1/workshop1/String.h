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
		char *str[3];
	public:
		String(const char* incomingStr);
		void display(std::ostream& obj) const;
	};
	
}

#endif //SICT_PROCESS_H