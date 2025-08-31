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
	cout << setw(9) << setfill(spc) << spc;
	cout << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(7) << setfill(spc) << spc;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(6) << setfill(spc) << spc;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(5) << setfill(spc) << spc;
	cout << setw(9) << setfill(c) << c << endl;
	cout << setw(6) << setfill(spc) << spc;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(7) << setfill(spc) << spc;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(8) << setfill(spc) << spc;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(9) << setfill(spc) << spc;
	cout << c << endl;
}


/*
Вариант 14
         #
        ###
	   #####
	  #######
	 #########
	  #######
	   #####
	    ###
		 #
*/