#include <iostream>
// �-14 �.1
int main() {
	setlocale(LC_CTYPE, "rus");
	int y1, x2, y2, min;
	std::cout << "������� y1: "; std::cin >> y1;
	std::cout << std::endl << "������� x2: "; std::cin >> x2;
	std::cout << std::endl << "������� y2: "; std::cin >> y2;

	if (y1 + x2 * y2 < y1 + x2 + y2) {
		if (y1 + x2 * y2 < y2)
		{
			min = y1 + x2 * y2;
		}
		else if (y1 + x2 + y2 < y2) {
			min = y1 + x2 + y2;
		}
		else {
			min = y2;
		}
	}
	else if (y1 + x2 + y2 < y2) {
		min = y1 + x2 + y2;
	}
	else {
		min = y2;
	}
	std::cout << std::endl << "min(y1+x2y2,y1+x2+y2,y2)+5=" << min + 5;
	return 0;
}