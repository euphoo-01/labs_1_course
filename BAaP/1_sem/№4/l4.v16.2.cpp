#include <iostream>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	float srV1, srV2, srV3, srV4, srV5, S, t1, t2, t3, t4, t5;
	cout << "������ 1 �������? (�) ";
	cin >> S;
	cout << "(�/�) ������� �������� �� ������� 1: ";
	cin >> srV1;
	t1 = S/srV1;
	cout << endl << "(�/�) ������� �������� �� ������� 2: ";
	cin >> srV2;
	t2 = S/srV2;
	cout << endl << "(�/�) ������� �������� �� ������� 3: ";
	cin >> srV3;
	t3 = S/srV3;
	cout << endl << "(�/�) ������� �������� �� ������� 4: ";
	cin >> srV4;
	t4 = S/srV4;
	cout << endl << "(�/�) ������� �������� �� ������� 5: ";
	cin >> srV5;
	t5 = S/srV5;
	cout << endl << "(�/�) ������� �������� �� ���� ��������: " << 5 * S / (t1 + t2 + t3 + t4 + t5);
}