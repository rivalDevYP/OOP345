//	program    : ItemSet.h
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

namespace sict
{
	class ItemSet
	{
		std::string* myTokens;
		std::string myName;
		long mySerialNum;
		int myQuantity;
	public:
		//standard member functions
		ItemSet();
		~ItemSet();
		ItemSet(const ItemSet& incomingObj);
		ItemSet& operator=(const ItemSet& incomingObj);
		ItemSet(ItemSet&& incomingObj);
		ItemSet& operator=(ItemSet&& incomingObj);

		//module specific member functions
		ItemSet(std::string& incomingStr);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}

#endif //SICT_ITEMSET_H
