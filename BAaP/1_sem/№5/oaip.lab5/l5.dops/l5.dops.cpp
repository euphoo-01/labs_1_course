#include <iostream>
using namespace std;

void first() {
	int x1, x2, x3, sum;
	cout << "������� �1: "; cin >> x1;
	cout << "������� x2: ";  cin >> x2;
	cout << "������� x3: "; cin >> x3;
	sum = (x1 % 5 > 0 ? 0 : x1) + (x2 % 5 > 0 ? 0 : x2) + (x3 % 5 > 0 ? 0 : x3);
	sum > 0 ? cout << "����� = " << sum : cout << "Error!";
}
void third() {
	int p, q, r, s, a, b;
	cout << "������ ������� a: "; cin >> a;
	cout << "������ ������� b: "; cin >> b;
	cout << "������ ���� 1 p: "; cin >> p;
	cout << "������ ���� 1 q: "; cin >> q;
	cout << "������ ���� 2 r: "; cin >> r;
	cout << "������ ���� 2 s: "; cin >> s;
	if (p + r <= a && q + s <= b) {
		cout << "���� ����� ���������� �� �������";
	}
	else {
		cout << "���� ������ ���������� �� �������";
	}
}
void fourth() {
	int r, p, q, r2;
	cout << "������� ������ ����: "; cin >> r;
	cout << "������� 1 ��������� �����: "; cin >> p;
	cout << "������� 2 ��������� �����: "; cin >> q;
	r2 = p * q * (sqrt(pow(p, 2) + pow(q, 2)));
	if (r <= r2) {
		cout << "��� �������.";
	}
	else {
		cout << "��� �� �������.";
	}

}
int main() {
	setlocale(LC_ALL, "RUS");
	fourth();
	return 0;
}
