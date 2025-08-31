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
        case FIT: return "���";
        case LID: return "���";
        case TOV: return "���";
        case IEF: return "���";
        case LHF: return "���";
        case PIM: return "���";
        default: return "����������";
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
            c == '�' || c == '�')) { // �������� ������� ���� � CP1251
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
        cout << "������: ������ ���� 2 ��� 3 ����� (������� ��� [��������])\n";
        return false;
    }

    for (const auto& p : parts) {
        if (!isValidNamePart(p)) {
            cout << "������ � \"" << p << "\":\n"
                 << "����� ������ ���������� � ��������� �����,\n"
                 << "��������� ����� ��������, ����������� ������\n";
            return false;
        }
    }
    return true;
}

void addStudent() {
    Student student;

    while (true) {
        cout << "������� ��� (������� ��� [��������]): ";
        getline(cin, student.fullName);
        if (student.fullName.empty()) {
            cout << "������: ���� ��� �� ����� ���� ������!\n";
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
        cout << "������� ���� ����������� (�� �� ����): ";
        if (cin >> day >> month >> year) {
            bool valid = true;
            
            if (day < 1 || day > 31) {
                cout << "������: ���� ������ ���� 1-31\n";
                valid = false;
            }
            if (month < 1 || month > 12) {
                cout << "������: ����� ������ ���� 1-12\n";
                valid = false;
            }
            if (year < 1900 || year > currentYearValue) {
                cout << "������: ��� ������ ���� 1900-" << currentYearValue << "\n";
                valid = false;
            }
            
            if (valid && !isValidDate(day, month, year)) {
                cout << "������: ����� ���� �� ����������!\n";
                valid = false;
            }

            if (valid) break;
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "������: ������� �����!\n";
        }
    }
    cin.ignore();
    student.admissionDate = {static_cast<unsigned int>(day), 
                             static_cast<unsigned int>(month), 
                             static_cast<unsigned int>(year)};

    while (true) {
        cout << "������� �������������: ";
        getline(cin, student.specialty);
        if (!student.specialty.empty()) break;
        cout << "������: ���� �� ����� ���� ������!\n";
    }

    while (true) {
        cout << "������� ������: ";
        getline(cin, student.group);
        if (!student.group.empty() && all_of(student.group.begin(), student.group.end(), ::isdigit) && stoi(student.group) < 100) break;
        cout << "������: ������������ �������� ������\n";
    }

    int facultyChoice;
    while (true) {
        cout << "�������� ���������:\n"
             << "0 - ���\n1 - ���\n2 - ���\n3 - ���\n4 - ���\n5 - ���\n"
             << "��� �����: ";
        if (cin >> facultyChoice) {
            if (facultyChoice >= 0 && facultyChoice <= 5) break;
            cout << "������: ������� 0-5\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "������: �������� ����\n";
        }
    }
    cin.ignore();
    student.faculty = static_cast<Faculty>(facultyChoice);

    while (true) {
        cout << "������� ������� ���� (����������� �����) (0.0-10.0): ";
        if (cin >> student.averageGrade) {
            if (student.averageGrade >= 0.0 && student.averageGrade <= 10.0) break;
            cout << "������: ���� ������ ���� 0.0-10.0\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "������: ������� �����\n";
        }
    }
    cin.ignore();
    students.push_back(student);
    cout << "������� ��������!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "������ ����\n";
        return;
    }
    cout << "\n������ ���������:\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " 
             << students[i].fullName << "\n"
             << "���� �����������: " << students[i].admissionDate.day << "." 
             << students[i].admissionDate.month << "." 
             << students[i].admissionDate.year << "\n"
             << "�������������: " << students[i].specialty << "\n"
             << "������: " << students[i].group << "\n"
             << "���������: " << facultyToString(students[i].faculty) << "\n"
             << "������� ����: " << students[i].averageGrade << "\n\n";
    }
}

void deleteStudent() {
    if (students.empty()) {
        cout << "������ ����\n";
        return;
    }

    string name;
    while (true) {
        cout << "������� ��� ��� ��������: ";
        getline(cin, name);
        if (name.empty()) {
            cout << "������: ������� ���!\n";
            continue;
        }
        break;
    }

    bool found = false;
    for (auto it = students.begin(); it != students.end();) {
        if (it->fullName == name) {
            it = students.erase(it);
            found = true;
            cout << "������� ������\n";
        } else {
            ++it;
        }
    }
    if (!found) cout << "������: ������� �� ������\n";
}

void findByGrade() {
    if (students.empty()) {
        cout << "������ ����\n";
        return;
    }

    double minGrade;
    while (true) {
        cout << "������� ����������� ���� (0.0-10.0): ";
        if (cin >> minGrade) {
            if (minGrade >= 0.0 && minGrade <= 10.0) break;
            cout << "������: ���� ������ ���� 0.0-10.0\n";
        } else {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "������: �������� ����\n";
        }
    }
    cin.ignore();

    bool found = false;
    for (const auto& s : students) {
        if (s.averageGrade >= minGrade) {
            cout << s.fullName << " | ����: " << s.averageGrade << "\n";
            found = true;
        }
    }
    if (!found) cout << "�������� �� �������\n";
}

void menu() {
    while (true) {
        cout << "\n����:\n"
             << "1. �������� ��������\n"
             << "2. �������� ���������\n"
             << "3. ������� ��������\n"
             << "4. ����� �� �����\n"
             << "5. �����\n"
             << "�������� ��������: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "������: �������� ����\n";
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
                cout << "�����...\n";
                return;
            default:
                cout << "������: �������� �����\n";
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