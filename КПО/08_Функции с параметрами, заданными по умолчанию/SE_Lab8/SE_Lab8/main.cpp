#include <iostream>
#include <locale>

using namespace std;

int defaultparm(int a, int b, int c, int d = 1, int e = 1) {
	cout << "Функция выполняется..." << endl
		<< "Значения переданных переменных: " << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << endl;
	return (a + b + c + d + e) / 5;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int a, b, c;
	cout << "Введите a, b, c: "; cin >> a >> b >> c;
	cout << "Среднее арифметическое: " << defaultparm(a, b, c);
	return 0;
}