#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "modules.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    int choice;
    printf("####################################################################\n");
    printf("��� ������ � ��������?\n1 - ������� ����� �������� � ��������� ������ ����������� ��������\n2 - ������� ����� �������� � ��������� ������ �������� ��������\n3 - ��� �����\n����� ���������: ");
    cin >> choice;
    printf("####################################################################\n");
    cin.ignore();
    switch (choice) {
    case 1: {
        printf("������� ������: ");
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            ENletter(input[i]);
        }
        break;
    }
    case 2: {
        printf("������� ������: ");
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            RUletter(input[i]);
        }
        break;
    }
    case 3: {
        printf("������� ������: ");
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            number(input[i]);
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
    