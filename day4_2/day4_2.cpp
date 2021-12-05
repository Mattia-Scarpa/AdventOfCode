// day4_2.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

constexpr auto BOARD_SIZE = 5;
int winningBoard, last;

// Creating bingo boards

struct board {
	int table[5][5]{};
	int sum = 0;
	std::vector<int> rows = { std::vector<int>(5,0) };		// marked numbers counter in rows
	std::vector<int> cols = { std::vector<int>(5,0) };		// marked numbers counter in columns
};

// Utilities funciton

void extractSequence(std::string sSeq, std::vector<int>& vSeq) {
	vSeq.clear();
	std::size_t pos = 0;
	std::size_t found = sSeq.find(",", pos);

	while (found != sSeq.npos) {
		vSeq.push_back(stoi(sSeq.substr(pos, found - pos)));
		pos = found + 1;
		found = sSeq.find(",", pos);
	}
	vSeq.push_back(stoi(sSeq.substr(pos, sSeq.length() - pos)));		// extract last value
}

void fillBoards(std::ifstream& inputFile, std::vector<board>& boards) {
	int num;
	while (true) {
		board bTemp;

		for (size_t i = 0; i < BOARD_SIZE; i++) {
			for (size_t j = 0; j < BOARD_SIZE; j++) {		// adding line to board
				if (!(inputFile >> num)) {
					return;
				}
				else {
					bTemp.table[i][j] = num;
					bTemp.sum = bTemp.sum + num;
				}
			}
		}
		boards.push_back(bTemp);
	}
}

void findExtracted(int extraction, std::vector<board> &boards) {
	for (size_t b = 0; b < boards.size(); b++) {
		for (size_t i = 0; i < BOARD_SIZE; i++) {
			for (size_t j = 0; j < BOARD_SIZE; j++) {
				if (boards[b].table[i][j] == extraction) {
					boards[b].sum -= extraction;
					boards[b].cols[i]++;
					boards[b].rows[j]++;

					if ((boards[b].cols[i] == 5 || boards[b].rows[j] == 5) && boards.size() > 1) {
						boards.erase(boards.begin() + b);
						if (b >= boards.size())
							return;
					}
					else {
						if ((boards[b].cols[i] == 5 || boards[b].rows[j] == 5) && boards.size() == 1) {
							winningBoard = boards[b].sum;
							last = extraction;
							std::cout << "The winning board has sum " << winningBoard << ".\nThe final score is -> " << winningBoard * last << std::endl;
							exit(1);
						}
					}
				}
			}
		}
	}
}

int main() {

	std::ifstream inputFile;
	inputFile.open("../inputBingo.txt");

	if (!inputFile) {
		std::cerr << "Unable to open input file!" << std::endl;
		exit(1);
	}

	std::string seq;
	inputFile >> seq;
	std::vector<int> sequence;
	extractSequence(seq, sequence);

	std::vector<board> boards;

	fillBoards(inputFile, boards);

	for (int extraction : sequence) {
		findExtracted(extraction, boards);
	}
}