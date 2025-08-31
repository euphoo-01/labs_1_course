#include <iostream>
#include <Windows.h>
#include <locale>
#include "Call.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Call::cdecll(1, 2, 3);

	int a = 5;
	Call::cstd(a, 2, 3);

	Call::cfst(1, 2, 3, 4);
	system("pause");
	return 0;
}
