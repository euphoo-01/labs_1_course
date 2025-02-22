#include <iostream>
// В-10 з.1
int main() {
	setlocale(LC_CTYPE, "rus");
	int n, m, k;
	std::cout << "Введите m: "; std::cin >> m;
	std::cout << std::endl << "Введите n: "; std::cin >> n;
	std::cout << std::endl << "Введите k: "; std::cin >> k;

	if (m % 2 == 0 && n % 2 == 0 && k % 2 == 0) {
		std::cout << std::endl << "Все числа четные";
	}
	else {
		std::cout << std::endl << "Есть нечетные числа";
	}
	
	return 0;
}
