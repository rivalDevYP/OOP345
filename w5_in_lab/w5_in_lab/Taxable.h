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
			return (incomingPrice + ((incomingPrice / 100)*taxRate));
		}
	};
}

#endif //SICT_TAXABLE_H