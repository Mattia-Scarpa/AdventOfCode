// day1_1.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <fstream>
#include <vector>

int main()
{

    std::ifstream inputFile;
    inputFile.open("../inputDepth.txt");

    if (!inputFile) {
        std::cerr << "Unable to open input file!" << std::endl;
        exit(1);
    }

    int depth;
    int last = 0;
    int count = 0;
    int n = 0;

    std::vector<int> d;

    std::cout << "Analyzing input file..." << std::endl;

    int d_sum[4]{};

    while (inputFile >> depth) {
        if (n < 3) {
            d_sum[n] = depth;
        } else {
            d_sum[(n) % 4] = depth;
            count += d_sum[(n - 3) % 4] < d_sum[n%4];
            }
        n++;
    }

    std::cout << "There are " << count << " sums larger than the previous sum" << std::endl;

    return count;
}
