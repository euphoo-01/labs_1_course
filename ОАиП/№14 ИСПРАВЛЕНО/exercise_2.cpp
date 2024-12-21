#include <iostream>
using namespace std;

// Задача - Проверить, есть ли в матрице хотя бы одна строка, содержащая элемент, равный нулю, и найти ее номер. 
// Уменьшить все элементы матрицы на значение первого элемента найденной строки.

const int m = 3;
const int n = 3;

int main() {
	system("chcp 1251");

	int A[m][n];
	
	// Блок ввода
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			 cin >> *(*(A + i) + j);
		}
		cout << "\n";
	}

	bool nullElementExists = false;
	int nullElementRow;

	for (int i = 0; i < m; i++) { // Логический блок. Проверка матрицы на выполнение условия
		for (int j = 0; j < n; j++) {
			if ( *(*(A + i) + j) == 0 ) {
				nullElementExists = true;
				nullElementRow = i;
			}
			if (nullElementExists) {
				break;
			}
		}
	}

	if (nullElementExists) { // Уменьшаем все элементы матрицы на значение первого элемента найденной строки.
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (*(*(A + i) + j) != *(*(A + nullElementRow) + 0)) {
					*(*(A + i) + j) -= *(*(A + nullElementRow) + 0);
				}
			}
		}
		cout << "В матрице есть хотя бы одна строка, содержащая элемент, равный нулю. Ее номер - " << nullElementRow+1 << endl;
	}
	else {
		cerr << "В матрице отсутствуют элементы, подходящие под условия. Матрица остаётся без изменений." << endl;
	}

	for (int i = 0; i < m; i++) { // Вывод матрицы
		for (int j = 0; j < n; j++) {
			cout << *(*(A + i) + j) << '\t';
		}
		cout << endl;
	}

	return 0;
}