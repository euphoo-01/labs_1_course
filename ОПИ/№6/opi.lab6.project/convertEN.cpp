#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;

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
}
