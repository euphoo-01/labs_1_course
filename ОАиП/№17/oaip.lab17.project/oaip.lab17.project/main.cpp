#include <iostream>
using namespace std;

void input1DArray(int* arr, int* sz);
void returnOddNumbers(int* arr, int* sz);
void delete2DArray(int** arr, int* n);

void input2DArray(int** arr, int* n, int* m);
int findMaxNumber(int** arr, int* n, int* m);
int numberOfRepeats(int** arr, int* number, int* n, int* m);
void printRepeatedIndexes(int** arr, int* number, int* n, int* m);

int main() {
	system("chcp 1251");

	int exercise;
	cout << "Какое задание? "; cin >> exercise;

	switch (exercise) {
	case 1: {
		cout << "===== ЗАДАНИЕ 1 =====" << endl;
		int n;
		cout << "Введите размер массива: "; cin >> n;

		int* line = new int[n];

		input1DArray(line, &n);

		returnOddNumbers(line, &n);

		delete[] line;
		break;
	}
	case 2: {
		cout << "===== ЗАДАНИЕ 2 =====" << endl;
		int n, m;
		cout << "Введите количество строк матрицы: "; cin >> n;
		cout << "Введите количество столбцов матрицы: "; cin >> m;

		int** matrix = new int* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
		}
		input2DArray(matrix, &n, &m);

		int maxNumber = findMaxNumber(matrix, &n, &m);
		int repeats = numberOfRepeats(matrix, &maxNumber, &n, &m);

		if (repeats - 1) {
			cout << "Число " << maxNumber << " встречается в массиве " << repeats << " раз. Его позиции: ";
			printRepeatedIndexes(matrix, &maxNumber, &n, &m);
		}

		delete2DArray(matrix, &n);
		break;
	}
	default: {
		cerr << "Такого варианта нет!" << endl;
	}
	}
	return 0;
}

void input1DArray(int* arr, int* sz) {
	for (int i{}; i < *sz; i++) {
		cout << "Введите элемент массива [" << i+1 << "]: "; cin >> arr[i];
	}
}

void returnOddNumbers(int* arr, int* sz) {
	for (int i = 0; i < *sz; i += 2) {
		if (arr[i] % 2 == 0) {
			cout << "Элемент под номером " << i + 1 << " четный." << endl;
		}
	}
}

void delete2DArray(int** arr, int* n){
	for (int i{}; i < *n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void input2DArray(int** arr, int* n, int* m) {
	for (int i{}; i < *n; i++) {
		for (int j{}; j < *m; j++) {
			cin >> arr[i][j];
		}
		cout << endl;
	}
}

int findMaxNumber(int** arr, int* n, int* m) {
	int tempMax = **arr;
	for (int i{}; i < *n; i++) {
		for (int j{}; j < *m; j++) {
			if (arr[i][j] > tempMax) {
				tempMax = arr[i][j];
			}
		}
	}
	return tempMax;
}

int numberOfRepeats(int** arr, int* number, int* n, int* m) {
	int count = 0;
	for (int i{}; i < *n; i++)
		for (int j{}; j < *m; j++)
			if (arr[i][j] == *number)
				count++;
	return count;
}
void printRepeatedIndexes(int** arr, int* number, int* n, int* m) {
	for (int i{}; i < *n; i++) {
		for (int j{}; j < *m; j++) {
			if (arr[i][j] == *number)
				cout << i+1 << " строка " << j+1 << " столбец." << endl;
		}
	}
}