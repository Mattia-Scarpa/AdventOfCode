// day3_4.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

constexpr auto CODE_SIZE = 12;				// code string length

std::string rating(std::vector<std::string> bCodes, int index, int r) {					// bCodes	= binary codes vector
																						// index	= bit position
																						// r		= O2/CO2 rating selector
	std::string code;
	if (bCodes.size() == 1) {
		return bCodes[0];
	}
	if (bCodes.empty() || bCodes[0].length() != CODE_SIZE || index >= CODE_SIZE) {
		std::cerr << "Error in processing codes vector or codes strings are broken!";
		exit(1);
	}

	std::vector<std::string> codeOne, codeZero;

	for (size_t i(0); i < bCodes.size(); i++) {

		if (bCodes[i].substr(index, 1) == "1") {
			codeOne.push_back(bCodes[i]);
		}
		else
			codeZero.push_back(bCodes[i]);
	}

	switch (r) {
	case 0:			// O2 generator rating
		if (codeOne.size() >= codeZero.size())
			code = rating(codeOne, index + 1, r);
		else
			code = rating(codeZero, index + 1, r);
		break;
	case 1:			// CO2 scrubber rating
		if (codeOne.size() < codeZero.size())
			code = rating(codeOne, index + 1, r);
		else
			code = rating(codeZero, index + 1, r);
		break;
	default:
		if (codeOne.size() >= codeZero.size())
			code = rating(codeOne, index + 1, r);
		else
			code = rating(codeZero, index + 1, r);
		break;
	}
	return code;
}

int BinToDec(std::string bin) {
	int dec = 0;
	for (size_t i = 0; i < bin.length(); i++) {
		dec += (bin.substr(bin.length() - 1 - i, 1) == "1") * pow(2, i);
	}
	return dec;
}

int main() {

	std::ifstream inputFile;
	inputFile.open("../inputDiagnostic.txt");

	if (!inputFile) {
		std::cerr << "Unable to open input file!" << std::endl;
		exit(1);
	}

	std::vector<std::string> codes; // diagnostic code vectors
	std::string code;
	std::vector<std::vector<std::string>> codeOne, codeZero;

	// Loading inputfile
	while (inputFile >> code) {
		if (code.length() == CODE_SIZE)
			codes.push_back(code);
	}

	std::string O2Generator, Co2Scrubber;

	O2Generator = rating(codes, 0, 0);
	Co2Scrubber = rating(codes, 0, 1);

	int O2 = BinToDec(O2Generator);
	int CO2 = BinToDec(Co2Scrubber);

	std::cout << "The Oxygen generator rating is ->" << O2 << ";\nWhile the CO2 scrubber rating is ->" << CO2 << "." << std::endl;
	std::cout << "The life support rating of the submarine is -> " << O2 * CO2 << std::endl;

	return O2 * CO2;
}
