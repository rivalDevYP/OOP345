//	program		:	iProduct.h
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 13, 2019
//	professor	:	Chris, Szalwinski

#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

namespace sict
{
	//extern int FW;

	class iProduct
	{
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};
	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream&, const iProduct&);
}

#endif //SICT_IPRODUCT_H