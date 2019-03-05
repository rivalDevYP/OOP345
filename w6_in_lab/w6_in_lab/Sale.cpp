#include "Sale.h"

namespace sict
{
	Sale::Sale(const char* incomingFileName)
	{
		std::ifstream fileptr(incomingFileName);
		std::string temp;
		int lineCount{ 0 };
		if (fileptr.is_open())
		{
			while (!fileptr.eof() && fileptr.good())
			{
				std::getline(fileptr, temp, '\n');
				lineCount++;
				temp.clear();
			}

			for (int index = 0; index < lineCount; index++)
			{
				proObj.push_back(*(readRecord(fileptr)));
			}
		}
	}

	void Sale::display(std::ostream& os) const
	{
		for (int index = 0; index < proObj.size(); index++)
		{
			proObj[index].display(os);
		}
	}
}