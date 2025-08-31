#include "stdafx.h"
#include "detSerialNumber.h"
#include "detViscosity.h"
#include "splitData.h"
#include "showMonth.h"
#include "showDate.h"

using namespace std;
const string BDAY_DATE = "02012007";

int days_in_months[12] = { 31, 28 /*�������, ������������*/, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	setlocale(LC_ALL, "Russian");
	string current_date;
	cout << "������� ���� � ������� (��������): ";
	cin >> current_date;
	bool isAllDigits = true;
	for (unsigned char c : current_date) {
		if (!isdigit(c)) isAllDigits = false;
	}

	if (!isAllDigits || current_date.length() != 8)
	{
		cerr << "������! ������� ������������ ����" << endl;
		return 1;
	}

	int cur_day = splitData(current_date)[0];
	int cur_month = splitData(current_date)[1];
	int cur_year = splitData(current_date)[2];

	bool is_viscos;
	if (is_viscos = detViscosity(cur_year))
	{
		days_in_months[1] = 29;
	}
	else
	{
		days_in_months[1] = 28;
	}

	// �������� �� ������������ ��������� �����
	if (cur_month > 12 || cur_day > days_in_months[cur_month - 1])
	{
		cerr << "������! ������� ������������ ����" << endl;
		return 1;
	}

	if (cur_year == 0 || cur_month == 0 || cur_day == 0)
	{
		cerr << "������! ������� ������������ ����" << endl;
		return 1;
	}

	int cur_serial_number = detSerialNumber(cur_day, cur_month, days_in_months);

	int bday_day = splitData(BDAY_DATE)[0];
	int bday_month = splitData(BDAY_DATE)[1];
	int bday_year = splitData(BDAY_DATE)[2];
	int bday_serial_number = detSerialNumber(bday_day, bday_month, days_in_months);

	int remaining_days_for_bday;
	if (bday_serial_number >= cur_serial_number) // ���� ���� �������� ��� �� ������
	{
		remaining_days_for_bday = bday_serial_number - cur_serial_number;
		if (bday_day == 29 && bday_month == 2)
		{
			int temp_cur_year = cur_year;
			while (!detViscosity(temp_cur_year)) // ���� � ���� ���� ��� ���� ����
			{
				temp_cur_year++;
				remaining_days_for_bday += 365;
			}
		}
	}
	else // ���� ���� �������� ��� ������
	{
		remaining_days_for_bday = (detViscosity(cur_year + 1) ? 366 : 365) - cur_serial_number + bday_serial_number;
		if (bday_day == 29 && bday_month == 2)
		{
			int temp_cur_year = cur_year;
			while (!detViscosity(temp_cur_year))
			{
				temp_cur_year++;
				remaining_days_for_bday += 365;
			}
		}
	}

	cout << "��������� ����: " << cur_day << "\t" << showMonth(cur_month) << "\t" << cur_year << endl;
	cout << "��� - " << (is_viscos ? "����������" : "�� ����������") << endl;
	cout << "���������� ����� ���: " << detSerialNumber(cur_day, cur_month, days_in_months) << endl;
	cout << "�������� ���� �� ����� ��� ��������: " << remaining_days_for_bday << endl;

	int cur_serial_day;
	cout << "������� ���������� ����� ���: "; cin >> cur_serial_day;
	while (cur_serial_day < 0 || cur_serial_day > 366) {
		cout << "������! ������� ���������� ����� ���: "; cin >> cur_serial_day;
	}
	showDate(cur_serial_day, days_in_months);

	return 0;
}