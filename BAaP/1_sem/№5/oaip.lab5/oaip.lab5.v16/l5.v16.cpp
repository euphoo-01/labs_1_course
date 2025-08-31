#include <iostream>
// В-16 з.1
int main() {
	setlocale(LC_CTYPE, "rus");
	int a, b, c;
	std::cout << "Введите a: "; std::cin >> a;
	std::cout << std::endl << "Введите b: "; std::cin >> b;
	std::cout << std::endl << "Введите c: "; std::cin >> c;
	
	if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
		std::cout << std::endl << "Среди чисел есть хотя бы одно нечетное";
	}
	else {
		std::cout << std::endl << "Все числа четные";
	}

	return 0;
}