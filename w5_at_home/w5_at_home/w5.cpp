// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}


int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// check for command line errors
	try {
		if (argc != 3) exit(1);
	}
	catch (int errCode) {
		std::cout << "The program has exited with the error code: " << errCode << std::endl;
	}
	catch (const char* errMsg) {
		std::cout << "The program has exited with the error message: " << errMsg << std::endl;
	}
	catch (...) {
		std::cout << "The program has exited with an error..." << std::endl;
	}

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);

	// process price list file
	try
	{	
		KVList<KVPair<std::string, float>> priceList = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[1]);

		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));

	}
	catch (int errCode) {
		std::cout << "The program has exited with the error code: " << errCode << std::endl;
	}
	catch (const char* errMsg) {
		std::cout << "The program has exited with the error message: " << errMsg << std::endl;
	}
	catch (...) {
		std::cout << "The program has exited with an error..." << std::endl;
	}

	// process grade list file
	try 
	{

		KVList<KVPair<int, float>> gradeList = createList<
			KVList<KVPair<int, float>>,
			KVPair<int, float>,
			int,
			float>
			(argv[2]);

		std::cout << "\nStudent List Letter Grades Included\n===================================\n";
		std::cout << "Student No :      Grade    Letter\n";

		auto convertToGrade = [](float incomingGrade)
		{
			if (incomingGrade >= 0 && incomingGrade <= 49.9)
				return "F ";
			if (incomingGrade >= 50 && incomingGrade <= 54.9)
				return "D ";
			if (incomingGrade >= 55 && incomingGrade <= 59.9)
				return "D+";
			if (incomingGrade >= 60 && incomingGrade <= 64.9)
				return "C ";
			if (incomingGrade >= 65 && incomingGrade <= 69.9)
				return "C+";
			if (incomingGrade >= 70 && incomingGrade <= 74.9)
				return "B ";
			if (incomingGrade >= 75 && incomingGrade <= 79.9)
				return "B+";
			if (incomingGrade >= 80 && incomingGrade <= 89.9)
				return "A ";
			if (incomingGrade >= 90 && incomingGrade <= 100)
				return "A+";
			else
				throw("undefined grade value recieved...");
		};	

		gradeList.display(std::cout, convertToGrade);


	}
	catch (int errCode) {
		std::cout << "The program has exited with the error code: " << errCode << std::endl;
	}
	catch (const char* errMsg) {
		std::cout << "The program has exited with the error message: " << errMsg << std::endl;
	}
	catch (...) {
		std::cout << "The program has exited with an error..." << std::endl;
	}


}
