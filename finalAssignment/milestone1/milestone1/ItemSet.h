//	program    : ItemSet.h
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include "Utilities.h"

namespace sict
{
	class ItemSet
	{
		Utilities helper;

		char myDelim;
		static int myFieldWidth;

		std::string myName;
		std::string myDescription;
		long mySerialNum{ 0 };
		int myQuantity{ 0 };

	public:
		ItemSet();
		ItemSet(std::string& incomingStr);

		// disabled copy & move semantics
		ItemSet(const ItemSet& incomingObj) = delete;
		ItemSet& operator=(const ItemSet& incomingObj) = delete;
		ItemSet(ItemSet&& incomingObj) = delete;
		ItemSet& operator=(ItemSet&& incomingObj) = delete;		

		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;

		ItemSet& operator--();

		void display(std::ostream& os, bool full) const;

		static void setFieldWidth(int incomingWidth);
		static int getFieldWidth();
	};
}

#endif //SICT_ITEMSET_H






//vector is a mathematical object that has a magnitude and a direction