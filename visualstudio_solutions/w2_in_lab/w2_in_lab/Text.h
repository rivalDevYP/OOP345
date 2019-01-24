/*
	program: Text.h
	programmer: yathavan, parameshwaran
	date: January 21, 2019
	description: workshop 2 in lab portion
*/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <iostream>

namespace sict
{
	class Text
	{
		int numOfStringsCurrentlyStored; //class keeps track of the number of strings currently stored 
		std::string* strArray;
	public:
		Text();
		Text(const char* incomingStr);
		Text(const Text& incomingTextObj);
		Text& operator=(const Text& incomingObj);
		~Text();
		size_t size() const;
	};
}
#endif //SICT_TEXT_H