#include <iostream>
#include <cmath>
// В-10
void main() {
	setlocale(LC_CTYPE, "rus");
	float k;
	std::cout << "Цикл for: " << std::endl;
	for (int i = 0; i < 3;i++) {
		std::cout << std::endl << "Введите k: "; std::cin >> k;
		float
			s = 7.4,
			f = 3.2 * pow(10, 4),
			m = 10,
			y = s / log(5.2 * f) / (exp((-1) * s) + 2),
			v = (1 + m * y - m * k) / log(y);
		std::cout << "v = " << v << " k = " << k << std::endl;
	}
	std::cout << std::endl << "Цикл while: " << std::endl;
	k = 0;
	while (k <= 4) {
		float
			s = 7.4,
			f = 3.2 * pow(10, 4),
			m = 10,
			y = s / log(5.2 * f) / (exp((-1) * s) + 2),
			v = (1 + m * y - m * k) / log(y);
		std::cout << "v = " << v << " k = " << k << std::endl;
		k = k + 0.5;
	}
	std::cout << std::endl << "Двойной цикл for, do while: " << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << std::endl << "Введите k: "; std::cin >> k;
		float m = 0.3;
		do {
			float
				s = 7.4,
				f = 3.2 * pow(10, 4),
				y = s / log(5.2 * f) / (exp((-1) * s) + 2),
				v = (1 + m * y - m * k) / log(y);
			std::cout << "v = " << v << " k = " << k << " m = " << m << std::endl;
			m = m + 0.1;
		} while (m < 0.8);
	}
}