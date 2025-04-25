#include <iostream>
#include <Windows.h>
#include <locale>
#include "Call.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, c, d;
	cout << "Введите a, b, c: "; cin >> a >> b >> c;
	cout << "_cdecl: " << Call::funcA(a, b, c) << endl;
	system("pause");

	cout << "Введите a, b, c: "; cin >> a >> b >> c;
	cout << "_cstd: " << Call::funcB(&a, b, c) << endl;
	system("pause");

	cout << "Введите a, b, c, d: "; cin >> a >> b >> c >> d;
	cout << "_cfst: " << Call::funcC(a, b, c, d) << endl;
	system("pause");
	return 0;
}
