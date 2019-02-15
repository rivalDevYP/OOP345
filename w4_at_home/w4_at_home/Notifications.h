// program: Notifications.h
// programmer: Yathavan, Parameshwaran
// professor: Chris, Szalwinski
// date: February 14, 2019

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>

#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** mesObj;
		int maxAddr; 
		int numAddr; 
	public:
		Notifications();
		Notifications(size_t maxElements);
		~Notifications();
		Notifications(const Notifications& incomingObj);
		Notifications& operator=(const Notifications& incomingObj);
		Notifications(Notifications&& incomingObj);
		Notifications& operator=(Notifications&& incomingObj);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, Notifications& incomingObj);
}

#endif //SICT_NOTIFICATIONS_H
