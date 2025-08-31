#include <iostream>
using namespace std;

void main() {
	// Вариант 13
	float d = 0.5 * pow(10, -8), a=1.5, t,y;
	int c = 9;
	t = d * c + a * sqrt(c - 1);
	y = 0.5 * t / d + exp(a);
	cout << "t=" << t << endl;
	cout << "y=" << y;
}