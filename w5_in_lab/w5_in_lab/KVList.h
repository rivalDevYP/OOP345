#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

namespace sict
{
	template<typename T>
	class KVList
	{
		T* listOfTees{ nullptr }; //heh heh heh... tees... XD
		size_t currentNumOfTees{ 0 };
		size_t maximumNumOfTees{ 0 };
	public:

		//default constructor
		KVList()
		{			
		}

		//one argument constructor, initializes listOfTees
		KVList(int n) : listOfTees(n > 0 ? new T[n]{ nullptr } : nullptr)
		{
			maximumNumOfTees = n;
		}

		//disabled copy constructor
		KVList(const KVList& incomingObj) = delete;

		//disabled copy assignment operator
		KVList& operator=(const KVList& incomingObj) = delete;

		//move constructor
		KVList(KVList&& incomingObj)
		{
			*this = std::move(incomingObj);
		}

		//disabled move assignment operator
		KVList& operator=(KVList&& incomingObj) = delete;

		//destructor
		~KVList()
		{
			delete[]listOfTees;
		}

		//operator overload
		const T& operator[](size_t i) const
		{
			return listOfTees[i];
		}
		
		//templated display query
		template<typename F>
		void display(std::ostream& os, F f)
		{
			for (unsigned int index = 0; index < currentNumOfTees; index++)
			{
				listOfTees[index].display(os, f);
			}
		}

		//pushback modifier
		void push_back(const T& t)
		{
			if (currentNumOfTees < maximumNumOfTees)
			{
				for (unsigned int index = 0; index < maximumNumOfTees; index++)
				{
					listOfTees[currentNumOfTees++] = t;
				}
			}
		}
	};
}

#endif //SICT_KVLIST_H
