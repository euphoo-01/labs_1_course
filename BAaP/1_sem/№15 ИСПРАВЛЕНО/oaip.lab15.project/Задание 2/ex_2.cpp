#include <iostream>

using namespace std;

// Найти в матрице первую строку, все элементы которой отрицательны. Увеличить все элементы матрицы на зна-чение первого элемента найденной строки.

int main() {
	system("chcp 1251");


	int n,m;
	cout << "Введите количество строк: "; cin >> n;
	cout << "Введите количество столбцов: "; cin >> m;
	

	// Объявление строк
	int** cells{ new int* [n] {} };
	// Объявление столбцов для каждой строки
	for (int i{}; i < n; i++) {
		cells[i] = new int[m] {};
	}


	// Ввод
	cout << "Введите элементы массива: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cin >> cells[i][j];
		}
		cout << endl;
	}
	cout << "Исходная матрица: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}


	// Логический блок
	int negativeIndex = -1;
	for (int i{}; i < n; i++) {
		bool havePositiveValue;
		for (int j{}; j < m; j++) {
			havePositiveValue = false;
			if (cells[i][j] > 0) {
				havePositiveValue = true;
				break;
			}
		}
		if (!havePositiveValue) {
			negativeIndex = i;
			break;
		}
	}

	if (negativeIndex+1) {
		cout << "Первая строка, в которой все элементы отрицательные: " << negativeIndex + 1 << endl;

		// Уменьшаем матрицу на первый элемент найденной строки
		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				if (cells[i][j] != cells[negativeIndex][0]) {
					cells[i][j] += cells[negativeIndex][0];
				}
			}
		}

		// Вывод
		cout << "Результат: " << endl;
		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				cout << cells[i][j] << '\t';
			}
			cout << endl;
		}
	}
	else {

		cerr << "В этой матрице нет такой строки, в которой все элементы отрицательные.";
	
	}


	// Очистка памяти
	for (int i{}; i < n; i++) {
		delete[] cells[i];
	}
	delete[] cells;

	return 0;
}