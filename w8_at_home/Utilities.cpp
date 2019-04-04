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

		std::string errorMsg = "*** Negative prices are invalid ***";
		for (size_t index = 0; index < desc.size(); index++)
		{
			for (size_t tempNum = 0; tempNum < price.size(); tempNum++)
			{
				if (desc[index].code == price[tempNum].code)
				{
					Product *newObj = new Product(desc[index].desc, price[tempNum].price);

					try
					{
						newObj->validate();
						priceList.operator+=(newObj);
						delete newObj;
					}
					catch (...)
					{
						throw(errorMsg);
					}
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		std::string errorMsg = "*** Negative prices are invalid ***";
		for (size_t index = 0; index < desc.size(); index++)
		{
			for (size_t tempNum = 0; tempNum < price.size(); tempNum++)
			{
				if (desc[index].code == price[tempNum].code)
				{
					std::unique_ptr<Product> newObj(new Product(desc[index].desc, price[tempNum].price));

					try
					{
						newObj->validate();
						priceList.operator+=(*newObj);						
					}
					catch (...)
					{
						throw(errorMsg);
					}
				}
			}
		}
		
		return priceList;
	}
}