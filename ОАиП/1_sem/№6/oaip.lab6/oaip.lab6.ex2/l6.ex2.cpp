#include <iostream>
// �.2
void main() {
	setlocale(LC_CTYPE, "rus");
	int n, sum = 0;
	float p;
	std::cout << "������� �� ������� p% ����������� �����: "; std::cin >> p;
	std::cout << "������� n ���: "; std::cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		sum = (sum+s)-(sum + s)*(p/100);
	}
	std::cout << "����� ��������� ������������ �� " << n << " ��� ����������: " << sum;
	
}