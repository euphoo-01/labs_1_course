// 1.	������� 6 ��� ������ ����� �, ������� �� 2-��� n �����.
#include <stdio.h>
#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE,"Russian");
	char tmp[32];
	unsigned int A;
	int n = 2;
	cout << "������� �: "; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "�������� ������������� �����: " << tmp << endl;
	int mask = (1 << 6) - 1;
	_itoa_s((A >> n) & mask, tmp, 2);
	cout << "6 ��� �����, ������� �� 2-�� ����: " << tmp;
}