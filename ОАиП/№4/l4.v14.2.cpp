#include <iostream>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;
	cout << "����� ���� ��������: ";
	cin >> a;
	cout << endl << "����� ���� �����: ";
	cin >> b;
	cout << endl << "����� ���� ���������: ";
	cin >> c;
	cout << "����� ������� �����: " << a * 50 + b * 100 + c * 200;
}