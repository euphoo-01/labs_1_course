#include <iostream>
// В-12 з.1
int main() {
	setlocale(LC_CTYPE, "rus");
	double x1, y1, y2, max, min;
	std::cout << "Введите x1: "; std::cin >> x1;
	std::cout << std::endl << "Введите y1: "; std::cin >> y1;
	std::cout << std::endl << "Введите y2: "; std::cin >> y2;

	if (x1 + y1 > x1 * y1) {
		if (x1 + y1 > y1 * y2) {
			max = x1 + y1;
		}
		else if (x1 * y1 > y1 * y2) {
			max = x1 * y1;
		}
		else {
			max = y1 * y2;
		}
	}
	else if (x1 * y1 > y1 * y2) {
		max = x1 * y1;
	}
	else {
		max = y1 * y2;
	}

	if (x1 < y1) {
		if (x1 < y2) {
			min = x1;
		}
		else if (y1 < y2) {
			min = y1;
		}
		else {
			min = y2;
		}
	}
	else if (y1 < y2) {
		min = y1;
	}
	else {
		min = y2;
	}

	std::cout << std::endl << "max+min=" << max + min;
	return 0;
}