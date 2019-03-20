//	program		:	Sale.h
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 13, 2019
//	professor	:	Chris, Szalwinski

#ifndef SICT_SALE_H
#define SICT_SALE_H

#include "iProduct.h"

namespace sict
{
	class Sale
	{
		std::vector <iProduct*> proObj;
		
	public:
		Sale(const char* incomingFileName);
		void display(std::ostream& os) const;
	};
}

#endif //SICT_SALE_H
