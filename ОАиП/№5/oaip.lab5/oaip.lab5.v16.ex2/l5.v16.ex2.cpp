#include <iostream>
// �-16 �.2
int main() {
	setlocale(LC_CTYPE, "rus");
	int c;
	std::cout << "������� ����� �� 0 �� 7: "; std::cin >> c;
	switch (c) {
	case 0: std::cout << std::endl << "����"; break;
	case 1: std::cout << std::endl << "����"; break;
	case 2: std::cout << std::endl << "���"; break;
	case 3: std::cout << std::endl << "���"; break;
	case 4: std::cout << std::endl << "������"; break;
	case 5: std::cout << std::endl << "����"; break;
	case 6: std::cout << std::endl << "�����"; break;
	case 7: std::cout << std::endl << "����"; break;
	default: std::cout << std::endl << "������! ������� ����� �� 0 �� 7!"; break;
	}
	return 0;
}