#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <Windows.h>
using namespace std;

enum Faculty {
    FIT, LID, TOV, IEF, LHF, PIM
};

struct Date {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 12;
};

struct Student {
    string fullName;
    Date admissionDate;
    string specialty;
    string group;
    Faculty faculty;
    double averageGrade;
};

vector<Student> students;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2) {
        return isLeapYear(year) ? day <= 29 : day <= 28;
    }

    return day <= daysInMonth[month - 1];
}

string facultyToString(Faculty faculty) {
    switch (faculty) {
        case FIT: return "ФИТ";
        case LID: return "ЛИД";
        case TOV: return "ТОВ";
        case IEF: return "ИЭФ";
        case LHF: return "ЛХФ";
        case PIM: return "ПИМ";
        default: return "Неизвестно";
    }
}

bool isValidNamePart(const string& part) {
    
    unsigned char firstLetter = part[0];
    if (!((firstLetter >= 'A' && firstLetter <= 'Z') || 
    (firstLetter >= 192 && firstLetter <= 223) ||
    (firstLetter == 168))) return false;

    for (unsigned char c : part) {
        if (!(c == '-' ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 192 && c <= 255) ||
            c == 'ё' || c == 'Ё')) { // Диапазон русских букв в CP1251
            return false;
        }
    }
    if (part[0] == '-' || part[part.length() - 1] == '-') return false;
    return !part.empty();
}

bool validateFullName(const string& fullName) {
    istringstream iss(fullName);
    vector<string> parts;
    string part;
    while (iss >> part) {
        parts.push_back(part);
    }

    if (parts.size() < 2 || parts.size() > 3) {
        cout << "Ошибка: Должно быть 2 или 3 части (Фамилия Имя [Отчество])\n";
        return false;
    }

    for (const auto& p : parts) {
        if (!isValidNamePart(p)) {
            cout << "Ошибка в \"" << p << "\":\n"
                 << "Часть должна начинаться с заглавной буквы,\n"
                 << "остальные буквы строчные, допускаются дефисы\n";
            return false;
        }
    }
    return true;
}

void addStudent() {
    Student student;

    while (true) {
        cout << "Введите ФИО (Фамилия Имя [Отчество]): ";
        getline(cin, student.fullName);
        if (student.fullName.empty()) {
            cout << "Ошибка: Поле ФИО не может быть пустым!\n";
            continue;
        }
        if (validateFullName(student.fullName)) break;
    }

    int day, month, year;
    time_t t = time(nullptr);
    tm currentYear;
    localtime_s(&currentYear, &t);
    int currentYearValue = currentYear.tm_year + 1900;

    while (true) {
        cout << "Введите дату поступления (дд мм гггг): ";
        if (cin >> day >> month >> year) {
            bool valid = true;
            
            if (day < 1 || day > 31) {
                cout << "Ошибка: День должен быть 1-31\n";
                valid = false;
            }
            if (month < 1 || month > 12) {
                cout << "Ошибка: Месяц должен быть 1-12\n";
                valid = false;
            }
            if (year < 1900 || year > currentYearValue) {
                cout << "Ошибка: Год должен быть 1900-" << currentYearValue << "\n";
                valid = false;
            }
            
            if (valid && !isValidDate(day, month, year)) {
                cout << "Ошибка: Такая дата не существует!\n";
                valid = false;
            }

            if (valid) break;
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Ошибка: Введите числа!\n";
        }
    }
    cin.ignore();
    student.admissionDate = {static_cast<unsigned int>(day), 
                             static_cast<unsigned int>(month), 
                             static_cast<unsigned int>(year)};

    while (true) {
        cout << "Введите специальность: ";
        getline(cin, student.specialty);
        if (!student.specialty.empty()) break;
        cout << "Ошибка: Поле не может быть пустым!\n";
    }

    while (true) {
        cout << "Введите группу: ";
        getline(cin, student.group);
        if (!student.group.empty() && all_of(student.group.begin(), student.group.end(), ::isdigit) && stoi(student.group) < 100) break;
        cout << "Ошибка: Некорректное значение группы\n";
    }

    int facultyChoice;
    while (true) {
        cout << "Выберите факультет:\n"
             << "0 - ФИТ\n1 - ЛИД\n2 - ТОВ\n3 - ИЭФ\n4 - ЛХФ\n5 - ПИМ\n"
             << "Ваш выбор: ";
        if (cin >> facultyChoice) {
            if (facultyChoice >= 0 && facultyChoice <= 5) break;
            cout << "Ошибка: Введите 0-5\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Ошибка: Неверный ввод\n";
        }
    }
    cin.ignore();
    student.faculty = static_cast<Faculty>(facultyChoice);

    while (true) {
        cout << "Введите средний балл (разделитель точка) (0.0-10.0): ";
        if (cin >> student.averageGrade) {
            if (student.averageGrade >= 0.0 && student.averageGrade <= 10.0) break;
            cout << "Ошибка: Балл должен быть 0.0-10.0\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Ошибка: Введите число\n";
        }
    }
    cin.ignore();
    students.push_back(student);
    cout << "Студент добавлен!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "Список пуст\n";
        return;
    }
    cout << "\nСписок студентов:\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " 
             << students[i].fullName << "\n"
             << "Дата поступления: " << students[i].admissionDate.day << "." 
             << students[i].admissionDate.month << "." 
             << students[i].admissionDate.year << "\n"
             << "Специальность: " << students[i].specialty << "\n"
             << "Группа: " << students[i].group << "\n"
             << "Факультет: " << facultyToString(students[i].faculty) << "\n"
             << "Средний балл: " << students[i].averageGrade << "\n\n";
    }
}

void deleteStudent() {
    if (students.empty()) {
        cout << "Список пуст\n";
        return;
    }

    string name;
    while (true) {
        cout << "Введите ФИО для удаления: ";
        getline(cin, name);
        if (name.empty()) {
            cout << "Ошибка: Введите ФИО!\n";
            continue;
        }
        break;
    }

    bool found = false;
    for (auto it = students.begin(); it != students.end();) {
        if (it->fullName == name) {
            it = students.erase(it);
            found = true;
            cout << "Студент удален\n";
        } else {
            ++it;
        }
    }
    if (!found) cout << "Ошибка: Студент не найден\n";
}

void findByGrade() {
    if (students.empty()) {
        cout << "Список пуст\n";
        return;
    }

    double minGrade;
    while (true) {
        cout << "Введите минимальный балл (0.0-10.0): ";
        if (cin >> minGrade) {
            if (minGrade >= 0.0 && minGrade <= 10.0) break;
            cout << "Ошибка: Балл должен быть 0.0-10.0\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Ошибка: Неверный ввод\n";
        }
    }
    cin.ignore();

    bool found = false;
    for (const auto& s : students) {
        if (s.averageGrade >= minGrade) {
            cout << s.fullName << " | Балл: " << s.averageGrade << "\n";
            found = true;
        }
    }
    if (!found) cout << "Студенты не найдены\n";
}

void menu() {
    while (true) {
        cout << "\nМеню:\n"
             << "1. Добавить студента\n"
             << "2. Показать студентов\n"
             << "3. Удалить студента\n"
             << "4. Поиск по баллу\n"
             << "5. Выход\n"
             << "Выберите действие: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Ошибка: Неверный ввод\n";
            continue;
        }

        switch (choice) {
            case 1:
                cin.ignore();
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cin.ignore();
                deleteStudent();
                break;
            case 4:
                cin.ignore();
                findByGrade();
                break;
            case 5:
                cout << "Выход...\n";
                return;
            default:
                cout << "Ошибка: Неверный выбор\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}