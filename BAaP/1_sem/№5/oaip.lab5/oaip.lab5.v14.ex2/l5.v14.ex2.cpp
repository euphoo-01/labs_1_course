#include <iostream>
//�-14 �.2
int main() {
	setlocale(LC_CTYPE, "rus");
	double a, b, c, d;
	std::cout << "������� ����� a: "; std::cin >> a;
	std::cout << std::endl << "������� ����� b: "; std::cin >> b;
	std::cout << std::endl << "������� ����� c: "; std::cin >> c;

	if (a > b && a > c) {
		d = a;
	}
	else if (b > a && b > c) {
		d = b;
	}
	else if (c > a && c > b) {
		d = c;
	}
	std::cout << std::endl << "d = " << d;
	return 0;
}