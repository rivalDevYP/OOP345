/*
	program: Text.h
	programmer: yathavan, parameshwaran
	date: January 21, 2019
	description: workshop 2 in lab portion
*/

#include <iostream>
#include <string>
#include <chrono>
#include "Timekeeper.h"
#include "Text.h"

using namespace std;

namespace sict
{
	Text::Text()
	{
		strArray = nullptr;
	}
	Text::Text(const char * incomingStr)
	{
	}
	Text::Text(const Text & incomingTextObj)
	{
	}
	Text & Text::operator=(const Text & incomingObj)
	{
		// TODO: insert return statement here
	}
	Text::~Text()
	{
	}
	size_t Text::size() const
	{
		return size_t();
	}
}
