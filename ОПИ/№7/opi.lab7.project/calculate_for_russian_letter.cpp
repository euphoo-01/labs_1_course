#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;


int �alculateForRussianLetter(unsigned char ch) {

    int letterCode = static_cast<int>(ch);


    if (ch == ' ') {
        
    }
    else if ((letterCode < 192 || letterCode > 255) && (letterCode != 168 && letterCode != 184)) {       
        cerr << "������! ������ " << ch << " �� �������� �������� �������� ��������!\n";
        return 1;    
    }
    else {    
        int upperLetterCode = static_cast<int>(toupper(ch));
        int lowerLetterCode = static_cast<int>(tolower(ch));

        printf("������� ����� ������� \"%c\" �������� ��������: %i\n", ch, lowerLetterCode - upperLetterCode);
        return 0;    
    }

    return 1;

}

