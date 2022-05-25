#include "./Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int rows, cols;
	cout << "Enter number of rows (number of columns will be the same)\n";
	cin >> rows;
	cols = rows;
	int* array = new int[rows * cols];
	int** arr = new int* [rows];
	Menu(arr, array, cols, rows);
}
