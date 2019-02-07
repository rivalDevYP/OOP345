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

	
	
	
	
	
	
	
	
	template<typename L, typename V>
	class SummableLVPair :public LVPair<L, V>
	{
		static V initialValue;
		static size_t minWidth;

	public:

		SummableLVPair()
		{
			//setClear();
		}

		SummableLVPair(const L& label, const V& v)
		{
			//call base class constructor, and pass all recieved values to it
			LVPair(label, v);
			if (minWidth < label.size())
			{
				minWidth++;
			}
		}

		static const V& getInitialValue()
		{
			//returns the initial value for the summation of a set of LVPair objects of label type L
			return initialValue<L>;
		}

		V sum(const L& label, const V& sum) const
		{
			return (this->sum + sum);
		}

		void display(std::ostream& os) const
		{
			os << std::setw(minWidth);
			display(os);
		}

		static V getInitVal()
		{
			return initialValue;
		}

		static size_t getMinWidthVal()
		{
			return minWidth;
		}


		template<>
		std::string SummableLVPair<std::string, std::string>::initialValue = std::string("");

		template<>
		int SummableLVPair<std::string, int>::initialValue = 0;

		

		V SummableLVPair<L, V>::initialValue = 0;



	};

	

}

#endif //SICT_LVPAIR_H
