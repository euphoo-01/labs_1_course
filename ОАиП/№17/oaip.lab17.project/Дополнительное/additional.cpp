#include <iostream>
using namespace std;

//  Основные функции
void input1DArray(int* arr, int sz);
void input2DArray(int** arr, int* n, int* m);
void print2DArray(int** arr, int n, int m);
void print1DArray(int* arr, int n);

// Вариант 12
int countNegative(int* inputArr, int n);

int findRowOfNegative(int** arr, int n, int m);
void decraseCol(int** arr, int n, int col);

// Вариант 14
int findMinElement(int* arr, int n);
int findMaxElement(int* arr, int n);

int findPositiveRow(int** arr, int n, int m);
void inverseRow(int** arr, int n, int m, int row);

// Вариант 16
int findMaxNegativeElementIndex(int* arr, int n);
void swapThisWithLast(int* arr, int n, int index);

bool everyRowHasNegative(int** arr, int n, int m);
void invertMatrix(int** arr, int n, int m);


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

			int** matrix = new int*[n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[m];
			}

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
			cout << "===== ЗАДАНИЕ 1 ======" << endl;
			
			int n;
			cout << "Введите n: "; cin >> n;
			int* line = new int[n];
			input1DArray(line, n);
			
			int difference = findMaxElement(line, n) - findMinElement(line, n);
			cout << "Разность максимального и минимального элементов массива: " << difference;
			cout << "Масимальный элемент массива: " << findMaxElement(line, n);
			cout << "Минимальный элемент массива: " << findMinElement(line, n);
			
		}
		else if (exercise == 2) {
			cout << "===== ЗАДАНИЕ 2 ======" << endl;

			int n, m;
			cout << "Введите количество строк: "; cin >> n;
			cout << "Введите количество столбцов: "; cin >> m;

			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[m];
			}

			cout << "Введите элементы матрицы: " << endl;
			input2DArray(matrix, &n, &m);
			int positiveRow;
			if (positiveRow = findPositiveRow(matrix, n, m)) {
				inverseRow(matrix, n, m, positiveRow);
				cout << "В матрице есть столбец, где все элементы положительные: " << positiveRow << endl;
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "В матрице нет столбца, содержащего только положительные элементы." << endl;
			}

		}
		else {
			cerr << "Такого задания нет!" << endl;
		}
		break;
	}
	case 16: {
		if (exercise == 1) {
			cout << "====== ЗАДАНИЕ 1 ======" << endl;

			int n;
			cout << "Введите n: "; cin >> n;
			int* line = new int[n];

			int maxNegativeIndex = findMaxNegativeElementIndex(line, n);
			int maxNegativeElement = line[maxNegativeIndex];
			
			swapThisWithLast(line, n, maxNegativeIndex);
			cout << "Максимальный отрицательный элемент массива: " << maxNegativeElement << endl;
			cout << "Результат смены мест: " << endl;
			print1DArray(line, n);
		}
		else if (exercise == 2) {
			cout << "===== ЗАДАНИЕ 2 =====" << endl;

			int n, m;
			cout << "Введите количество строк: "; cin >> n;
			cout << "Введите количество столбцов: "; cin >> m;
			
			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[m];
			}

			input2DArray(matrix, &n, &m);

			if (everyRowHasNegative(matrix, n, m)) {
				cout << "Каждая строка матрицы имеет хотя-бы один отрицательный элемент." << endl;
				cout << "Результат инверсии: " << endl;
				invertMatrix(matrix, n, m);
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "В какой то строке матрицы нет отрицательного элемента." << endl;
			}
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
void print1DArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\t';
	}
}

// Вариант 12
int countNegative(int* inputArr, int n) {
	int count = 0;
	for (int i = 1; i < n; i+=2)
		if (inputArr[i] < 0)
			count++;
	return count;
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


// Вариант 14
int findMinElement(int* arr, int n) {
	int min = *arr;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int findMaxElement(int* arr, int n) {
	int max = *arr;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int findPositiveRow(int** arr, int n, int m) {
	bool isPositive;
	for (int j = 0; j < m; j++) {
		isPositive = true;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] < 0)
			{
				isPositive = false;
				break;
			}
		}
		if (isPositive)
			return j+1;
	}
	return 0;
}
void inverseRow(int** arr, int n, int m, int row) {
	row = row - 1;
	if (row > 0 && row < m) {
		for (int i = 0; i < n; i++) {
			arr[i][row - 1] *= -1;
		}
	}
}


// Вариант 16
int findMaxNegativeElementIndex(int* arr, int n) {
	int min = INT_MAX;
	int minIndex;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0 && arr[i] < min) {
			min = arr[i];
			minIndex = i;
		}
	}
	return min;
}
void swapThisWithLast(int* arr, int n, int index) {
	int buffer = arr[index];
	arr[index] = arr[n-1];
	arr[n - 1] = buffer;
}
bool everyRowHasNegative(int** arr, int n, int m) {
	bool currentRowHasNegative = false;
	for (int i = 0; i < n; i++) {
		currentRowHasNegative = false;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < 0) {
				currentRowHasNegative = true;
			}
		}
		if (!currentRowHasNegative)
			return false;
	}
	if (currentRowHasNegative)
		return true;
	else
		return false;
}
void invertMatrix(int** arr, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] *= -1;
}