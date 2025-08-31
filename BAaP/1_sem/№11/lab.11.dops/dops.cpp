#include <iostream>
#include <stdio.h>
using namespace std;

// Задача - Ввести целое число A. Инвертировать все биты с 4 по 8, включая эти биты. Вывести полученное число.
int v12e1() {
	int A;
	char temp[33];
	cout << "Введите А: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "Двоичное представление числа: " << temp << endl;
	unsigned int mask = (1 << 5) - 1;
	mask <<= 3;
	_itoa_s(A ^ mask, temp, 2);
	cout << "Результат: " << temp << endl;
	return 0;
}
// 2.	Установить в 0 n битов в числе А вправо от позиции p, заменить ими m битов числа В, начиная с по-зиции q.
int v12e2() {
	int A, p, n;
	char temp[33];
	cout << "Введите А: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "Двоичное представление числа: " << temp << endl;
	cout << "Введите p: "; cin >> p;
	cout << "Введите n: "; cin >> n;
	unsigned int mask = (1 << n) - 1;
	mask <<= (p - n);
	_itoa_s(A & ~mask, temp, 2);
	cout << "Число с установленными в 0 битами: " << temp << endl;
	int extracted = (A & mask) >> (p-n);
	int B, q;
	cout << "Введите B: "; cin >> B;
	_itoa_s(B, temp, 2);
	cout << "Двоичное представление числа: " << temp << endl;
	cout << "Введите q: "; cin >> q;
	int m = n;
	mask = (1 << m) - 1;
	mask <<= (q-m);
	_itoa_s((B & ~mask), temp, 2);
	cout << "Результат: " << temp << endl;
	return 0;
}
// 1.	Ввести целое число A и посчитать, сколько единиц в числе с 5 по 10 бит, включая эти биты.
int v14e1() {
	int A;
	char temp[33];
	cout << "Введите А: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "Число А в 2-ном коде" << temp;
	int mask = ((1 << (11 - 5)) - 1) >> 4;
	int bits = (A & mask) >> 4;
	int count = 0;
	while (bits) {
		count += bits & 1;
		bits >>= 1;
	}
	_itoa_s((A & mask) >> 5, temp, 2);
	cout << endl << count;
	return 0;
}
// 2.	Извлечь 3 бита числа А, начиная с позиции n по счету справа, и вставить в число В, начиная с пози-ции m.
int v14e2() {
	int A, B, n, m;
	char temp[33];
	cout << "Введите А: "; cin >> A;
	cout << "Введите B: "; cin >> B;
	cout << "Введите n: "; cin >> n;
	cout << "Введите m: "; cin >> m;
	unsigned int mask = (1 << 3) - 1;
	int bits = (A >> n) & mask;
	mask = ~((1 << 3) - 1 << m);
	B = B & mask;
	B = B | (bits << m);
	_itoa_s(A, temp, 2);
	cout << "Число А в 2-ном коде: " << temp << endl;
	_itoa_s(B & mask, temp, 2);
	cout << "Число B в 2-ном коде:" << temp << endl;
	_itoa_s(B, temp, 2);
	cout << "Результат: " << temp << endl;
	return 0;
}
// 1.	Ввести целое число A. Извлечь 3 бита числа A, начиная со второго по счету справа, и вставить их в число B, 
// начиная с первого бита по счету справа.
int v16e1() {
	int A, B;
	char temp[33];
	cout << "Введите A: "; cin >> A;
	cout << "Введите B: "; cin >> B;
	unsigned int mask = (1 << 4) - 1;
	int extracted = (A >> 1) & mask;
	_itoa_s(A, temp, 2);
	cout << "Число А в 2-ном коде: " << temp << endl;
	_itoa_s(B, temp, 2);
	cout << "Число В в 2-ном коде: " << temp << endl;
	_itoa_s((B & ~mask) | extracted, temp, 2);
	cout << "Результат: " << temp << endl;
	return 0;
}
//2.	Установить в 1 два бита числа А, начиная с четвертого по счету справа.
int v16e2() {
	int A;
	char temp[33];
	cout << "Введите А: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "Число А в 2-ном коде: " << temp << endl;
	unsigned int mask = (1 << 2) - 1;
	mask <<= 3;
	_itoa_s(A | mask, temp, 2);
	cout << "Результат: " << temp << endl;
	return 0;
}
int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	//v12e1();
	//v12e2();
	//v14e1();
	//v14e2();
	//v16e1();
	v16e2();
	return 0;
}