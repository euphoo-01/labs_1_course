#include <iostream>
using namespace std;

void first() {
	int x1, x2, x3, sum;
	cout << "Введите х1: "; cin >> x1;
	cout << "Введите x2: ";  cin >> x2;
	cout << "Введите x3: "; cin >> x3;
	sum = (x1 % 5 > 0 ? 0 : x1) + (x2 % 5 > 0 ? 0 : x2) + (x3 % 5 > 0 ? 0 : x3);
	sum > 0 ? cout << "Сумма = " << sum : cout << "Error!";
}
void third() {
	int p, q, r, s, a, b;
	cout << "Размер участка a: "; cin >> a;
	cout << "Размер участка b: "; cin >> b;
	cout << "Размер дома 1 p: "; cin >> p;
	cout << "Размер дома 1 q: "; cin >> q;
	cout << "Размер дома 2 r: "; cin >> r;
	cout << "Размер дома 2 s: "; cin >> s;
	if (p + r <= a && q + s <= b) {
		cout << "Дома можно разместить на участке";
	}
	else {
		cout << "Дома нельзя разместить на участке";
	}
}
void fourth() {
	int r, p, q, r2;
	cout << "Введите радиус шара: "; cin >> r;
	cout << "Введите 1 диагональ ромба: "; cin >> p;
	cout << "Введите 2 диагональ ромба: "; cin >> q;
	r2 = p * q * (sqrt(pow(p, 2) + pow(q, 2)));
	if (r <= r2) {
		cout << "Шар пройдет.";
	}
	else {
		cout << "Шар не пройдет.";
	}

}
int main() {
	setlocale(LC_ALL, "RUS");
	fourth();
	return 0;
}
