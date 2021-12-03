// day2_2.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct position {
    int p = 0;
    int d = 0;
};

//------------------------------------------------------------------------

int main()
{
	// Reading depth vaues and store it in an array from inputFiles

    std::ifstream inputFile;
    inputFile.open("../inputCommand.txt");

    if (!inputFile) {
        std::cerr << "Unable to open input file!" << std::endl;
        exit(1);
    }

    std::string c;

    //std::vector<int> commands;

    position position;

    std::cout << "Analyzing input file..." << std::endl;

    int x;

   while (inputFile >> c) {
       inputFile >> x;

       position.p += (c=="forward") * x;
       position.d += (c == "down") * x - (c == "up") * x;
    }

   std::cout << "Your final position is ->" <<  position.p << "\nWhile your final depth is -> " << position.d << std::endl;
   std::cout << "Multiplying your final horizontal position by your final depth you obtain: " << position.p << " * " << position.d << " = " << position.p * position.d << std::endl;

   return position.p * position.d;
}
