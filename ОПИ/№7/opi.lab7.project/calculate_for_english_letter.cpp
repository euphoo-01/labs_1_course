#include <stdio.h>
#include <iostream>
#include "modules.h"
using namespace std;


int �alculateForEnglishLetter(char ch) {

    int letterCode = static_cast<int>(ch);

   
    if (ch == ' ') {

    }
    else if (letterCode < 65 || (letterCode > 90 && letterCode < 97) || letterCode>122) {        
        cerr << "������! ������ " << ch << " �� �������� �������� ����������� ��������!\n";
        return 1;
    }
    else {    
        int upperLetterCode = static_cast<int>(toupper(ch)),
            lowerLetterCode = static_cast<int>(tolower(ch));
        
        printf("������� ����� ������� \"%c\" ����������� ��������: %i\n", ch, lowerLetterCode - upperLetterCode);
        return 0;
    }


    return 1;

}
