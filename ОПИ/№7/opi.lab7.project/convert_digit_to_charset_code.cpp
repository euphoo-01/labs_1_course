#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;


int �onvertDigitToCharsetCode(char ch) {

    int digitCode = static_cast<int>(ch);

    
    if (ch == ' ') {

    }
    else if (digitCode < 48 || digitCode > 57) {        
        cerr << "������! ������ " << ch << " �� �������� ������!\n";
        return 1;    
    }
    else {     
        printf("��� ����� \"%c\": %i\n", ch, digitCode);
        return 0;    
    }

    return 1;

}