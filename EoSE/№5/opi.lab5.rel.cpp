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
    printf("Что делаем с символом?\n1 - Разница между строчной и прописной буквой английского алфавита\n2 - Разница между строчной и прописной буквой русского алфавита\n3 - Код цифры\nРежим программы: ");
    cin >> choice;
    printf("Введите символ: ");
    cin >> ch;
    printf("####################################################################\n");
    switch(choice){
        case 1:{
            while (ch != EOF) {
                printf("Введите символ: ");
                cin >> ch;
                ENletter(ch);
            }
            break;
        }
        case 2: {
            while (ch != EOF) {
                printf("Введите символ: ");
                cin >> ch;
                RUletter(ch);
            }
            break;
        }
        case 3: {
            while (ch != EOF) {
                printf("Введите символ: ");
                cin >> ch;
                number(ch);
            }
            break;
        }
        default: {
            cerr << "Ошибка! Такого варианта нет!\n";
            break;
        }
    }
    return 0;
}

int ENletter(char ch) {
        int xCode = static_cast<int>(ch);
    if (xCode < 65 || (xCode > 90 && xCode < 97) || xCode>122) {
        cerr << "Ошибка! Введите символ английского алфавита!\n";
        return 1;
    }
    else {
        int xUpper = static_cast<int>(toupper(ch)),
            xLower = static_cast<int>(tolower(ch));
        printf("Разница кодов символа английского алфавита: %i\n", xLower - xUpper);
        return 0;
    }
    return 0;
};

int RUletter(char ch) {
        int yCode = static_cast<int>(ch);
    if (yCode < 192 || yCode > 255) {
        cerr << "Ошибка! Введите символ русского алфавита!\n";
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
        printf("Разница кодов символа русского алфавита: %i\n", yLower - yUpper);
        return 0;
    }
};

int number(char ch) {
    int zCode = static_cast<int>(ch);
    if (zCode < 48 || zCode > 57) {
        return 1;
    }
    else {
        printf("Код цифры: %i\n", zCode);
        return 0;
    }
};


