#include <iostream>
#include <cmath>
// ���. 4
void main() {
	setlocale(LC_CTYPE, "rus");
	long long k, c = 0;
	std::cout << "������� ����������� ����� k: "; std::cin >> k;
	for (long long i = 0; i < k; i++) {
		c = pow(2, i);
		std::cout << c << " ";
	}
	std::cout << std::endl << k << "-� ����� ������������������: " << c;
}