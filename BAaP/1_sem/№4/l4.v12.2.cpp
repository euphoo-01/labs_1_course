#include <iostream>
using namespace std;
void main() {
	int a, b, c, chislo;
	setlocale(LC_CTYPE, "Russian");
	cout << "¬ведите трЄхзначное число: ";
	cin >> chislo;
	if (chislo < 100 || chislo > 999)
	{
		cout << "ќшибка! ¬ведите трЄхзначное число!";
	}
	else {
		a = chislo / 100;
		b = chislo / 10 - a * 10;
		c = chislo - b * 10 - a * 100;
		cout << endl << "–еверсное число: " << c << b << a;
	}

}