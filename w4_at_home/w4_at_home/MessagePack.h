// program: MessagePack.h 
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// date: February 14, 2019

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <iostream>
#include "Message.h"

namespace sict
{
	class MessagePack
	{
		Message* objectRef;
		size_t numObj;
		size_t maxObj;
	public:
		MessagePack();
		MessagePack(Message** incomingArr, size_t numOfElements);
		~MessagePack();
		MessagePack(const MessagePack& incomingObj);
		MessagePack& operator=(const MessagePack& incomingObj);
		MessagePack(MessagePack&& incomingObj);
		MessagePack& operator=(MessagePack&& incomingObj);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, MessagePack& msgPackObj);
}

#endif //SICT_MESSAGEPACK_H