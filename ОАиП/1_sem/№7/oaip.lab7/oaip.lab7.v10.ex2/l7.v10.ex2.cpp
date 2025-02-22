#include <iostream>
#include <stdio.h>
// В-10 з.2

int main() {
	setlocale(LC_CTYPE, "RUS");
	int sum = 0;
	for (int i = 5; i < 150; i+=5) {
			sum += i;
	}
	printf("Сумма положительных чисел кратных 5, но меньше 150: %i \n",sum);
	system("pause");
}