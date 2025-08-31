#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;


int ñonvertDigitToCharsetCode(char ch) {

    int digitCode = static_cast<int>(ch);

    
    if (ch == ' ') {

    }
    else if (digitCode < 48 || digitCode > 57) {        
        cerr << "Îøèáêà! Ñèìâîë " << ch << " íå ÿâëÿåòñÿ öèôðîé!\n";
        return 1;    
    }
    else {     
        printf("Êîä öèôðû \"%c\": %i\n", ch, digitCode);
        return 0;    
    }

    return 1;

}