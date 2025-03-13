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

// Проверка високосного года
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Проверка корректности даты
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
            (c >= 192 && c <= 255))) { // Диапазон русских букв в CP1251
            return false;
        }
    }
    if (surname[0] == '-' || surname[surname.length() - 1] == '-') return false;
    return !surname.empty();
}

// Вспомогательная функция для безопасного ввода чисел
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
            cout << "Значение должно быть между " << minVal << " и " << maxVal << ".\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Некорректный ввод. Введите число.\n";
        }
    }
}

void addItem() {
    Item item;
    
    // Ввод фамилии
    cout << "Введите фамилию клиента: ";
    getline(cin, item.clientLastName);
    while (!isCorrectSurname(item.clientLastName) || item.clientLastName == "-") {
        cout << "Ошибка! Некорректная фамилия. Введите снова: ";
        getline(cin, item.clientLastName);
    }

    // Ввод наименования товара
    cout << "Введите наименование товара: ";
    getline(cin, item.itemName);
    while (item.itemName.empty()) {
        cout << "Наименование товара не может быть пустым. Введите снова: ";
        getline(cin, item.itemName);
    }

    // Ввод оценочной стоимости
    item.appraisalValue = getNumber<double>("Введите оценочную стоимость: ", 0.01, 1e9);

    // Ввод суммы залога
    item.loanAmount = getNumber<double>("Введите сумму, выданную под залог: ", 0.01, item.appraisalValue);

    // Ввод даты с проверкой корректности
    int day, month, year;
    bool validDate;
    do {
        day = getNumber<int>("Введите день (1-31): ", 1, 31);
        month = getNumber<int>("Введите месяц (1-12): ", 1, 12);
        year = getNumber<int>("Введите год (2020-4095): ", 2020, 4095);
        validDate = isValidDate(day, month, year);
        if (!validDate) {
            cout << "Ошибка: Некорректная дата. Попробуйте снова.\n";
        }
    } while (!validDate);
    
    item.pawnDate = {static_cast<unsigned int>(day), 
                     static_cast<unsigned int>(month), 
                     static_cast<unsigned int>(year)};

    // Ввод срока хранения
    item.storageTerm = getNumber<int>("Введите срок хранения (в месяцах): ", 1, 120);

    items.push_back(item);
    cout << "Товар успешно добавлен!\n";
}

// Остальные функции остаются без изменений...

void displayItems() {
    if (items.empty()) {
        cout << "Список товаров пуст.\n";
        return;
    }
    
    for (const auto& item : items) {
        cout << "\nФамилия: " << item.clientLastName
             << "\nТовар: " << item.itemName
             << "\nОценочная стоимость: " << item.appraisalValue
             << "\nСумма залога: " << item.loanAmount
             << "\nДата сдачи: " << item.pawnDate.day << "." 
             << item.pawnDate.month << "." << item.pawnDate.year
             << "\nСрок хранения: " << item.storageTerm << " мес.\n";
    }
}

void deleteItem() {
    if (items.empty()) {
        cout << "Список товаров пуст.\n";
        return;
    }

    string lastName;
    cout << "Введите фамилию клиента для удаления: ";
    getline(cin, lastName);
    while (lastName.empty()) {
        cout << "Фамилия не может быть пустой. Введите снова: ";
        getline(cin, lastName);
    }

    bool found = false;
    for (auto it = items.begin(); it != items.end();) {
        if (it->clientLastName == lastName) {
            it = items.erase(it);
            found = true;
            cout << "Товар клиента " << lastName << " удален.\n";
        } else {
            ++it;
        }
    }
    
    if (!found) {
        cout << "Товары с фамилией " << lastName << " не найдены.\n";
    }
}

void findExpiredItems() {
    if (items.empty()) {
        cout << "Список товаров пуст.\n";
        return;
    }

    int currentMonth = getNumber<int>("Введите текущий месяц (1-12): ", 1, 12);
    int currentYear = getNumber<int>("Введите текущий год (2020-4095): ", 2020, 4095);
    bool found = false;

    for (const auto& item : items) {
        int totalMonths = item.pawnDate.month + item.storageTerm - 1;
        int expirationYear = item.pawnDate.year + totalMonths / 12;
        int expirationMonth = (totalMonths % 12) + 1;

        if (expirationYear < currentYear || 
            (expirationYear == currentYear && expirationMonth < currentMonth)) {
            
            cout << "\nПросроченный товар: " << item.itemName 
                 << " (Клиент: " << item.clientLastName << ")"
                 << "\nДата окончания хранения: " << expirationMonth 
                 << "." << expirationYear << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Просроченных товаров не найдено.\n";
    }
}

void displayMenu() {
    cout << "\nМеню:\n"
         << "1. Добавить товар\n"
         << "2. Вывести список товаров\n"
         << "3. Удалить товар\n"
         << "4. Найти просроченные товары\n"
         << "5. Выход\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int choice;
    while (true) {
        displayMenu();
        choice = getNumber<int>("Выберите действие (1-5): ", 1, 5);
        
        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: deleteItem(); break;
            case 4: findExpiredItems(); break;
            case 5: 
                cout << "Выход из программы.\n";
                return 0;
        }
    }
}