#include <iostream>
#include <ctime>

using namespace std;

void ex_1();
void ex_2();
void ex_3();


int main() {
	system("chcp 1251");

	// Выбор задания
	int choice;
	cout << "Выберите задание, которое нужно выполнить: "; cin >> choice;

	switch (choice) {
	case 1: 
		ex_1();
		break;
	case 2:
		ex_2();
		break;
	case 3:
		ex_3();
		break;
	}

	return 0;
}


// Задача - Дана квадратная матрица порядка 2n, элементы которой формируются случайным образом и находятся в пределах от -10 до 10. 
// Получить новую матрицу, переставляя ее блоки размера n x n в соответствии со схемой.

void ex_1() {

	const int n = 3;

	int A[2 * n][2 * n]; // Квадратная матрица порядка 2n
	int maxValue = 10,
		minValue = -10;

	for (int i = 0; i < 2 * n; i++) { // Генерация чисел от -10 до 10
		for (int j = 0; j < 2 * n; j++) {
			A[i][j] = (int)(((double)rand() / (double)RAND_MAX) * (maxValue - minValue) + minValue);
			cout << A[i][j] << '\t';
			j == n-1 ? printf("\t") : j;
		}
		cout << '\n';
		i == n-1 ? printf("\n") : i;
	}

	int B[2 * n][2 * n];

	// Перестановка блоков
	for (int i = 0; i < n; i++) { // Первый блок
		for (int j = 0; j < n; j++) {
			B[i + n][j + n] = A[i][j];
		}
	}

	for (int i = 0; i < n; i++) { // Второй блок
		for (int j = n; j < 2 * n; j++) {
			B[i+n][j-n] = A[i][j];
		}
	}

	for (int i = n; i < 2 * n; i++) { // Третий блок
		for (int j = 0; j < n; j++) {
			B[i - n][j + n] = A[i][j];
		}
	}

	for (int i = n; i < 2 * n; i++) { // Четвертый блок
		for (int j = n; j < 2 * n; j++) {
			B[i - n][j - n] = A[i][j];
		}
	}

	// Вывод
	cout << "Результат:" << '\n';
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << B[i][j] << '\t';
			j == n-1 ? printf("\t") : j;
		}
		cout << '\n';
		i == n-1 ? printf("\n") : i;
	}

}

// Задание - Латинским квадратом порядка n называется квадратная таблица размером n х n, 
// каждая строка и каждый столбец которой содержат все числа от 1 до n. Для заданного n в матрице L(n, n) построить латинский квадрат порядка n. 


void ex_2() {

	const int n = 3;
	int L[n][n];

	// Генерация латинского квадрата
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			L[i][j] = (i + j) % n + 1; // Единичку добавляем, т.к. в массиве нумерация происходит с 0
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << L[i][j] << '\t';
		}
		cout << '\n';
	}

}

// Задание - Путем перестановки элементов квадратной вещественной матрицы добиться того, чтобы ее максимальный элемент находился в левом верхнем углу,
// следующий по величине - в позиции (2, 2), следующий - в позиции (3, 3) и т. д., заполнив таким образом всю главную диагональ.

void ex_3() { // Н
	const int n = 3;
	float F[n][n];

	cout << "Введите массив: " << endl; // Блок ввода
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> F[i][j];
		}
		cout << "\n";
	}

	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << F[i][j] << '\t';
		}
		cout << '\n';
	}
	
	for (int diag = 0; diag < n; ++diag) {
		int maxRow = diag, maxCol = diag;
		for (int i = diag; i < n; ++i) {
			for (int j = diag; j < n; ++j) {
				if (F[i][j] > F[maxRow][maxCol] && F[i][j] != F[diag][diag]) {
					maxRow = i;
					maxCol = j;
					swap(F[diag][diag], F[maxRow][maxCol]);
				}
			}
		}
	}

	cout << "Результат: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << F[i][j] << '\t';
		}
		cout << '\n';
	}
}