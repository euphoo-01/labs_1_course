// ������ - ������������� n ����� � ����� � ����� �� ������� p.
#include <iostream>
#include <stdio.h>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	unsigned int A;
	int n, p;
	cout << "������� �: "; cin >> A;
	cout << "������� n: "; cin >> n;
	cout << "������� p: "; cin >> p;
	_itoa_s(A,tmp,2);
	cout << "�������� ������������� �����: " << tmp << endl;
	unsigned int mask = (1 << n) - 1;
	mask <<= p;
	_itoa_s(A ^ mask, tmp, 2); // ������������� ��� ����
	cout << "�������� ������������� ����� � " << n << " ���������������� ������ �� ������� " << p << ": " << tmp << endl;
}