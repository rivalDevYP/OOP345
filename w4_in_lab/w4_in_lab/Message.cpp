// program: Message.cpp
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>

#include "Message.h"

namespace sict
{
	//zero arg. constructor; sets the object to a safe empty state
	Message::Message()
	{
		tweet.clear();
		userName.clear();
		replyName.clear();
	}

	//1 arg constructor; recieves a reference to a string, and parses it into 3 substrings
	Message::Message(const std::string & incomingStr)
	{
		std::string userString;
		std::string tweetString;
		std::string replyString;

		size_t firstSpace = incomingStr.find_first_of(' ');
		size_t secondSpace = incomingStr.find(' ', incomingStr.find_first_of(' ') + 1);
		size_t at = incomingStr.find('@');

		if (incomingStr.find_first_of(' ') != std::string::npos)
		{
			userString = incomingStr.substr(0, firstSpace);

			if (incomingStr.find('@') != std::string::npos) 
			{
				replyString = incomingStr.substr((at + 1), ((secondSpace - firstSpace) - 2));
				tweetString = incomingStr.substr(secondSpace + 1);
			}
			else
			{
				tweetString = incomingStr.substr(firstSpace + 1);
			}

			this->userName = userString;
			this->replyName = replyString;
			this->tweet = tweetString;
		}		
	}

	//empty query; returns true is the object is in a safe empty state
	bool Message::empty() const
	{

		if (tweet[0] == '\0' && (userName[0] == '\0' || replyName[0]=='\0'))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//display query; prints object to output stream
	void Message::display(std::ostream & os) const
	{
		if (!empty())
		{
			os << '>';

			if (!replyName[0] == '\0')
			{
				os << "User  : " << this->userName << "\n" << " Reply : " << this->replyName << "\n" << " Tweet : " << this->tweet << std::endl;
			}
			else
			{
				os << "User  : " << this->userName << "\n" << " Tweet : " << this->tweet << std::endl;
			}			

		}
	}
}
