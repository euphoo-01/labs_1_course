#include <iostream>
// �.1
void main() {
	setlocale(LC_CTYPE, "RUS");
	float p, q;
	int i = 1;
	std::cout << "�� ����� ����� �������� ����� ����������� ������ � ������ ����? "; std::cin >> p;
	std::cout << "������ ���������� ���� ��������? "; std::cin >> q;
	while(p<q){
		p = p + p * 0.03;
		i++;
	}
	std::cout << "����� �������� ���� �� " << i << " ����. ������� � ��������� ���� ���������: " << p;
}