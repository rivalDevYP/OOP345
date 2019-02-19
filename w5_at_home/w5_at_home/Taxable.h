// program    : Taxable.h
// programmer : Yathavan, Parameshwaran
// professor  : Chris, Szalwinski
// date       : February 15, 2019

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict
{
	class Taxable
	{
		const float taxRate;
	public:

		//one argument constructor, initialized taxRate
		Taxable(float incomingVar) : taxRate(incomingVar > 0 ? incomingVar : 0)
		{
		}

		//operator overload, returns total price of value with tax
		float operator()(float incomingPrice)
		{
			return (incomingPrice + ((incomingPrice / 100)*(taxRate*100)));
		}

	};
}

#endif //SICT_TAXABLE_H
