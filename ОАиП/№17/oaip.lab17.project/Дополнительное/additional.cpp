#include <iostream>
using namespace std;

//  Основные функции
void input1DArray(int* arr, int sz);
void input2DArray(int** arr, int* n, int* m);
void initialize2DArray(int** arr, int n, int m);

// Вариант 12
int countNegative(int* inputArr, int n);

int findRowOfNegative(int** arr, int n, int m);
void decraseCol(int** arr, int n, int col);

// Вариант 14
int findMinElement(int** arr, int n);

// Вариант 16

int main() {
	system("chcp 1251");

	int variant, exercise;
	cout << "Введите вариант: "; cin >> variant;
	cout << "Введите номер задания: "; cin >> exercise;

	switch (variant) {
	case 12: {
		if (exercise == 1) {
			cout << "===== ЗАДАНИЕ 1 =====" << endl;
			
			int n;
			cout << "Введите n: "; cin >> n;
			int* line = new int[n];

			input1DArray(line, n);

			if (int nNegatives = countNegative(line, n)) {
				cout << "Количество отрицательных элементов в массиве: " << nNegatives << endl;
			}
			else {
				cerr << "В массиве нет отрицательных элементов!";
			}
		}
		else if (exercise == 2) {
			cout << "===== ЗАДАНИЕ 2 =====" << endl;

			int n, m;
			cout << "Введите количество строк матрицы: "; cin >> n;
			cout << "Введите количество столбцов матрицы:"; cin >> m;

			int** matrix = nullptr;
			initialize2DArray(matrix, n, m);

			if (int row = findRowOfNegative(matrix, n, m)) {
				decraseCol(matrix, n, row);
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "В матрице нет отрицательных элементов." << endl;
			}
			
		}
		else {
			cerr << "Такого задания нет!" << endl;
		}
		break;
	}
	case 14: {
		if (exercise == 1) {

		}
		else if (exercise == 2) {

		}
		else {
			cerr << "Такого задания нет!" << endl;
		}
		break;
	}
	case 16: {
		if (exercise == 1) {

		}
		else if (exercise == 2) {

		}
		else {
			cerr << "Такого задания нет!" << endl;
		}
		break;
	}
	default: {
		cerr << "Такого варианта нет!" << endl;
		break;
	}
	}

	return 0;
}

// Пользовательские функции

// Основные функции
void input1DArray(int* arr, int sz) {
	for (int i{}; i < sz; i++) {
		cout << "Введите элемент массива [" << i + 1 << "]: "; 
		cin >> arr[i];
	}
}
void input2DArray(int** arr, int* n, int* m) {
	for (int i{}; i < *n; i++) {
		cout << i + 1 << "-я строка: " << endl;
		for (int j{}; j < *m; j++) {
			cin >> arr[i][j];
		}
		cout << endl;
	}
}
void print2DArray(int** arr, int n, int m) {
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

void initialize2DArray(int** arr, int n, int m) {
	arr = new int* [n];
	for (int i{}; i < n; i++) {
		arr[i] = new int[m];
	}
}


// Вариант 12
int countNegative(int* inputArr, int n) {
	int count = 0;
	for (int i = 1; i < n; i+=2)
		if (inputArr[i] < 0)
			count++;
}

int findRowOfNegative(int** arr, int n, int m) {
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (arr[i][j] < 0) {
				return i;
			}
		}
	}
}

void decraseCol(int** arr, int n, int col) {
	for (int i{}; i < n; i++) {
		arr[i][col] /= 2;
	}
}
