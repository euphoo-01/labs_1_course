#include <iostream>
// з.1
void main() {
	setlocale(LC_CTYPE, "RUS");
	float p, q;
	int i = 1;
	std::cout << "На какую сумму торговая фирма реализовала товары в первый день? "; std::cin >> p;
	std::cout << "Какова финансовая цель компании? "; std::cin >> q;
	while(p<q){
		p = p + p * 0.03;
		i++;
	}
	std::cout << "Фирма достигла цели за " << i << " дней. Выручка в последний день составила: " << p;
}