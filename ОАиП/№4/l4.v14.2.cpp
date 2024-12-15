#include <iostream>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;
	cout << "Игрок сбил самолётов: ";
	cin >> a;
	cout << endl << "Игрок сбил ракет: ";
	cin >> b;
	cout << endl << "Игрок сбил спутников: ";
	cin >> c;
	cout << "Игрок получил очков: " << a * 50 + b * 100 + c * 200;
}