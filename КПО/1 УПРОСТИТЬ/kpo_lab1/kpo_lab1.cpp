п»ї#include <iostream>
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
	cout << "Р’РІРµРґРёС‚Рµ РґР°С‚Сѓ РІ С„РѕСЂРјР°С‚Рµ (Р”Р”РњРњР“Р“Р“Р“): ";
	cin >> current_date;

	// Р’Р°Р»РёРґР°С†РёСЏ СЃС‚СЂРѕРєРё СЃ РїРѕРјРѕС‰СЊСЋ СѓРЅР°СЂРЅРѕРіРѕ РїСЂРµРґРёРєР°С‚Р°
	if (!all_of(current_date.begin(), current_date.end(), ::isdigit) || current_date.length() != 8)
	{
		cerr << "РћС€РёР±РєР°! Р’РІРµРґРµРЅР° РЅРµРїСЂР°РІРёР»СЊРЅР°СЏ РґР°С‚Р°" << endl;
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

	// РџСЂРѕРІРµСЂРєР° РЅР° РєРѕСЂСЂРµРєС‚РЅРѕСЃС‚СЊ РІРІРµРґРµРЅРЅС‹С… С‡РёСЃРµР»
	if (cur_month > 12 || cur_day > days_in_months[cur_month - 1])
	{
		cerr << "РћС€РёР±РєР°! Р’РІРµРґРµРЅР° РЅРµРїСЂР°РІРёР»СЊРЅР°СЏ РґР°С‚Р°" << endl;
		return 1;
	}

	if (cur_year == 0 || cur_month == 0 || cur_day == 0)
	{
		cerr << "РћС€РёР±РєР°! Р’РІРµРґРµРЅР° РЅРµРїСЂР°РІРёР»СЊРЅР°СЏ РґР°С‚Р°" << endl;
		return 1;
	}

	int cur_serial_number = detSerialNumber(cur_day, cur_month, days_in_months);

	int bday_day = splitData(BDAY_DATE)[0];
	int bday_month = splitData(BDAY_DATE)[1];
	int bday_year = splitData(BDAY_DATE)[2];
	int bday_serial_number = detSerialNumber(bday_day, bday_month, days_in_months);

	int remaining_days_for_bday;
	if (bday_serial_number >= cur_serial_number) // Р•СЃР»Рё РґРµРЅСЊ СЂРѕР¶РґРµРЅРёСЏ РµС‰Рµ РЅРµ РїСЂРѕС€РµР»
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
	else // Р•СЃР»Рё РґРµРЅСЊ СЂРѕР¶РґРµРЅРёСЏ СѓР¶Рµ РїСЂРѕС€РµР»
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

	cout << "Р’РІРµРґРµРЅРЅР°СЏ РґР°С‚Р°: " << cur_day << "\t" << cur_month << "\t" << cur_year << endl;
	cout << "Р“РѕРґ - " << (is_viscos ? "РІРёСЃРѕРєРѕСЃРЅС‹Р№" : "РЅРµ РІРёСЃРѕРєРѕСЃРЅС‹Р№") << endl;
	cout << "РџРѕСЂСЏРґРєРѕРІС‹Р№ РЅРѕРјРµСЂ РґРЅСЏ: " << detSerialNumber(cur_day, cur_month, days_in_months) << endl;
	cout << "РћСЃС‚Р°Р»РѕСЃСЊ РґРЅРµР№ РґРѕ РјРѕРµРіРѕ РґРЅСЏ СЂРѕР¶РґРµРЅРёСЏ: " << remaining_days_for_bday;

	return 0;
}