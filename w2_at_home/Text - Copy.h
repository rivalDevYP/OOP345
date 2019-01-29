/*
program: Text.h
programmer: yathavan, parameshwaran
date: January 28, 2019
description: workshop 2 at home portion
*/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <iostream>

namespace sict
{
	class Text
	{
		int numOfStringsCurrentlyStored; 
		std::string* strArray;
	public:
		Text();
		Text(const char* incomingStr);
		Text(const Text& incomingTextObj);
		Text& operator=(const Text& incomingObj);
		Text(Text&& incomingObj);
		Text& operator=(Text&& incomingObj);
		~Text();
		size_t size() const;
	};
}

#endif //SICT_TEXT_H
