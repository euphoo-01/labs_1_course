#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "modules.h"
using namespace std;

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "RUSSIAN");
	int n = 0;
	cout << "Введите количество элементов в списке: "; cin >> n; 
	float* price = new float[n];
	string* names = new string[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите имя товара: "; cin >> names[i]; 
		cout << "Введите цену товара: "; cin >> price[i];
		if (proverka(price[i]))  cout << names[i] << endl << price[i] << endl;
		else goto cleanup;
	}
	cleanup:
	delete []price;
	delete []names;
	return 0;
}