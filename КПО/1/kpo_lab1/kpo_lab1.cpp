#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "detViscosity.hpp"
#include "detSerialNumber.hpp"
#include "splitData.hpp"
using namespace std;
const string BDAY_DATE = "02012007";

vector<int> days_in_months = {31, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	setlocale(LC_ALL, "Russian");
	string current_date;
	cout << "Введите дату в формате (ДДММГГГГ): ";
	cin >> current_date;

	// Валидация строки с помощью унарного предиката
	if (!all_of(current_date.begin(), current_date.end(), ::isdigit) || current_date.length() != 8)
	{
		cerr << "Ошибка! Введена неправильная дата" << endl;
		return 1;
	}

	int cur_day = splitData(current_date)[0];
	int cur_month = splitData(current_date)[1];
	int cur_year = splitData(current_date)[2];

	bool is_viscos;
	if (is_viscos = detViscosity(cur_year))
	{
		days_in_months.insert(days_in_months.begin() + 1, 29);
	}
	else
	{
		days_in_months.insert(days_in_months.begin() + 1, 28);
	}

	// Проверка на корректность введенных чисел
	if (cur_month > 12 || cur_day > days_in_months[cur_month - 1])
	{
		cerr << "Ошибка! Введена неправильная дата" << endl;
		return 1;
	}

	if (cur_year == 0 || cur_month == 0 || cur_day == 0)
	{
		cerr << "Ошибка! Введена неправильная дата" << endl;
		return 1;
	}

	int cur_serial_number = detSerialNumber(cur_day, cur_month, days_in_months);

	int bday_day = splitData(BDAY_DATE)[0];
	int bday_month = splitData(BDAY_DATE)[1];
	int bday_year = splitData(BDAY_DATE)[2];
	int bday_serial_number = detSerialNumber(bday_day, bday_month, days_in_months);

	int remaining_days_for_bday;
	if (bday_serial_number >= cur_serial_number) // Если день рождения еще не прошел
	{
		remaining_days_for_bday = bday_serial_number - cur_serial_number;
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
	else // Если день рождения уже прошел
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

	cout << "Введенная дата: " << cur_day << "\t" << cur_month << "\t" << cur_year << endl;
	cout << "Год - " << (is_viscos ? "високосный" : "не високосный") << endl;
	cout << "Порядковый номер дня: " << detSerialNumber(cur_day, cur_month, days_in_months) << endl;
	cout << "Осталось дней до моего дня рождения: " << remaining_days_for_bday;

	return 0;
}