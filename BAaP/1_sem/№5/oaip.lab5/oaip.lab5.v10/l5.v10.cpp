#include <iostream>
// �-10 �.1
int main() {
	setlocale(LC_CTYPE, "rus");
	int n, m, k;
	std::cout << "������� m: "; std::cin >> m;
	std::cout << std::endl << "������� n: "; std::cin >> n;
	std::cout << std::endl << "������� k: "; std::cin >> k;

	if (m % 2 == 0 && n % 2 == 0 && k % 2 == 0) {
		std::cout << std::endl << "��� ����� ������";
	}
	else {
		std::cout << std::endl << "���� �������� �����";
	}
	
	return 0;
}
