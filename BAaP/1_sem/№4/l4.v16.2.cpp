#include <iostream>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	float srV1, srV2, srV3, srV4, srV5, S, t1, t2, t3, t4, t5;
	cout << "–азмер 1 отрезка? (м) ";
	cin >> S;
	cout << "(м/с) —редн€€ скорость на участке 1: ";
	cin >> srV1;
	t1 = S/srV1;
	cout << endl << "(м/с) —редн€€ скорость на участке 2: ";
	cin >> srV2;
	t2 = S/srV2;
	cout << endl << "(м/с) —редн€€ скорость на участке 3: ";
	cin >> srV3;
	t3 = S/srV3;
	cout << endl << "(м/с) —редн€€ скорость на участке 4: ";
	cin >> srV4;
	t4 = S/srV4;
	cout << endl << "(м/с) —редн€€ скорость на участке 5: ";
	cin >> srV5;
	t5 = S/srV5;
	cout << endl << "(м/с) —редн€€ скорость на всех участках: " << 5 * S / (t1 + t2 + t3 + t4 + t5);
}