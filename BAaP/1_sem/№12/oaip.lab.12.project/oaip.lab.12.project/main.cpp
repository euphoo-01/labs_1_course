#include <iostream>
#include <ctime>
using namespace std;

bool isTrue(int* nowCell, int* B, int sizeB) { // Проверка на уникальность
	for (int i = 0; i < sizeB; i++) {
		if (*nowCell == *(B + i)) return false;
	}
	return true;
}

int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	int A[15]={}, B[15]={},
		max = 18,
		min = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++) { // Блок ввода
		*(A + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		*(B + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << *(A + i) << '\t' << *(B + i) << '\n';
	}

	int minArr = *A;

	cout << '\n';
	for (int i = 0; i < 15; i++) // Основные вычисления
		if (isTrue((A + i), B, 15))
			if (*(A + i) < minArr) minArr = *(A + i);

	// Блок вывода
	cout << "Минимальное число, которое есть в массиве А, но нет в массиве В: " << minArr << endl; 
	return 0;
}