// program: Message.cpp
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
	Message::Message(const std::string & str)
	{
		std::string userString;
		std::string replyString;
		std::string tweetString;

		int positionOfSpace = str.find(' ');

		userString = str.substr(0, positionOfSpace);
		std::string str1 = str.substr(positionOfSpace+1, str.length());
		if (isReply(str))
		{
			int positionOfSpace1 = str1.find(' ');
			replyString = str1.substr(1, positionOfSpace1-1);
			std::string newStr = str1.substr(positionOfSpace1+1, str1.length());
			tweetString = newStr.substr(0, newStr.length());
		}
		else
		{
			tweetString = str1.substr(0, str1.length());
		}

		if (positionOfSpace >= 1)
		{
			this->userName = userString;
			this->replyName = replyString;
			this->tweet = tweetString;
		}
		
	}

	//empty query; returns true is the object is in a safe empty state
	bool Message::empty() const
	{
		if (tweet.empty() && (userName.empty() || replyName.empty()))
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
			os << ">User  : " << this->userName << std::endl;
			if (!replyName[0] == '\0')
			{
				os << " Reply : " << this->replyName << std::endl;
			}
			os << " Tweet : " << this->tweet << std::endl;
		}
	}
	
	//query; returns true if string contains a reply
	bool Message::isReply(std::string incomingStr) const
	{
		char temp;
		for (size_t index = 0; index < incomingStr.length(); index++)
		{
			temp = incomingStr[index];
			if (temp == '@')
			{
				return true;
			}
		}
		return false;
	}
}
