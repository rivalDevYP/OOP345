// program: Message.h
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>
#include <string>

namespace sict
{
	class Message
	{
		std::string tweet;
		std::string userName;
		std::string replyName;
		bool isReply(std::string) const;

	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};	
}

#endif //SICT_MESSAGE_H
