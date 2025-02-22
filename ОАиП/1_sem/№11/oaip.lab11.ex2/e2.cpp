// Задача - Инвертировать n битов в числе А влево от позиции p.
#include <iostream>
#include <stdio.h>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	unsigned int A;
	int n, p;
	cout << "Введите А: "; cin >> A;
	cout << "Введите n: "; cin >> n;
	cout << "Введите p: "; cin >> p;
	_itoa_s(A,tmp,2);
	cout << "Двоичное представления числа: " << tmp << endl;
	unsigned int mask = (1 << n) - 1;
	mask <<= p;
	_itoa_s(A ^ mask, tmp, 2); // Инвертировали все биты
	cout << "Двоичное представление числа с " << n << " инвертированными битами от позиции " << p << ": " << tmp << endl;
}