#include <iostream>
using namespace std;
void main() {
	// Вариант 10
	float z = 1.7;
	int a = 4 * pow(10, -8), m = 3, n = 3;
	float y = (z + log(z)) / (exp(-3) + sqrt(a));
	float s = (1 + m * n) / log(1 + z);
	cout << "y=" << y << endl;
	cout << "s=" << s;
}