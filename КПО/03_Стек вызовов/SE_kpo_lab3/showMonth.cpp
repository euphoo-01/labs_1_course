#include "stdafx.h"
#include "showMonth.h"
using namespace std;

string showMonth(int month) {
    switch (month) {
    case 1: return "Январь"; break;
    case 2: return "Февраль"; break;
    case 3: return "Март"; break;
    case 4: return "Апрель"; break;
    case 5: return "Май"; break;
    case 6: return "Июнь"; break;
    case 7: return "Июль"; break;
    case 8: return "Август"; break;
    case 9: return "Сентябрь"; break;
    case 10: return "Октябрь"; break;
    case 11: return "Ноябрь"; break;
    case 12: return "Декабрь"; break;
    default: throw invalid_argument("Invalid month!");
    }
}