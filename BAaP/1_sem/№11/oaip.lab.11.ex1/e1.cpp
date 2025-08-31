// 1.	Вывести 6 бит целого числа А, начиная со 2-ого n битов.
#include <stdio.h>
#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE,"Russian");
	char tmp[32];
	unsigned int A;
	int n = 2;
	cout << "Введите А: "; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Двоичное представление числа: " << tmp << endl;
	int mask = (1 << 6) - 1;
	_itoa_s((A >> n) & mask, tmp, 2);
	cout << "6 бит числа, начиная со 2-го бита: " << tmp;
}