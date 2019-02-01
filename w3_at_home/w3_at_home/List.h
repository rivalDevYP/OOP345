/*
	program: List.h
	programmer: Yathavan, Parameshwaran
	instructor: Chris, Szalwinski
	course: OOP345SCC
	date: January 29, 2018
	description: declaration file for the List module
*/

#ifndef SICT_LIST_H
#define SICT_LIST_H

namespace sict
{
	template <typename T, int N>
	class List
	{
		size_t numOfElements = 0;
		T arrayOne[N];

	public:

		//size query: returns number of elements in array
		size_t size() const
		{
			return numOfElements;
		}

		//query: returns elements at the position of the incoming integer
		const T& operator[](size_t i) const
		{
			return (arrayOne[i]);
		}

		//operator overload: adds incoming element to array, provided there is any space available
		void operator+=(const T& t)
		{
			if (numOfElements <= N)
			{
				arrayOne[numOfElements] = t;
				numOfElements++;
			}			
		}

	};
}

#endif //SICT_LIST_H
