#include "stdafx.h"
#include "detSerialNumber.h"
using namespace std;
int detSerialNumber(int day, int month, int* days_in_months)
{
    int serial_number = 0;
    for (int i = 0; i < month - 1 && month < 12; i++)
    {
        serial_number += days_in_months[i];
    }
    serial_number = serial_number + day;
    return serial_number;
}