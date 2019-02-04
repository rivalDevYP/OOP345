/*
	program: LVPair.h
	programmer: Yathavan, Parameshwaran
	instructor: Chris, Szalwinski
	course: OOP345SCC
	date: January 29, 2018
	description: declaration file for the LVPair module
*/

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

namespace sict
{
	template<typename L, typename V>
	class LVPair
	{
		L myLabel;
		V myValue;

	public:

		//constructor: sets values to safe empty state
		LVPair()
		{
			
		}

		//2 arg. constructor: copies over incoming values to local values
		LVPair(const L& label, const V& value)
		{
			myLabel = label;
			myValue = value;
		}

		//display function: prints object to output stream
		virtual void display(std::ostream& os) const
		{
			os << this->myLabel << " : " << this->myValue << std::endl;
		}

	};

	//ostream overload: prints incoming object to output stream
	template<typename L, typename V>
	std::ostream & operator<<(std::ostream& os, const LVPair<L, V> & pair)
	{
		pair.display(os);
		return os;
	}	
	
	//SummableLVPair class deriving from LVPair class
	template<typename L, typename V>
	class SummableLVPair : LVPair<L, V>
	{
		static V initialValue;
		static size_t minWidth;
	public:

		SummableLVPair()
		{

		}
		SummableLVPair(const L& label, const V& v)
		{

		}
		const V& getInitialValue()
		{

		}
		
		void display(std::ostream& os) const
		{

		}

	};
}

#endif //SICT_LVPAIR_H
