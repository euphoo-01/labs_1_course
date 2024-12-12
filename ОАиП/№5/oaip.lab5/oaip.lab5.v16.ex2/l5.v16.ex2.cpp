#include <iostream>
// В-16 з.2
int main() {
	setlocale(LC_CTYPE, "rus");
	int c;
	std::cout << "Введите число от 0 до 7: "; std::cin >> c;
	switch (c) {
	case 0: std::cout << std::endl << "Ноль"; break;
	case 1: std::cout << std::endl << "Один"; break;
	case 2: std::cout << std::endl << "Два"; break;
	case 3: std::cout << std::endl << "Три"; break;
	case 4: std::cout << std::endl << "Четыре"; break;
	case 5: std::cout << std::endl << "Пять"; break;
	case 6: std::cout << std::endl << "Шесть"; break;
	case 7: std::cout << std::endl << "Семь"; break;
	default: std::cout << std::endl << "Ошибка! Введите число от 0 до 7!"; break;
	}
	return 0;
}