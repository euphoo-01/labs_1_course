#include "stdafx.h"
#include "splitData.h"
using namespace std;
int* splitData(string date)  // ��������� ������ ���� �� 3 ����� �����: ���, ����� � ����
{
    int temp[3];

    temp[0] = stoi(date.substr(0, 2)); // day
    temp[1] = stoi(date.substr(2, 2)); // month
    temp[2] = stoi(date.substr(4, 4)); // year

    return temp;
}