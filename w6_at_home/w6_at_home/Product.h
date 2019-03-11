//	program		:	Product.h
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 5, 2019
//	professor	:	Chris, Szalwinski

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include "iProduct.h"

namespace sict
{
	class Product : public iProduct
	{
		unsigned int myProductNum{ 0 };
		double myPrice{ 0.0f };		
	public:
		Product();
		Product(long incomingProductNum, double incomingPrice);
		double price() const;
		void display(std::ostream& os) const;
	};
	iProduct* readRecord(std::ifstream& file);

	class TaxableProduct : public Product
	{
		enum taxType
		{
			HST = 13,
			PST = 8
		};
		char isTaxable;
	public:
		TaxableProduct(unsigned int incomingProNum, double incomingPrice, char incomingTaxType);
		double price() const;
		void display(std::ostream& os) const;
	};
}

#endif //SICT_PRODUCT_H