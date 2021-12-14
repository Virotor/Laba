#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int BUFFER_SIZE = 1024 * 2;

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

char* inputString();
int strlen(char* string);
void sortString(char* string);
char* sumString(char* stringFirst, char* stringSecond);
char* resizeString(char* string);
char* deleteSpace(char* string);

int main() {


	//printCross(inputChar(), 10);
	/*auto matrix = createMatrix(8, 8);
	printMatrix(matrix, 8, 8,padding::center);*/
	char* a = inputString();
	//cout << a<<endl;
	char* b = inputString();
	//cout << b << endl;
	char* c = sumString(a, b);
	deleteSpace(c);
	cout << c;
	return 0;
}

char* deleteSpace(char* string) {
	int size = strlen(string);
	for (int i = 0; i < size; i++) {
		if (string[i] == ' ') {
			for (int j = i+1; j < size; j++) {
				string[j - 1] = string[j];
			}
			size--;
		}
	}
	return resizeString(string);
}

char* inputString() {
	char buffer[BUFFER_SIZE];
	cin.getline(buffer, BUFFER_SIZE, '\n');
	return resizeString(buffer);
}

int strlen(char* string) {
	int size = 0;
	while (string[size] != '\0') {
		size++;
	}
	return size+1;
}

char* sumString(char* stringFirst, char* stringSecond) {
	int sizeFirst = strlen(stringFirst);
	int sizeSecond = strlen(stringSecond);
	int stringSize = sizeFirst + sizeSecond-1;
	char* result = new char[stringSize];
	for (int i = 0; i < sizeFirst-1; i++) {
		result[i] = stringFirst[i];
	}
	for (int i = 0; i < sizeSecond; i++) {
		result[sizeFirst+i-1] = stringSecond[i];
	}
	return result;
}

void sortString(char* string) {
	int n = strlen(string);
	for (int i = 1; i < n-1; ++i)
	{
		for (int r = 0; r < n - i-1; r++)
		{
			if (string[r] < string[r + 1])
			{
				int temp = string[r];
				string[r] = string[r + 1];
				string[r + 1] = temp;
			}
		}
	}
}


char* resizeString(char* string) {
	int sizeString = strlen(string);
	char* result = new char[sizeString];
	for (int i = 0; i < sizeString; i++) {
		result[i] = string[i];
	}
	return result;
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