#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

namespace sict 
{
	int FW;

	class iProduct
	{
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};
	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
}

#endif //SICT_IPRODUCT_H