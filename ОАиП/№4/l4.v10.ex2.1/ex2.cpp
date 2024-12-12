#include <iostream>
#include <iomanip>
void main() {
	setlocale(LC_CTYPE, "Russian");
	int n, k, y, ost;
	std::cout << "¬ведите количество €блок ";
	std::cin >> n;
	std::cout << std::endl << "¬ведите количество школьников ";
	std::cin >> k;
	y = n / k;
	ost = n % k;
	if (y==1) {
		std::cout << std::endl << " аждому школьнику досталось по " << y << " €блоку" << std::endl;
	}
	else if (y < 5) {
		std::cout << std::endl << " аждому школьнику досталось по " << y << " €блока" << std::endl;
	}
	else {
		std::cout << std::endl << " аждому школьнику досталось по " << y << " €блок" << std::endl;
	}
	if (ost == 1) {
		std::cout << "ќстаток в корзине: " << ost << " €блоко" << std::endl;
	}
	else if (ost < 5) {
		std::cout << "ќстаток в корзине: " << ost << " €блока" << std::endl;
	}
	else {
		std::cout << "ќстаток в корзине: " << ost << " €блок" << std::endl;
	}
		
}