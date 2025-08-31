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
    printf("Что делаем с символом?\n1 - Разница между строчной и прописной буквой английского алфавита\n2 - Разница между строчной и прописной буквой русского алфавита\n3 - Код цифры\nРежим программы: ");
    cin >> choice;
    printf("####################################################################\n");
    cin.ignore();
    switch (choice) {
    case 1: {
        printf("Введите символ: ");
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            ENletter(input[i]);
        }
        break;
    }
    case 2: {
        printf("Введите символ: ");
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            RUletter(input[i]);
        }
        break;
    }
    case 3: {
        printf("Введите символ: ");
        getline(cin, input);
        for (int i = 0; i < input.length(); i++) {
            number(input[i]);
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
    