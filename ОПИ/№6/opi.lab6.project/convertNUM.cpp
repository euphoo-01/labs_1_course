#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;

int number(char ch) {
    int zCode = static_cast<int>(ch);
    if (zCode < 48 || zCode > 57) {
        printf("������! ������� �����!\n");
        return 1;
    }
    else {
        printf("��� �����: %i\n", zCode);
        return 0;
    }
}