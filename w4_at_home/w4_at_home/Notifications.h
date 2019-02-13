#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** mesObj;
		int maxAddr; //maximum number of addresses that can be stored in the aggregation
		int numAddr; //number of addresses currently stored in the aggregation
	public:
		Notifications();
		Notifications(size_t maxElements) : mesObj() {};
		~Notifications();
		Notifications(const Notifications& incomingObj);
		Notifications& operator=(const Notifications& incomingObj);
		Notifications(const Notifications&& incomingObj);
		Notifications& operator=(Notifications&& incomingObj);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, Notifications& incomingObj);
}

#endif //SICT_NOTIFICATIONS_H