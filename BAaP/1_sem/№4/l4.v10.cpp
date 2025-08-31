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
	cout << setw(7) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(5) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c;
	cout << setw(4) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(4) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c;
	cout << setw(6) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(4) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c;
	cout << setw(6) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c << endl; cout << setw(4) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c;
	cout << setw(6) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(5) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c;
	cout << setw(4) << setfill(spc) << spc;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(7) << setfill(spc) << spc;
	cout << setw(4) << setfill(c) << c << endl;

}


/*
		
       ####
     ##    ##
    ##      ##
    ##      ##
	##      ##
	 ##    ##
	   ####
	    
		
*/