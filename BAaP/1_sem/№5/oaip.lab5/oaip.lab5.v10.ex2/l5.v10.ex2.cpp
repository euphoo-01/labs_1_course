#include <iostream>
// В-10 з.2
int main() {
	setlocale(LC_CTYPE, "rus");
	int c3, a, b, c;
	std::cout << "Введите любое 3-х значное число: "; std::cin >> c3;
	a = c3 / 100;
	b = c3 / 10 - a * 10;
	c = c3 - b * 10 - a * 100;

	if (c3 > 99 && c3 < 1000) {
		if ((a + b + c) % 3 == 0) {
			std::cout << std::endl << "Число делится на 3.";
		}
		else if ((a + b + c) % 3 != 0) {
			std::cout << std::endl << "Число не делится на 3.";
		}
	}
	else {
		std::cout << std::endl << "Ошибка! Введите 3-х значное число!";
	}
	return 0;
}