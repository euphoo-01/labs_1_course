#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;

int RUletter(unsigned char ch) {
    int yCode = static_cast<int>(ch);
    if (yCode < 192 || yCode > 255) {
        cerr << "Ошибка! Введите символ русского алфавита!\n";
        return 1;
    }
    else {
        int
            yUpper = static_cast<int>(toupper(ch)),
            yLower = static_cast<int>(tolower(ch));
        printf("Разница кодов символа русского алфавита: %i\n", yLower - yUpper);
        return 0;
    }
}

