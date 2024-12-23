#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "modules.h"
using namespace std;


int main() {

    setlocale(LC_CTYPE, "Russian_Russia.1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    int choice;


    printf("������� ������: ");
    getline(cin, input);
    printf("####################################################################\n");
    printf("��� ������ � ��������?\n1 - ������� ����� �������� � ��������� ������ ����������� ��������\n2 - ������� ����� �������� � ��������� ������ �������� ��������\n3 - ��� �����\n����� ���������: ");
    cin >> choice;
    printf("####################################################################\n");


    switch (choice) {
        case 1: {

            for (int i = 0; i < input.length(); i++) {
                �alculateForEnglishLetter(input[i]);
            }

            break;
        }
        case 2: {

            for (int i = 0; i < input.length(); i++) {
                �alculateForRussianLetter(input[i]);
            }

            break;
        }
        case 3: {

            for (int i = 0; i < input.length(); i++) {
                �onvertDigitToCharsetCode(input[i]);
            }

            break;
        }
        default: {
            cerr << "������! ������ �������� ���!\n";
            break;
        }
    }


    return 0;

}
    