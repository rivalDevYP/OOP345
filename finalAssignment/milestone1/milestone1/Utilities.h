//	program    : Utilities.h
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

namespace sict
{
	class Utilities
	{
		std::string* myToken;
		char* myDelim;
		int myFieldWidth;	
	public:
		//standard member functions
		Utilities();
		~Utilities();
		Utilities(const Utilities& incomingObj);
		Utilities& operator=(const Utilities& incomingObj);
		Utilities(Utilities&& incomingObj);
		Utilities& operator=(Utilities&& incomingObj);

		//module specific member functions
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		void setDelimiter(const char d);
		void setFieldWidth(size_t t);
	};
}

#endif //SICT_UTILITIES_H