#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;

int number(char ch) {
    int zCode = static_cast<int>(ch);
    if (zCode < 48 || zCode > 57) {
        printf("Ошибка! Введите цифру!\n");
        return 1;
    }
    else {
        printf("Код цифры: %i\n", zCode);
        return 0;
    }
}