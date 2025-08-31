#include <windows.h>
#include <iostream>
using namespace std;

int ENletter(char ch);
int RUletter(unsigned char ch);
int number(char ch);

int main(){
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
    switch(choice){
        case 1:{
            while (ch != EOF) {
                printf("������� ������: ");
                cin >> ch;
                ENletter(ch);
            }
            break;
        }
        case 2: {
            while (ch != EOF) {
                printf("������� ������: ");
                cin >> ch;
                RUletter(ch);
            }
            break;
        }
        case 3: {
            while (ch != EOF) {
                printf("������� ������: ");
                cin >> ch;
                number(ch);
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

int ENletter(char ch) {
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

int RUletter(char ch) {
        int yCode = static_cast<int>(ch);
    if (yCode < 192 || yCode > 255) {
        cerr << "������! ������� ������ �������� ��������!\n";
        return 1;
    }
    else {
        int yUpper, yLower;
        if (yCode > 223) {
            yUpper = yCode - 32;
            yLower = yCode;
        }
        else if (yCode > 191 && yCode < 224) {
            yUpper = yCode;
            yLower = yCode + 32;
        }
        printf("������� ����� ������� �������� ��������: %i\n", yLower - yUpper);
        return 0;
    }
};

int number(char ch) {
    int zCode = static_cast<int>(ch);
    if (zCode < 48 || zCode > 57) {
        return 1;
    }
    else {
        printf("��� �����: %i\n", zCode);
        return 0;
    }
};


