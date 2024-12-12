#include <iostream>
#include <stdio.h>
using namespace std;

// ������ - ������ ����� ����� A. ������������� ��� ���� � 4 �� 8, ������� ��� ����. ������� ���������� �����.
int v12e1() {
	int A;
	char temp[33];
	cout << "������� �: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "�������� ������������� �����: " << temp << endl;
	unsigned int mask = (1 << 5) - 1;
	mask <<= 3;
	_itoa_s(A ^ mask, temp, 2);
	cout << "���������: " << temp << endl;
	return 0;
}
// 2.	���������� � 0 n ����� � ����� � ������ �� ������� p, �������� ��� m ����� ����� �, ������� � ��-����� q.
int v12e2() {
	int A, p, n;
	char temp[33];
	cout << "������� �: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "�������� ������������� �����: " << temp << endl;
	cout << "������� p: "; cin >> p;
	cout << "������� n: "; cin >> n;
	unsigned int mask = (1 << n) - 1;
	mask <<= (p - n);
	_itoa_s(A & ~mask, temp, 2);
	cout << "����� � �������������� � 0 ������: " << temp << endl;
	int extracted = (A & mask) >> (p-n);
	int B, q;
	cout << "������� B: "; cin >> B;
	_itoa_s(B, temp, 2);
	cout << "�������� ������������� �����: " << temp << endl;
	cout << "������� q: "; cin >> q;
	int m = n;
	mask = (1 << m) - 1;
	mask <<= (q-m);
	_itoa_s((B & ~mask), temp, 2);
	cout << "���������: " << temp << endl;
	return 0;
}
// 1.	������ ����� ����� A � ���������, ������� ������ � ����� � 5 �� 10 ���, ������� ��� ����.
int v14e1() {
	int A;
	char temp[33];
	cout << "������� �: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "����� � � 2-��� ����" << temp;
	int mask = ((1 << (11 - 5)) - 1) >> 4;
	int bits = (A & mask) >> 4;
	int count = 0;
	while (bits) {
		count += bits & 1;
		bits >>= 1;
	}
	_itoa_s((A & mask) >> 5, temp, 2);
	cout << endl << count;
	return 0;
}
// 2.	������� 3 ���� ����� �, ������� � ������� n �� ����� ������, � �������� � ����� �, ������� � ����-��� m.
int v14e2() {
	int A, B, n, m;
	char temp[33];
	cout << "������� �: "; cin >> A;
	cout << "������� B: "; cin >> B;
	cout << "������� n: "; cin >> n;
	cout << "������� m: "; cin >> m;
	unsigned int mask = (1 << 3) - 1;
	int bits = (A >> n) & mask;
	mask = ~((1 << 3) - 1 << m);
	B = B & mask;
	B = B | (bits << m);
	_itoa_s(A, temp, 2);
	cout << "����� � � 2-��� ����: " << temp << endl;
	_itoa_s(B & mask, temp, 2);
	cout << "����� B � 2-��� ����:" << temp << endl;
	_itoa_s(B, temp, 2);
	cout << "���������: " << temp << endl;
	return 0;
}
// 1.	������ ����� ����� A. ������� 3 ���� ����� A, ������� �� ������� �� ����� ������, � �������� �� � ����� B, 
// ������� � ������� ���� �� ����� ������.
int v16e1() {
	int A, B;
	char temp[33];
	cout << "������� A: "; cin >> A;
	cout << "������� B: "; cin >> B;
	unsigned int mask = (1 << 4) - 1;
	int extracted = (A >> 1) & mask;
	_itoa_s(A, temp, 2);
	cout << "����� � � 2-��� ����: " << temp << endl;
	_itoa_s(B, temp, 2);
	cout << "����� � � 2-��� ����: " << temp << endl;
	_itoa_s((B & ~mask) | extracted, temp, 2);
	cout << "���������: " << temp << endl;
	return 0;
}
//2.	���������� � 1 ��� ���� ����� �, ������� � ���������� �� ����� ������.
int v16e2() {
	int A;
	char temp[33];
	cout << "������� �: "; cin >> A;
	_itoa_s(A, temp, 2);
	cout << "����� � � 2-��� ����: " << temp << endl;
	unsigned int mask = (1 << 2) - 1;
	mask <<= 3;
	_itoa_s(A | mask, temp, 2);
	cout << "���������: " << temp << endl;
	return 0;
}
int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	//v12e1();
	//v12e2();
	//v14e1();
	//v14e2();
	//v16e1();
	v16e2();
	return 0;
}