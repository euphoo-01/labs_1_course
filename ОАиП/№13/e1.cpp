#include <iostream>
#include <string>
using namespace std;

//1. Написать программу, которая записывает строку в обратном порядке.
int main() {
	system("chcp 1251");
	char s[256] = {};
	char sInverted[256] = {};
	cout << "Введите строку: ";
	gets_s(s);
	s[strlen(s)] = '\0';
	
	for (int i = 0; i < strlen(s); i++) {
		sInverted[i] = s[(strlen(s) - 1) - i];
	}

	cout << "Инвертированная строка: " << sInverted;
	return 0;
}