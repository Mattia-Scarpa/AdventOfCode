// day2_2.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct position {
    int p = 0;          // position variable
    int d = 0;          // depth variable
    int a = 0;          // aim variable
};

//------------------------------------------------------------------------

int main()
{
    // Reading depth vaues from inputFiles

    std::ifstream inputFile;
    inputFile.open("../inputCommand.txt");

    if (!inputFile) {
        std::cerr << "Unable to open input file!" << std::endl;
        exit(1);
    }

    std::string c;

    position position;

    std::cout << "Analyzing input file..." << std::endl;

    int x;

    while (inputFile >> c) {    // reading command instructions
        inputFile >> x;

        position.p += (c == "forward") * x;
        position.d += (c == "forward") * x * position.a;
        position.a += (c == "down") * x - (c == "up") * x;
    }

    std::cout << "Your final position is ->" << position.p << "\nWhile your final depth is -> " << position.d << std::endl;
    std::cout << "Multiplying your final horizontal position by your final depth you obtain: " << position.p << " * " << position.d << " = " << position.p * position.d << std::endl;

    return position.p * position.d;
}
