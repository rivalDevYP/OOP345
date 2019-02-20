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
			os << std::left 
				<< std::setw(10) 
				<< myKey 
				<< " : " 
				<< std::setw(10)
				<< std::right 
				<< myValue 
				<< std::setw(10) 
				<< f(myValue) 
				<< std::endl;
		}

	};
}

#endif //SICT_KVPAIR_H
