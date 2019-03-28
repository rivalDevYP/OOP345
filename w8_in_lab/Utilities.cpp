// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		Product newObj;

		for (size_t index = 0; index < desc.size(); index++)
		{
			if (desc[index].code == price[index].code)
			{
				try
				{
					newObj.desc = desc[index].desc;
					newObj.price = price[index].price;
					priceList.operator+=(&newObj);
				}
				catch (...)
				{
					throw "error";
				}

				break;
			}
		}

		return priceList;
	}
}