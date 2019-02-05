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
	
	//SummableLVPair class derives from LVPair class
	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
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

		//templated declaration that initializes the field width class variable to 0

		//template specialization that initializes the starting value for an LVPair<std::string, int> type to 0.
		template<>
		class LVPair<std::string, int>
		{

		};

		//template specialization that initializes the starting value for an LVPair<std::string, std::string > type to an empty string
		
		/* professor provided */
		template<> //template specialization 
		std::string SummableLVPair<std::string, std::string>::initial = std::string(""); //returnType className<templateParams>::noClue = std::string("");
		/* professor provided */

	};
}

#endif //SICT_LVPAIR_H
