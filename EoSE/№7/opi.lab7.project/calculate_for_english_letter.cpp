#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;


int сalculateForEnglishLetter(char ch) {

    int letterCode = static_cast<int>(ch);

   
    if (ch == ' ') {

    }
    else if (letterCode < 65 || (letterCode > 90 && letterCode < 97) || letterCode>122) {        
        cerr << "Ошибка! Символ " << ch << " не является символом английского алфавита!\n";
        return 1;
    }
    else {    
        int upperLetterCode = static_cast<int>(toupper(ch)),
            lowerLetterCode = static_cast<int>(tolower(ch));
        
        printf("Разница кодов символа \"%c\" английского алфавита: %i\n", ch, lowerLetterCode - upperLetterCode);
        return 0;
    }


    return 1;

}
