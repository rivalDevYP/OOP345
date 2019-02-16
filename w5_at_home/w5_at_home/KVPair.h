// program    : KVPair.h
// programmer : Yathavan, Parameshwaran
// professor  : Chris, Szalwinski
// date       : February 15, 2019

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

#include <iostream>

#include "Taxable.h"
#include "KVPair.h"

namespace sict
{
	template <typename K, typename V>
	class KVPair
	{
		K myKey;
		V myValue;
		
	public:

		//default constructor
		KVPair()
		{
		}

		//two argument constructor, initializes object
		KVPair(const K& incomingKey, const V& incomingValue)
		{
			myKey = incomingKey;
			myValue = incomingValue;
		}

		//templated display query
		template<typename F>
		void display(std::ostream& os, F f) const
		{
			Taxable myObj(f);
			double totalPrice = myObj(myValue);
			os << std::left;
			os << std::setw(11);
			os << myKey;
			os << std::setw(8);
			os << ": ";
			os << std::setw(10);
			os << myValue;
			os << totalPrice;
			os << std::endl;
		}

	};
}

#endif //SICT_KVPAIR_H
