// program: MessagePack.h
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <iostream>

#include "Message.h"

namespace sict
{
	class MessagePack
	{
		Message **mesobg;

	public:
		MessagePack();
		MessagePack(Message& incomingObj, size_t sizeOfArray);
		~MessagePack();
		MessagePack(const MessagePack& incomingObj);
		MessagePack& operator=(const MessagePack& incomingObj);
		MessagePack(MessagePack&& incomingObj);
		MessagePack& operator=(MessagePack&& incomingObj);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream operator<<(std::ostream& os, const MessagePack& incomingObj);
}

#endif //SICT_MESSAGEPACK_H