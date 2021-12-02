// day1_1.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <fstream>

int main()
{

    std::ifstream inputFile;
    inputFile.open("../input.txt");

    if (!inputFile) {
        std::cerr << "Unable to open input file!" << std::endl;
        exit(1);
    }

    int depth;
    int last = 0;
    int count = 0;

    std::cout << "Analyzing input file..." << std::endl;

    while (inputFile >> depth) {
        if (last != 0 && depth > last)
            count++;
        last = depth;
    }
    std::cout << "There are " << count << " measurements larger than the previous measurement" << std::endl;

    return count;
}
