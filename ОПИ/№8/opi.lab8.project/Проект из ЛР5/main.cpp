#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

int ENletter(unsigned char ch);
int RUletter(unsigned char ch);
int number(unsigned char ch);

int main() {

    setlocale(LC_ALL, "Russian_Russia.1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string ch;
    int choice;
    printf("####################################################################\n");
    printf("��� ������ � ��������?\n1 - ������� ����� �������� � ��������� ������ ����������� ��������\n2 - ������� ����� �������� � ��������� ������ �������� ��������\n3 - ��� �����\n����� ���������: ");
    cin >> choice;
    printf("������� ������: ");
    cin >> ch;
    printf("####################################################################\n");
    switch (choice) {
    case 1: {
        for (size_t i = 0; i < ch.length(); i++) {
            ENletter(ch[i]);
        }
        break;
    }
    case 2: {
        for (size_t i = 0; i < ch.length(); i++) {
            RUletter(ch[i]);
        }
        break;
    }
    case 3: {
        for (size_t i = 0; i < ch.length(); i++) {
            number(ch[i]);
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

int ENletter(unsigned char ch) {
    int xCode = static_cast<int>(ch);
    if (xCode < 65 || (xCode > 90 && xCode < 97) || xCode>122) {
        cerr << "������! ������� ������ ����������� ��������!\n";
        return 1;
    }
    else {
        int xUpper = static_cast<int>(toupper(ch)),
            xLower = static_cast<int>(tolower(ch));
        printf("������� ����� ������� ����������� ��������: %i\n", xLower - xUpper);
        return 0;
    }
    return 0;
};

int RUletter(unsigned char ch) {
    int yCode = static_cast<int>(ch);
    if ((yCode < 192 || yCode > 255) && (yCode != 168 && yCode != 184)) {
        cerr << "������! ������� ������ �������� ��������!\n";
        return 1;
    }
    else {
        int yUpper = static_cast<int>(toupper(ch)),
            yLower = static_cast<int>(tolower(ch));
        printf("������� ����� ������� �������� ��������: %i\n", yLower - yUpper);
        return 0;
    }
};

int number(unsigned char ch) {
    int zCode = static_cast<int>(ch);
    if (zCode < 48 || zCode > 57) {
        return 1;
    }
    else {
        printf("��� �����: %i\n", zCode);
        return 0;
    }
};


