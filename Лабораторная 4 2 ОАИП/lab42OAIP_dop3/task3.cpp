#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Sanatorium {
    string name;         // Название санатория
    string location;     // расположение
    string profile;      // лечебный профиль
    int voucherCount;    // путевки
};

void sortSanatoriums(Sanatorium sanatoriums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (sanatoriums[j].profile > sanatoriums[j + 1].profile ||
                (sanatoriums[j].profile == sanatoriums[j + 1].profile && sanatoriums[j].name > sanatoriums[j + 1].name)) {
                Sanatorium tmp = sanatoriums[j];
                sanatoriums[j] = sanatoriums[j + 1];
                sanatoriums[j + 1] = tmp;
            }
        }
    }
}

void printSanatoriums(Sanatorium sanatoriums[], int count) {
    cout << "\nСанатории:\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "| Лечебный профиль   | Название санатория         | Местоположение | Путевки|\n";
    cout << "----------------------------------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << "| " << sanatoriums[i].profile
            << string(19 - sanatoriums[i].profile.length(), ' ') << "| "
            << sanatoriums[i].name
            << string(25 - sanatoriums[i].name.length(), ' ') << "| "
            << sanatoriums[i].location
            << string(16 - sanatoriums[i].location.length(), ' ') << "| "
            << sanatoriums[i].voucherCount << "      |\n";
    }

    cout << "----------------------------------------------------------------------------\n";
}

void searchSanatoriums(Sanatorium sanatoriums[], int count, const string& searchProfile) {
    cout << "\nРезультаты поиска по лечебному профилю \"" << searchProfile << "\":\n";
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (sanatoriums[i].profile == searchProfile) {
            if (!found) {
                cout << "----------------------------------------------------------------------------\n";
                cout << "| Название санатория         | Местоположение     | Путевки |\n";
                cout << "----------------------------------------------------------------------------\n";
            }

            cout << "| " << sanatoriums[i].name
                << string(25 - sanatoriums[i].name.length(), ' ') << "| "
                << sanatoriums[i].location
                << string(20 - sanatoriums[i].location.length(), ' ') << "| "
                << sanatoriums[i].voucherCount << "      |\n";

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

void main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int sanatoriumCount = 5;
    Sanatorium sanatoriums[sanatoriumCount];
    cout << "Введите данные о " << sanatoriumCount << " санаториях:\n";
    for (int i = 0; i < sanatoriumCount; i++) {
        cout << "\nСанаторий #" << (i + 1) << ":\n";
        cout << "Введите название санатория: ";
        cin.ignore();
        getline(cin, sanatoriums[i].name);
        cout << "Введите место расположения: ";
        getline(cin, sanatoriums[i].location);
        cout << "Введите лечебный профиль: ";
        getline(cin, sanatoriums[i].profile);
        cout << "Введите количество путевок: ";
        cin >> sanatoriums[i].voucherCount;
    }
    sortSanatoriums(sanatoriums, sanatoriumCount);
    printSanatoriums(sanatoriums, sanatoriumCount);

    string searchProfile;
    cout << "\nВведите лечебный профиль для поиска: ";
    cin.ignore(); 
    getline(cin, searchProfile);

    searchSanatoriums(sanatoriums, sanatoriumCount, searchProfile);
}
