#include <iostream>

using namespace std;

const int n = 2;
const int m = 2;

// Задание - дана матрица В(n, m). Вычислить произведение чётных положительных элементов матрицы. 
int main() {

	system("chcp 1251");

	int B[n][m];
	// Блок ввода
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент B[" << i << "][" << j << "] матрицы: "; cin >> B[i][j];
		}

	// Блок вычислений
	int cellsProduct = 1;
	for (int i = 0, cellNumber = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ( cellNumber++ && (B[i][j] > 0) ) {
				cellsProduct *= B[i][j];
			}
		}

	if (cellsProduct) {
		cout << "Произведение четных положительных элементов матрицы B(n, m): " << cellsProduct << endl;
	}
	else {
		cerr << "Нет элемиентов, подходящих под условия!";
	}
	return 0;
}