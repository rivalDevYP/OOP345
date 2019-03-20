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
	protected:
		unsigned int myProductNum{ 0 };
		double myPrice{ 0.0f };
	public:
		Product();
		Product(size_t incomingProductNum, double incomingPrice);
		double price() const;
		void display(std::ostream& os) const;
	};

	class TaxableProduct : public Product
	{
		enum taxRates
		{
			HST=13,
			PST=8
		};

		char taxableStatus{ '\n' };

	public:
		TaxableProduct(size_t incomingProductNum, double incomingPrice, char incomingTaxStatus);
		double price() const;
		void display(std::ostream& os);
	};

	iProduct* readRecord(std::ifstream& file);
}

#endif //SICT_PRODUCT_H