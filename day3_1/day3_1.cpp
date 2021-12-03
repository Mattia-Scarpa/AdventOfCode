// day3_1.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

int main()
{
	std::ifstream inputFile;
	inputFile.open("../inputDiagnostic.txt");

	if (!inputFile) {
		std::cerr << "Unable to open input file!" << std::endl;
		exit(1);
	}

	long long int code;
	int n = 0;
	std::vector<int> count = {0,0,0,0,0,0,0,0,0,0,0,0};

	std::cout << "Analyzing input file..." << std::endl;

	while (inputFile >> code) {

		int digit = 0;
		for (size_t i(0); i < count.size(); i++) {
			digit = code % 10;
			code /= 10;
			count[count.size()-1 - i] += digit;
		}
		n++;
	}

	int gamma = 0, epsilon = 0;

	for (size_t i(0); i < count.size(); i++) {
		gamma += (count[count.size() - 1 - i]>500)*pow(2,i);
		epsilon += (count[count.size() - 1 - i] < 500) * pow(2, i);
	}

	std::cout << "Gamma -> " << gamma << ";\nEpsilon -> " << epsilon << "." << std::endl;

	std::cout << "The total power consumption is -> " << gamma * epsilon << std::endl;

	return gamma * epsilon;
}
