#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <Windows.h>
using namespace std;

enum Month {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

struct Date {
    unsigned int day : 5;   // 1-31
    unsigned int month : 4; // 1-12
    unsigned int year : 12; // 2020-4095
};

struct Item {
    string clientLastName;
    string itemName;
    double appraisalValue;
    double loanAmount;
    Date pawnDate;
    int storageTerm;
};

vector<Item> items;

// �������� ����������� ����
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// �������� ������������ ����
bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) return false;

    int daysInMonth;
    switch (month) {
        case February:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        case April: case June: case September: case November:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
    }

    return day <= daysInMonth;
}

bool isCorrectSurname(string surname) {
    for (unsigned char c : surname) {
        if (!(c == '-' ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 192 && c <= 255))) { // �������� ������� ���� � CP1251
            return false;
        }
    }
    if (surname[0] == '-' || surname[surname.length() - 1] == '-') return false;
    return !surname.empty();
}

// ��������������� ������� ��� ����������� ����� �����
template <typename T>
T getNumber(const string& prompt, T minVal, T maxVal) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= minVal && value <= maxVal) {
                cin.ignore(9999, '\n');
                return value;
            }
            cout << "�������� ������ ���� ����� " << minVal << " � " << maxVal << ".\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "������������ ����. ������� �����.\n";
        }
    }
}

void addItem() {
    Item item;
    
    // ���� �������
    cout << "������� ������� �������: ";
    getline(cin, item.clientLastName);
    while (!isCorrectSurname(item.clientLastName) || item.clientLastName == "-") {
        cout << "������! ������������ �������. ������� �����: ";
        getline(cin, item.clientLastName);
    }

    // ���� ������������ ������
    cout << "������� ������������ ������: ";
    getline(cin, item.itemName);
    while (item.itemName.empty()) {
        cout << "������������ ������ �� ����� ���� ������. ������� �����: ";
        getline(cin, item.itemName);
    }

    // ���� ��������� ���������
    item.appraisalValue = getNumber<double>("������� ��������� ���������: ", 0.01, 1e9);

    // ���� ����� ������
    item.loanAmount = getNumber<double>("������� �����, �������� ��� �����: ", 0.01, item.appraisalValue);

    // ���� ���� � ��������� ������������
    int day, month, year;
    bool validDate;
    do {
        day = getNumber<int>("������� ���� (1-31): ", 1, 31);
        month = getNumber<int>("������� ����� (1-12): ", 1, 12);
        year = getNumber<int>("������� ��� (2020-4095): ", 2020, 4095);
        validDate = isValidDate(day, month, year);
        if (!validDate) {
            cout << "������: ������������ ����. ���������� �����.\n";
        }
    } while (!validDate);
    
    item.pawnDate = {static_cast<unsigned int>(day), 
                     static_cast<unsigned int>(month), 
                     static_cast<unsigned int>(year)};

    // ���� ����� ��������
    item.storageTerm = getNumber<int>("������� ���� �������� (� �������): ", 1, 120);

    items.push_back(item);
    cout << "����� ������� ��������!\n";
}

// ��������� ������� �������� ��� ���������...

void displayItems() {
    if (items.empty()) {
        cout << "������ ������� ����.\n";
        return;
    }
    
    for (const auto& item : items) {
        cout << "\n�������: " << item.clientLastName
             << "\n�����: " << item.itemName
             << "\n��������� ���������: " << item.appraisalValue
             << "\n����� ������: " << item.loanAmount
             << "\n���� �����: " << item.pawnDate.day << "." 
             << item.pawnDate.month << "." << item.pawnDate.year
             << "\n���� ��������: " << item.storageTerm << " ���.\n";
    }
}

void deleteItem() {
    if (items.empty()) {
        cout << "������ ������� ����.\n";
        return;
    }

    string lastName;
    cout << "������� ������� ������� ��� ��������: ";
    getline(cin, lastName);
    while (lastName.empty()) {
        cout << "������� �� ����� ���� ������. ������� �����: ";
        getline(cin, lastName);
    }

    bool found = false;
    for (auto it = items.begin(); it != items.end();) {
        if (it->clientLastName == lastName) {
            it = items.erase(it);
            found = true;
            cout << "����� ������� " << lastName << " ������.\n";
        } else {
            ++it;
        }
    }
    
    if (!found) {
        cout << "������ � �������� " << lastName << " �� �������.\n";
    }
}

void findExpiredItems() {
    if (items.empty()) {
        cout << "������ ������� ����.\n";
        return;
    }

    int currentMonth = getNumber<int>("������� ������� ����� (1-12): ", 1, 12);
    int currentYear = getNumber<int>("������� ������� ��� (2020-4095): ", 2020, 4095);
    bool found = false;

    for (const auto& item : items) {
        int totalMonths = item.pawnDate.month + item.storageTerm - 1;
        int expirationYear = item.pawnDate.year + totalMonths / 12;
        int expirationMonth = (totalMonths % 12) + 1;

        if (expirationYear < currentYear || 
            (expirationYear == currentYear && expirationMonth < currentMonth)) {
            
            cout << "\n������������ �����: " << item.itemName 
                 << " (������: " << item.clientLastName << ")"
                 << "\n���� ��������� ��������: " << expirationMonth 
                 << "." << expirationYear << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "������������ ������� �� �������.\n";
    }
}

void displayMenu() {
    cout << "\n����:\n"
         << "1. �������� �����\n"
         << "2. ������� ������ �������\n"
         << "3. ������� �����\n"
         << "4. ����� ������������ ������\n"
         << "5. �����\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int choice;
    while (true) {
        displayMenu();
        choice = getNumber<int>("�������� �������� (1-5): ", 1, 5);
        
        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: deleteItem(); break;
            case 4: findExpiredItems(); break;
            case 5: 
                cout << "����� �� ���������.\n";
                return 0;
        }
    }
}