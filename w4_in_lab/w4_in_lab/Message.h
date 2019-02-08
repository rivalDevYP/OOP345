#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>
#include <fstream>

namespace sict
{
	class Message
	{
		std::string tweet;
		std::string userName;
		std::string replyName;

	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
	std::ostream operator<<(const std::ostream& os, const Message& msgObj);
}

#endif //SICT_MESSAGE_H