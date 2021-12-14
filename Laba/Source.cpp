#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum padding {
	left = 0,
	right=1,
	center =2
};

void printMatrix(int** matrix, int row, int column, padding pad= padding::right);
char inputChar();
void printCross(char symbol, int size = 10);
void printCell(int elem, int size, padding pad = padding::right);
void printLine(int len);
int** createMatrix(int row, int column);


int main() {


	//printCross(inputChar(), 10);
	auto matrix = createMatrix(8, 8);
	printMatrix(matrix, 8, 8,padding::center);
	return 0;
}

int** createMatrix(int row, int column) {
	srand(NULL);
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[column];
		for (int j = 0; j < column; j++) {
			matrix[i][j] = rand() % 61 - 30;
		}
	}
	return matrix;
}


char inputChar() {
	char symbol = getchar();
	return symbol;
}

void printCross(char symbol, int size) {
	size = size < 1 ? 1 : size>15 ? 15 : size;
	for (int i = 0; i < size - 1; i++) {
		cout << setw(3 * size) << symbol << '\n';
	}
	for (int i = 0; i < size * 2; i++) {
		cout << setw(3) << symbol;
	}
	cout << "\n";
	for (int i = 0; i < size - 1; i++) {
		cout << setw(3 * size) << symbol << '\n';
	}
}
void printCell(int elem, int size, padding pad) {
	if (pad != padding::center) {
		cout << setw(size) << (pad == padding::left ? std::left : std::right) << elem;
		return;
	}
	auto sizeT = size+to_string(elem).length();
	auto left =ceil((size - to_string(elem).length())/2.0);
	cout << setw(size-left) << std::right << elem << setw(left+1);
}

void printMatrix(int** matrix, int row, int column, padding pad) {
	
	for (int i = 0; i < row; i++) {
		printLine((6+1)*column+1);
		cout << '|';
		for (int j = 0; j < column; j++) {
			printCell(matrix[i][j], 6, pad);
			cout << '|';
		}
		cout << endl;
	}
	printLine((column + 1) * 6-1);
}

void printLine(int len) {
	for (int i = 0; i < len; i++) {
		cout << "-";
	}
	cout << endl;
}