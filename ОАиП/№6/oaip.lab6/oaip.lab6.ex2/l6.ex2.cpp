#include <iostream>
// з.2
void main() {
	setlocale(LC_CTYPE, "rus");
	int n, sum = 0;
	float p;
	std::cout << "¬ведите на сколько p% уцениваетс€ товар: "; std::cin >> p;
	std::cout << "¬ведите n лет: "; std::cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		sum = (sum+s)-(sum + s)*(p/100);
	}
	std::cout << "ќбща€ стоимость оборудовани€ за " << n << " лет составл€ет: " << sum;
	
}