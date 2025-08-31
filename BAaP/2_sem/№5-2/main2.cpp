#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <cctype>
#include <limits>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <locale>

using namespace std;

union ClassInfo {
    struct {
        int number;
        char letter;
    };
    char combined[10];
};

struct Subject {
    char name[50];
    float grade;
};

struct Student {
    char fullName[100];
    ClassInfo classInfo;
    Subject subjects[10];
    int numSubjects;
    float average;
};

bool isValidName(const string& name);
bool isValidClass(const string& className);
bool isValidGrade(float grade);
void clearCinBuffer();
bool isRussianChar(char c);
bool isSubjectExists(const Student& student, const string& subjectName);

bool isSubjectExists(const Student& student, const string& subjectName) {
    for (int i = 0; i < student.numSubjects; ++i) {
        if (strcmp(student.subjects[i].name, subjectName.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

bool isRussianChar(char c) {
    return (c >= '�' && c <= '�') || c == '�' || c == '�';
}

bool isValidName(const string& name) {
    int count_space = 0;
    for (char c : name) {

        if (c == ' ') {
            count_space++;
        }
    }
    if (count_space < 1 || count_space > 2) {
        return false;
    }
    if (name.empty() || name.length() >= 100) return false;
    return all_of(name.begin(), name.end(), [](char c) {
        return isRussianChar(c) || c == ' ' || c == '-' || c == '\'';
        });

}

bool isValidClass(const string& className) {
    if (className.length() < 2 || className.length() > 5) return false;
    size_t i = 0;
    while (i < className.length() && isdigit(className[i])) i++;
    if (i == 0 || i >= className.length()) return false;
    int classNumber = stoi(className.substr(0, i));
    return classNumber >= 1 && classNumber <= 11 && isRussianChar(className[i]);
}

bool isValidGrade(float grade) {
    return grade >= 1.0f && grade <= 10.0f;
}

void clearCinBuffer() {
    cin.clear();
    cin.ignore(9999, '\n');
}

void inputStudent(Student& student) {
    do {
        cout << "������� ��� �������: ";
        cin.getline(student.fullName, 100);
        for (int i = 0; i < sizeof(student.fullName) / sizeof(char); i++) {
            if (i == 0) {
                student.fullName[i] = toupper(student.fullName[i]);
            }
            if (student.fullName[i - 1] == ' ') {
                student.fullName[i] = toupper(student.fullName[i]);
            }
        }
        if (!isValidName(student.fullName)) {
            cout << "������! ����������� ������ ������� �����, ������� � ������. ������� ��� ������� ������� � ���\n";
        }
    } while (!isValidName(student.fullName));

    string classStr;
    do {
        cout << "������� ����� (1-11 ����� + ������� �����, �������� 10�): ";
        getline(cin, classStr);
        if (!isValidClass(classStr)) {
            cout << "������! ������ ����������� �������: 9�\n";
        }
    } while (!isValidClass(classStr));

    size_t i = 0;
    student.classInfo.number = 0;
    while (i < classStr.size() && isdigit(classStr[i])) {
        student.classInfo.number = student.classInfo.number * 10 + (classStr[i] - '0');
        i++;
    }
    student.classInfo.letter = toupper(classStr[i]);

    cout << "������� �������� � ������ (�������� 10, ������: '���������� 8,5'):\n";
    student.numSubjects = 0;
    while (student.numSubjects < 10) {
        cout << "������� #" << student.numSubjects + 1 << " (��� Enter ��� ����������): ";
        string line;
        getline(cin, line);
        if (line.empty()) break;

        size_t last_space = line.find_last_of(" ");
        if (last_space == string::npos) {
            cout << "������ �������! �����������: '�������� �������� ������'\n";
            continue;
        }

        string subject = line.substr(0, last_space);
        string grade_str = line.substr(last_space + 1);

        float grade;
        try {
            replace(grade_str.begin(), grade_str.end(), '.', ',');
            grade = stof(grade_str);
            grade = round(grade * 10) / 10;
        }
        catch (...) {
            cout << "������ ������� ������! ������: 7,5\n";
            continue;
        }

        if (subject.length() >= 50) {
            cout << "������� ������� �������� ��������! �������� 49 ��������.\n";
            continue;
        }

        if (!isValidGrade(grade)) {
            cout << "������������ ������! ��������� �� 1,0 �� 10,0.\n";
            continue;
        }

        if (isSubjectExists(student, subject)) {
            cout << "���� ������� ��� ����������! ������� ������.\n";
            continue;
        }

        strncpy(student.subjects[student.numSubjects].name, subject.c_str(), 49);
        student.subjects[student.numSubjects].name[49] = '\0';
        student.subjects[student.numSubjects].grade = grade;
        student.numSubjects++;
    }

    float sum = 0;
    for (int i = 0; i < student.numSubjects; ++i) {
        sum += student.subjects[i].grade;
    }
    student.average = student.numSubjects > 0 ? round((sum / student.numSubjects) * 10) / 10 : 0;
}

void writeStudentToFile(const Student& student, ofstream& outFile) {
    outFile << student.fullName << ";";
    outFile << student.classInfo.number << student.classInfo.letter << ";";
    for (int i = 0; i < student.numSubjects; ++i) {
        outFile << student.subjects[i].name << ":" << fixed << setprecision(1) << student.subjects[i].grade;
        if (i < student.numSubjects - 1) outFile << ";";
    }
    outFile << ";" << fixed << setprecision(1) << student.average << "\n";
}

void printStudent(const Student& student) {
    cout << "\n���: " << student.fullName
        << "\n�����: " << student.classInfo.number << student.classInfo.letter
        << "\n��������:\n";
    cout << fixed << setprecision(1);
    for (int i = 0; i < student.numSubjects; ++i) {
        cout << "  " << student.subjects[i].name << ": " << student.subjects[i].grade << "\n";
    }
    cout << "������� ����: " << student.average << "\n\n";
}

vector<Student> readStudentsFromFile(const string& filename) {
    vector<Student> students;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "������ �������� �����!\n";
        return students;
    }

    string line;
    int lineNum = 0;

    while (getline(inFile, line)) {
        lineNum++;
        Student student;
        student.numSubjects = 0;
        float sum = 0;
        bool isValid = true;

        vector<string> parts;
        stringstream ss(line);
        string part;

        // ��������� ������ �� ����� �� ';'
        while (getline(ss, part, ';')) {
            parts.push_back(part);
        }

        // ����������� ���������� ������: ���, �����, ������� ����
        if (parts.size() < 3) {
            cerr << "������ � ������ " << lineNum << ": �������� ������ ������\n";
            continue;
        }

        // ��������� ���
        if (!isValidName(parts[0])) {
            cerr << "������ � ������ " << lineNum << ": ������������ ���\n";
            continue;
        }
        strncpy(student.fullName, parts[0].c_str(), 99);
        student.fullName[99] = '\0';

        // ��������� ������
        if (!isValidClass(parts[1])) {
            cerr << "������ � ������ " << lineNum << ": ������������ �����\n";
            continue;
        }
        size_t i = 0;
        student.classInfo.number = 0;
        while (i < parts[1].size() && isdigit(parts[1][i])) {
            student.classInfo.number = student.classInfo.number * 10 + (parts[1][i] - '0');
            i++;
        }
        student.classInfo.letter = toupper(parts[1][i]);

        // ��������� ��������� � ������
        for (size_t j = 2; j < parts.size() - 1; ++j) {
            if (student.numSubjects >= 10) {
                cerr << "������ � ������ " << lineNum << ": ������� ����� ���������\n";
                isValid = false;
                break;
            }

            size_t colonPos = parts[j].find_last_of(':');
            if (colonPos == string::npos) {
                cerr << "������ � ������ " << lineNum << ": �������� ������ ��������\n";
                isValid = false;
                break;
            }

            string subject = parts[j].substr(0, colonPos);
            string gradeStr = parts[j].substr(colonPos + 1);

            try {
                replace(gradeStr.begin(), gradeStr.end(), '.', ',');
                float grade = stof(gradeStr);
                grade = round(grade * 10) / 10;

                if (!isValidGrade(grade)) {
                    cerr << "������ � ������ " << lineNum << ": ������������ ������\n";
                    isValid = false;
                    break;
                }

                strncpy(student.subjects[student.numSubjects].name, subject.c_str(), 49);
                student.subjects[student.numSubjects].name[49] = '\0';
                student.subjects[student.numSubjects].grade = grade;
                sum += grade;
                student.numSubjects++;
            }
            catch (...) {
                cerr << "������ � ������ " << lineNum << ": ������ ������� ������\n";
                isValid = false;
                break;
            }
        }

        // ��������� �������� �����
        if (isValid) {
            try {
                replace(parts.back().begin(), parts.back().end(), '.', ',');
                student.average = stof(parts.back());
            }
            catch (...) {
                cerr << "������ � ������ " << lineNum << ": ������ ������� �������� �����\n";
                isValid = false;
            }
        }

        if (isValid) {
            students.push_back(student);
        }
        else {
            cerr << "������ " << lineNum << " ��������� ��-�� ������\n";
        }
    }

    inFile.close();
    return students;
}

void searchByLastName(const vector<Student>& students, const string& lastName) {
    bool found = false;
    for (const auto& student : students) {
        istringstream iss(student.fullName);
        string currentLastName;
        iss >> currentLastName;
        if (currentLastName == lastName) {
            printStudent(student);
            found = true;
        }
    }
    if (!found) {
        cout << "������� � �������� '" << lastName << "' �� �������.\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    locale::global(locale("Russian_Russia.1251"));
    cout.imbue(locale());
    cin.imbue(locale());
    setlocale(LC_ALL, "Russian");

    vector<Student> students;
    const string filename = "students.txt";

    while (true) {
        cout << "\n=== ���� ���������� ===\n";
        cout << "1. �������� �������\n";
        cout << "2. ��������� ���� � ����\n";
        cout << "3. ��������� �� �����\n";
        cout << "4. �������� ����\n";
        cout << "5. ����� �� �������\n";
        cout << "6. �����\n";

        int choice;
        while (true) {
            cout << "�������� �������� (1-6): ";
            cin >> choice;
            clearCinBuffer();

            if (choice >= 1 && choice <= 6) break;
            cout << "������������ �����! ���������� �����.\n";
        }

        switch (choice) {
        case 1: {
            Student newStudent;
            inputStudent(newStudent);
            students.push_back(newStudent);
            cout << "������ ������� ��������!\n";
            break;
        }
        case 2: {
            ofstream outFile(filename, ios::app);
            if (!outFile) {
                cerr << "������ �������� ����� ��� ������!\n";
                break;
            }
            for (const auto& s : students) {
                writeStudentToFile(s, outFile);
            }
            outFile.close();
            students.clear();
            cout << "������ ������� ��������� � ����!\n";
            break;
        }
        case 3: {
            students = readStudentsFromFile(filename);
            cout << "��������� ��������: " << students.size() << "\n";
            break;
        }
        case 4: {
            if (students.empty()) {
                cout << "������ �������� ����.\n";
            }
            else {
                cout << "\n=== ������ ���� �������� ===\n";
                for (const auto& s : students) {
                    printStudent(s);
                }
            }
            break;
        }
        case 5: {
            string lastName;
            cout << "������� ������� ��� ������: ";
            getline(cin, lastName);
            searchByLastName(students, lastName);
            break;
        }
        case 6: {
            cout << "����� �� ���������...\n";
            return 0;
        }
        }
    }
}