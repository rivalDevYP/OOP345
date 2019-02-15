#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

#include "Taxable.h"
#include "KVPair.h"

namespace sict
{
	template <typename K, typename V>
	class KVPair
	{
		Taxable myObj;
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
			os << myKey << " : " << myValue << "\t" << f(myValue) << std::endl;
		}


	};
}

#endif //SICT_KVPAIR_H

