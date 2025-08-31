#include <iostream>
// Вариант 3
using namespace std;

void main() {
	int i = -6;
	float x = 4.5, z = 1.5 * pow(10, -6), d, f;
	d = tan((-x) * i) / sqrt(x - z);
	f = sin(2*d) / d;
	cout << "d=" << d << endl;
	cout << "f=" << f;
}