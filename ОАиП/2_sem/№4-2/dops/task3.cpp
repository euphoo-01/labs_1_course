#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <cctype>
#include <locale>
#include <algorithm>
#include <tuple>

using namespace std;

struct Sanatorium {
    string name;         // Название санатория
    string location;     // расположение
    string profile;      // лечебный профиль
    int voucherCount;    // путевки
};

bool isValidNameProfile(const string& str) {
    for (unsigned char c : str) {
        if (!(c == '-' || (c == ' ') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 192 && c <= 255))) { // Диапазон русских букв в CP1251
            return false;
        }
    }
    return !str.empty();
}

void sortSanatoriums(vector<Sanatorium>& sanatoriums) {
    sort(sanatoriums.begin(), sanatoriums.end(),
        [](const Sanatorium& a, const Sanatorium& b) {
            return tie(a.profile, a.name) < tie(b.profile, b.name);
        });
}

void printSanatoriums(const vector<Sanatorium>& sanatoriums) {
    cout << "\nСанатории:\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "| Лечебный профиль   | Название санатория         | Местоположение | Путевки|\n";
    cout << "----------------------------------------------------------------------------\n";

    for (const auto& s : sanatoriums) {
        printf("| %-19s| %-25s| %-15s| %-7d|\n",
            s.profile.c_str(), s.name.c_str(), s.location.c_str(), s.voucherCount);
    }

    cout << "----------------------------------------------------------------------------\n";
}

void searchSanatoriums(const vector<Sanatorium>& sanatoriums, const string& searchProfile) {
    cout << "\nРезультаты поиска по лечебному профилю \"" << searchProfile << "\":\n";
    bool found = false;

    for (const auto& s : sanatoriums) {
        if (s.profile == searchProfile) {
            if (!found) {
                cout << "----------------------------------------------------------------------------\n";
                cout << "| Название санатория         | Местоположение     | Путевки |\n";
                cout << "----------------------------------------------------------------------------\n";
            }
            printf("| %-25s| %-20s| %-7d|\n", s.name.c_str(), s.location.c_str(), s.voucherCount);
            found = true;
        }
    }

    if (!found) {
        cout << "Санаториев с таким лечебным профилем не найдено.\n";
    }
    else {
        cout << "----------------------------------------------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    vector<Sanatorium> sanatoriums;
    int count;

    // Ввод количества санаториев
    do {
        cout << "Введите количество санаториев: ";
        if (!(cin >> count)) {
            cout << "Ошибка: введите целое число!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (count <= 0) {
            cout << "Ошибка: количество должно быть положительным!\n";
        }
    } while (count <= 0);
    cin.ignore(10000, '\n');

    // Ввод данных о санаториях
    for (int i = 0; i < count; ++i) {
        Sanatorium s;
        cout << "\nСанаторий #" << (i + 1) << ":\n";

        // Ввод названия
        do {
            cout << "Введите название (только буквы и дефисы): ";
            getline(cin, s.name);
            if (!isValidNameProfile(s.name)) {
                cout << "Ошибка: разрешены только русские/английские буквы и дефис!\n";
            }
        } while (!isValidNameProfile(s.name));

        // Ввод местоположения (любые символы)
        cout << "Введите место расположения: ";
        getline(cin, s.location);

        // Ввод профиля
        do {
            cout << "Введите лечебный профиль (только буквы и дефисы): ";
            getline(cin, s.profile);
            if (!isValidNameProfile(s.profile)) {
                cout << "Ошибка: разрешены только русские/английские буквы и дефис!\n";
            }
        } while (!isValidNameProfile(s.profile));

        // Ввод количества путевок
        do {
            cout << "Введите количество путевок: ";
            if (!(cin >> s.voucherCount)) {
                cout << "Ошибка: введите целое число!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else if (s.voucherCount < 0) {
                cout << "Ошибка: количество не может быть отрицательным!\n";
            }
            else {
                break;
            }
        } while (true);
        cin.ignore(10000, '\n');

        sanatoriums.push_back(s);
    }

    sortSanatoriums(sanatoriums);
    printSanatoriums(sanatoriums);

    // Поиск по профилю
    string searchProfile;
    do {
        cout << "\nВведите лечебный профиль для поиска: ";
        getline(cin, searchProfile);
        if (searchProfile.empty()) {
            cout << "Ошибка: профиль не может быть пустым!\n";
        }
    } while (searchProfile.empty());

    searchSanatoriums(sanatoriums, searchProfile);

    return 0;
}