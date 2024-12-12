#include <iostream>
using namespace std;

//void main() {
//	// Вариант 15
//	float a = 1.75, b = 4.5 * pow(10, -4), y, r;
//	y = a * exp(-2*b) - sqrt(1 + a);
//	r = log(1 + 20*b) / (1 + a);
//	cout << "y=" << y << endl;
//	cout << "r=" << r;
//}

void main() {
	setlocale(LC_CTYPE, "Russian");
	int x, a, b, c, d;
	cin >> x;
	a = x / 1000;
	b = x / 100 - a * 10;
	c = x / 10 - (b * 10 + a * 100);
	d = x - (a * 1000 + b * 100 + c * 10);
	cout << "a= " << a << " b= " << b << " c= " << c << " d= " << d;
	if (a == b || b == c || c == d || b == d || c == a || d == a)
	{
		cout << " Есть одинаковые числа";
	}
	else {
		cout << " Одинаковых чисел нет";
	}
}