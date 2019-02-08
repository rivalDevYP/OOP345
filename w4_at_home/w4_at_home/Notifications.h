// program: Notifications.h
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// project: workshop 4

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include "Message.h"

namespace sict
{
	class Notifications
	{

	public:
		Notifications();
		Notifications(const int maxNum);
		~Notifications();
		Notifications(const Notifications& incomingObj);
		Notifications& operator=(const Notifications& incomingObj);
		Notifications(const Notifications&& incomingObj);
		Notifications&& operator=(const Notifications&& incomingObj);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(const std::ostream& os) const;
		size_t size() const;		
	};
	std::ostream& operator<<(std::ostream& os, Notifications& incomingObj);
}

#endif //SICT_NOTIFICATIONS_H
