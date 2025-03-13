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
    return (c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё';
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
        cout << "Введите ФИО ученика: ";
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
            cout << "Ошибка! Используйте только русские буквы, пробелы и дефисы. Введите как минимум фамилию и имя\n";
        }
    } while (!isValidName(student.fullName));

    string classStr;
    do {
        cout << "Введите класс (1-11 число + русская буква, например 10А): ";
        getline(cin, classStr);
        if (!isValidClass(classStr)) {
            cout << "Ошибка! Пример правильного формата: 9Б\n";
        }
    } while (!isValidClass(classStr));

    size_t i = 0;
    student.classInfo.number = 0;
    while (i < classStr.size() && isdigit(classStr[i])) {
        student.classInfo.number = student.classInfo.number * 10 + (classStr[i] - '0');
        i++;
    }
    student.classInfo.letter = toupper(classStr[i]);

    cout << "Введите предметы и оценки (максимум 10, формат: 'Математика 8,5'):\n";
    student.numSubjects = 0;
    while (student.numSubjects < 10) {
        cout << "Предмет #" << student.numSubjects + 1 << " (или Enter для завершения): ";
        string line;
        getline(cin, line);
        if (line.empty()) break;

        size_t last_space = line.find_last_of(" ");
        if (last_space == string::npos) {
            cout << "Ошибка формата! Используйте: 'Название предмета Оценка'\n";
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
            cout << "Ошибка формата оценки! Пример: 7,5\n";
            continue;
        }

        if (subject.length() >= 50) {
            cout << "Слишком длинное название предмета! Максимум 49 символов.\n";
            continue;
        }

        if (!isValidGrade(grade)) {
            cout << "Некорректная оценка! Допустимо от 1,0 до 10,0.\n";
            continue;
        }

        if (isSubjectExists(student, subject)) {
            cout << "Этот предмет уже существует! Введите другой.\n";
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
    cout << "\nФИО: " << student.fullName
        << "\nКласс: " << student.classInfo.number << student.classInfo.letter
        << "\nПредметы:\n";
    cout << fixed << setprecision(1);
    for (int i = 0; i < student.numSubjects; ++i) {
        cout << "  " << student.subjects[i].name << ": " << student.subjects[i].grade << "\n";
    }
    cout << "Средний балл: " << student.average << "\n\n";
}

vector<Student> readStudentsFromFile(const string& filename) {
    vector<Student> students;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Ошибка открытия файла!\n";
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

        // Разбиваем строку на части по ';'
        while (getline(ss, part, ';')) {
            parts.push_back(part);
        }

        // Минимальное количество частей: ФИО, класс, средний балл
        if (parts.size() < 3) {
            cerr << "Ошибка в строке " << lineNum << ": Неверный формат данных\n";
            continue;
        }

        // Обработка ФИО
        if (!isValidName(parts[0])) {
            cerr << "Ошибка в строке " << lineNum << ": Некорректное ФИО\n";
            continue;
        }
        strncpy(student.fullName, parts[0].c_str(), 99);
        student.fullName[99] = '\0';

        // Обработка класса
        if (!isValidClass(parts[1])) {
            cerr << "Ошибка в строке " << lineNum << ": Некорректный класс\n";
            continue;
        }
        size_t i = 0;
        student.classInfo.number = 0;
        while (i < parts[1].size() && isdigit(parts[1][i])) {
            student.classInfo.number = student.classInfo.number * 10 + (parts[1][i] - '0');
            i++;
        }
        student.classInfo.letter = toupper(parts[1][i]);

        // Обработка предметов и оценок
        for (size_t j = 2; j < parts.size() - 1; ++j) {
            if (student.numSubjects >= 10) {
                cerr << "Ошибка в строке " << lineNum << ": Слишком много предметов\n";
                isValid = false;
                break;
            }

            size_t colonPos = parts[j].find_last_of(':');
            if (colonPos == string::npos) {
                cerr << "Ошибка в строке " << lineNum << ": Неверный формат предмета\n";
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
                    cerr << "Ошибка в строке " << lineNum << ": Некорректная оценка\n";
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
                cerr << "Ошибка в строке " << lineNum << ": Ошибка формата оценки\n";
                isValid = false;
                break;
            }
        }

        // Обработка среднего балла
        if (isValid) {
            try {
                replace(parts.back().begin(), parts.back().end(), '.', ',');
                student.average = stof(parts.back());
            }
            catch (...) {
                cerr << "Ошибка в строке " << lineNum << ": Ошибка формата среднего балла\n";
                isValid = false;
            }
        }

        if (isValid) {
            students.push_back(student);
        }
        else {
            cerr << "Строка " << lineNum << " пропущена из-за ошибок\n";
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
        cout << "Ученики с фамилией '" << lastName << "' не найдены.\n";
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
        cout << "\n=== Меню управления ===\n";
        cout << "1. Добавить ученика\n";
        cout << "2. Сохранить всех в файл\n";
        cout << "3. Загрузить из файла\n";
        cout << "4. Показать всех\n";
        cout << "5. Поиск по фамилии\n";
        cout << "6. Выход\n";

        int choice;
        while (true) {
            cout << "Выберите действие (1-6): ";
            cin >> choice;
            clearCinBuffer();

            if (choice >= 1 && choice <= 6) break;
            cout << "Некорректный выбор! Попробуйте снова.\n";
        }

        switch (choice) {
        case 1: {
            Student newStudent;
            inputStudent(newStudent);
            students.push_back(newStudent);
            cout << "Ученик успешно добавлен!\n";
            break;
        }
        case 2: {
            ofstream outFile(filename, ios::app);
            if (!outFile) {
                cerr << "Ошибка открытия файла для записи!\n";
                break;
            }
            for (const auto& s : students) {
                writeStudentToFile(s, outFile);
            }
            outFile.close();
            students.clear();
            cout << "Данные успешно сохранены в файл!\n";
            break;
        }
        case 3: {
            students = readStudentsFromFile(filename);
            cout << "Загружено учеников: " << students.size() << "\n";
            break;
        }
        case 4: {
            if (students.empty()) {
                cout << "Список учеников пуст.\n";
            }
            else {
                cout << "\n=== Список всех учеников ===\n";
                for (const auto& s : students) {
                    printStudent(s);
                }
            }
            break;
        }
        case 5: {
            string lastName;
            cout << "Введите фамилию для поиска: ";
            getline(cin, lastName);
            searchByLastName(students, lastName);
            break;
        }
        case 6: {
            cout << "Выход из программы...\n";
            return 0;
        }
        }
    }
}