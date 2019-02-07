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



	/*
	T -> the type of any element in the array
	L -> the type of the specified label 
	V -> the type of the summation value
	N -> the maximum number of elements in the array 
	*/

	template<typename T, typename L, typename V, int N>
	class LVList : public List<T, int N>
	{
	public:
		V accumulate(const L& label) const
		{
			//query recieves reference to L object
			//returns sum of values of all elements in current LVList object that have lavel of specified label in locally created value object
			//initialize accumulator object to initial value for objects of label-value pair (T)
			//accumulate values by calling append query on each element in list stored in base class
			/*Check label of current object against the incoming label object
			Initialize V to initial value of T(check hints)
			Call += operator to accumulate values on each element in list stored in base class FROM the locally created V object
			Return said V object*/
			if (this<L> == label)
			{
				V VOBJECT;
				T TOBJECT;
				VOBJECT = TOBJECT;


			}
			

		}
	};
}

#endif //SICT_LIST_H
