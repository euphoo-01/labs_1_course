#include <iostream>
// В-12 з.2
int main() {
	setlocale(LC_CTYPE, "rus");
	int n, a, b;
	std::cout << "Введите натуральное 2-х значное число n: "; std::cin >> n;
	if (n > 9 && n < 100) {
		a = n / 10;
		b = n - a * 10;
		if ((a == 1 && b == 9) || (a == 9 && b == 1)) {
			std::cout << std::endl << "Среди разрядов числа есть 9 и 1";
		}
		else if (a == 1 || b == 1) {
			std::cout << std::endl << "Среди разрядов числа есть 1";
		}
		else if (a == 9 || b == 9) {
			std::cout << std::endl << "Среди разрядов числа есть 9";
		}
		else {
			std::cout << std::endl << "Среди разрядов числа нет ни 1, ни 9";
		}
	}
	else {
		std::cout << std::endl << "Ошибка! Введите 2-х значное число!";
	}
	return 0;
}