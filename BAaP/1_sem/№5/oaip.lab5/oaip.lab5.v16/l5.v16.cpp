#include <iostream>
// �-16 �.1
int main() {
	setlocale(LC_CTYPE, "rus");
	int a, b, c;
	std::cout << "������� a: "; std::cin >> a;
	std::cout << std::endl << "������� b: "; std::cin >> b;
	std::cout << std::endl << "������� c: "; std::cin >> c;
	
	if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
		std::cout << std::endl << "����� ����� ���� ���� �� ���� ��������";
	}
	else {
		std::cout << std::endl << "��� ����� ������";
	}

	return 0;
}