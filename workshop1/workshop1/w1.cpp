#include <iostream>
#include <cstring>
#include "process.h"
#include "String.h"

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << argv[i] << " "
		}
		std::cout << std::endl;
	}
	for (int i = 1; i < argc; ++i)
	{
		sict::process(&argv[i]);
	}
	return 0;	
}