#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;


int сalculateForRussianLetter(unsigned char ch) {

    int letterCode = static_cast<int>(ch);


    if (ch == ' ') {
        
    }
    else if ((letterCode < 192 || letterCode > 255) && (letterCode != 168 && letterCode != 184)) {       
        cerr << "Ошибка! Символ " << ch << " не является символом русского алфавита!\n";
        return 1;    
    }
    else {    
        int upperLetterCode = static_cast<int>(toupper(ch));
        int lowerLetterCode = static_cast<int>(tolower(ch));

        printf("Разница кодов символа \"%c\" русского алфавита: %i\n", ch, lowerLetterCode - upperLetterCode);
        return 0;    
    }

    return 1;

}

