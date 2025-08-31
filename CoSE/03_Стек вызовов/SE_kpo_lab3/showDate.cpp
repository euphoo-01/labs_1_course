#include "stdafx.h"
#include "showDate.h"
#include "showMonth.h"
using namespace std;

void showDate(int serial_num, int* days_in_months) {
    if (serial_num < 1 || serial_num > 366) {
        throw invalid_argument("Invalid day number. Please enter a value between 1 and 366.");
    }

    int month = 0;
    while (serial_num > days_in_months[month]) {
        serial_num -= days_in_months[month];
        month++;
    }

    cout << serial_num << "\t" << showMonth(month + 1) << endl;
}