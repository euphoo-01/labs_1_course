#include "stdafx.h"
#include "showMonth.h"
using namespace std;

string showMonth(int month) {
    switch (month) {
    case 1: return "������"; break;
    case 2: return "�������"; break;
    case 3: return "����"; break;
    case 4: return "������"; break;
    case 5: return "���"; break;
    case 6: return "����"; break;
    case 7: return "����"; break;
    case 8: return "������"; break;
    case 9: return "��������"; break;
    case 10: return "�������"; break;
    case 11: return "������"; break;
    case 12: return "�������"; break;
    default: throw invalid_argument("Invalid month!");
    }
}