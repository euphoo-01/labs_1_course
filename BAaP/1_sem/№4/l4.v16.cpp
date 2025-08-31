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
	cout << setw(10) << setfill(spc) << spc;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << setw(14) << setfill(c) << c << endl;
	cout << setw(6) << setfill(spc) << spc;
	cout << setw(18) << setfill(c) << c << endl;
	cout << setw(13) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(13) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(13) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(13) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(13) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;
}


/*
Вариант 14
          ##########
        ##############
      ##################
             ####
		     ####
			 ####
			 ####
		     ####
*/