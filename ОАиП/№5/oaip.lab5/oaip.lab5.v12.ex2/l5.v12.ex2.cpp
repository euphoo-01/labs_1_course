#include <iostream>
// �-12 �.2
int main() {
	setlocale(LC_CTYPE, "rus");
	int n, a, b;
	std::cout << "������� ����������� 2-� ������� ����� n: "; std::cin >> n;
	if (n > 9 && n < 100) {
		a = n / 10;
		b = n - a * 10;
		if ((a == 1 && b == 9) || (a == 9 && b == 1)) {
			std::cout << std::endl << "����� �������� ����� ���� 9 � 1";
		}
		else if (a == 1 || b == 1) {
			std::cout << std::endl << "����� �������� ����� ���� 1";
		}
		else if (a == 9 || b == 9) {
			std::cout << std::endl << "����� �������� ����� ���� 9";
		}
		else {
			std::cout << std::endl << "����� �������� ����� ��� �� 1, �� 9";
		}
	}
	else {
		std::cout << std::endl << "������! ������� 2-� ������� �����!";
	}
	return 0;
}