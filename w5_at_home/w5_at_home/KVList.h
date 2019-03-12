// program    : KVList.h
// programmer : Yathavan, Parameshwaran
// professor  : Chris, Szalwinski
// date       : February 15, 2019

#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

#include <iostream>

#include "KVPair.h"

namespace sict
{
	template<typename T>
	class KVList
	{
		T* listOfTees{ nullptr };
		size_t currentNumOfTees{ 0 };
		size_t maximumNumOfTees{ 0 };
	public:

		//default constructor
		KVList()
		{			
		}

		//one argument constructor, initializes listOfTees
		KVList(int n) : listOfTees(n > 0 ? new T[n] : throw("incoming number not positive valued!"))
		{
			maximumNumOfTees = n;
		}

		//disabled copy constructor
		KVList(const KVList& incomingObj) = delete;

		//disabled copy assignment operator
		KVList& operator=(const KVList& incomingObj) = delete;

		//move constructor
		KVList(KVList&& incomingObj)
		{
			this->currentNumOfTees = incomingObj.currentNumOfTees;
			this->maximumNumOfTees = incomingObj.maximumNumOfTees;
			incomingObj.currentNumOfTees = 0;
			incomingObj.maximumNumOfTees = 0;
			if (incomingObj.listOfTees != nullptr)
			{
				this->listOfTees = incomingObj.listOfTees;
				incomingObj.listOfTees = nullptr;
			}
		}

		//disabled move assignment operator
		KVList& operator=(KVList&& incomingObj) = delete;

		//destructor
		~KVList()
		{
			delete[]listOfTees;
		}

		//operator overload
		const T& operator[](size_t i) const
		{
			if (i < 0 || i > currentNumOfTees || i > maximumNumOfTees)
			{
				throw("index out of bounds!");
			}
			else
			{
				return listOfTees[i];
			}			
		}
		
		//templated display query
		template<typename F>
		void display(std::ostream& os, F f)
		{
			for (unsigned int index = 0; index < currentNumOfTees; index++)
			{
				listOfTees[index].display(os, f);
			}
		}

		//pushback modifier
		void push_back(const T& t)
		{
			if (currentNumOfTees < maximumNumOfTees)
			{
				listOfTees[currentNumOfTees++] = t;
			}
		}

	};
}

#endif //SICT_KVLIST_H
