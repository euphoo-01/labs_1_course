#include <iostream>
#include <iomanip> 
#include <conio.h>
#include <windows.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char c, spc; spc = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(8) << setfill(spc) << spc;
	cout << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << c << endl;
	cout << setw(2) << setfill(spc) << spc;
	cout << setw(13) << setfill(c) << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << c << endl;
}


/*
Вариант 12
		#
        #
		#
  #############
		#
		#
		#

*/