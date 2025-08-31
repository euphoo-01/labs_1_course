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

	defaultparm(5, 4, 3);
	defaultparm(5, 4, 3, 2, 1);
	return 0;
}