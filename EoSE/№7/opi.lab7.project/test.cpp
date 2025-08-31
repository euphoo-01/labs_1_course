#include <iostream>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	unsigned char ch;
	cin >> ch;
	cout <<  static_cast<int>(ch);
	/*int lower = static_cast<int>(tolower(ch));
	cout << lower - upper;*/
	return 0;
}