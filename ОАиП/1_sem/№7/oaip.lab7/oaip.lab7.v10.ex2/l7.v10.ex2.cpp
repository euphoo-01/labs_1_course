#include <iostream>
#include <stdio.h>
// �-10 �.2

int main() {
	setlocale(LC_CTYPE, "RUS");
	int sum = 0;
	for (int i = 5; i < 150; i+=5) {
			sum += i;
	}
	printf("����� ������������� ����� ������� 5, �� ������ 150: %i \n",sum);
	system("pause");
}