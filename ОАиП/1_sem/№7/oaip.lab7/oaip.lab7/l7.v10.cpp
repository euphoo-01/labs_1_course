#include <cmath>
#include <stdio.h>
#include <iostream>
// Â-10 ç.1
int main() {
	double a = 1.055,
		x = 0.6,
		y, z;
	for (int n = 0; n <= 14; n = n + 2) {
		y = pow(cos(pow(x, 2)), 2) / abs(x);
		if (y < a * x * n) {
			z = abs(y);
			std::cout << "z = " << z << std::endl;
		}
		else if (y >= a * x * n) {
			z = sqrt(1 + exp((-1) * y));
			std::cout << "z = " << z << std::endl;

		}
	}
	return 0;
}