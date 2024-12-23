#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "modules.h"
using namespace std;


int main() {

    setlocale(LC_CTYPE, "Russian_Russia.1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    int choice;


    printf("Ââåäèòå ñèìâîë: ");
    getline(cin, input);
    printf("####################################################################\n");
    printf("×òî äåëàåì ñ ñèìâîëîì?\n1 - Ðàçíèöà ìåæäó ñòðî÷íîé è ïðîïèñíîé áóêâîé àíãëèéñêîãî àëôàâèòà\n2 - Ðàçíèöà ìåæäó ñòðî÷íîé è ïðîïèñíîé áóêâîé ðóññêîãî àëôàâèòà\n3 - Êîä öèôðû\nÐåæèì ïðîãðàììû: ");
    cin >> choice;
    printf("####################################################################\n");


    switch (choice) {
        case 1: {

            for (int i = 0; i < input.length(); i++) {
                ñalculateForEnglishLetter(input[i]);
            }

            break;
        }
        case 2: {

            for (int i = 0; i < input.length(); i++) {
                ñalculateForRussianLetter(input[i]);
            }

            break;
        }
        case 3: {

            for (int i = 0; i < input.length(); i++) {
                ñonvertDigitToCharsetCode(input[i]);
            }

            break;
        }
        default: {
            cerr << "Îøèáêà! Òàêîãî âàðèàíòà íåò!\n";
            break;
        }
    }


    return 0;

}
    