#include <iostream>
#include <iomanip>
void main() {
	setlocale(LC_CTYPE, "Russian");
	int n, k, y, ost;
	std::cout << "������� ���������� ����� ";
	std::cin >> n;
	std::cout << std::endl << "������� ���������� ���������� ";
	std::cin >> k;
	y = n / k;
	ost = n % k;
	if (y==1) {
		std::cout << std::endl << "������� ��������� ��������� �� " << y << " ������" << std::endl;
	}
	else if (y < 5) {
		std::cout << std::endl << "������� ��������� ��������� �� " << y << " ������" << std::endl;
	}
	else {
		std::cout << std::endl << "������� ��������� ��������� �� " << y << " �����" << std::endl;
	}
	if (ost == 1) {
		std::cout << "������� � �������: " << ost << " ������" << std::endl;
	}
	else if (ost < 5) {
		std::cout << "������� � �������: " << ost << " ������" << std::endl;
	}
	else {
		std::cout << "������� � �������: " << ost << " �����" << std::endl;
	}
		
}