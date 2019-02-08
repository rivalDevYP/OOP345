#include <iostream>
#include <string>
#include <fstream>

#include "Message.h"

namespace sict
{
	Message::Message()
	{
		tweet.clear();
		userName.clear();
		replyName.clear();
	}

	Message::Message(const std::string & str)
	{
		int countLines = 0;
		std::string tempLine;
		std::ifstream tweetFile(str);
		while (tweetFile.is_open())
		{
			while (!tweetFile.eof() && tweetFile.good())
			{
				std::getline(tweetFile, tempLine, '\n');
				parseStringIntoSections()
				countLines++;
			}
			/*if (tweetFile.eof())
			{
				tweetFile.clear();
				tweetFile.seekg(0, tweetFile.beg);
			}*/

		}
	}

	bool Message::empty() const
	{
		return false;
	}

	void Message::display(std::ostream & os) const
	{

	}
	
	std::ostream operator<<(const std::ostream& os, const Message& msgObj)
	{
		return os;
	}
}
