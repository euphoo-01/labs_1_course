#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

struct list {
    double number;
    list* next;
};

bool isValidNumber(const string& s) {
    if (s.empty()) return false;

    size_t start = 0;
    if (s[0] == '-') {
        start = 1;
        if (s.size() == 1) return false;
    }

    bool hasDecimalPoint = false;
    bool hasDigits = false;

    for (size_t i = start; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (hasDecimalPoint) return false;
            hasDecimalPoint = true;
        }
        else if (!isdigit(s[i])) {
            return false;
        }
        else {
            hasDigits = true;
        }
    }

    if (!hasDigits) return false;
    if (hasDecimalPoint && s.size() == start + 1 && s[start] == '.') return false;

    return true;
}

void insert(list*&, double);
void del(list*&, double);
list* find(list*, double);
bool isEmpty(list*);
void print(list*);
void menu();
void avgOfNegative(list*);
void saveToFile(list*, const string&);
void loadFromFile(list*&, const string&);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* first = nullptr;
    int choice = -1;
    string input;
    string filename = "list.txt";

    cout << "ВНИМАНИЕ! Разделитель целой и дробной части - точка!" << endl;

    while (choice != 0) {
        menu();
        cout << "Ваш выбор: ";
        getline(cin, input);
        if (!all_of(input.begin(), input.end(), ::isdigit)) {
            cerr << "Ошибка! Введите число" << endl;
            continue;
        }
        choice = stoi(input);
        switch (choice) {
        case 1: {
            string num_input;
            double num;
            cout << "Введите число для вставки: ";
            getline(cin, num_input);
            if (!isValidNumber(num_input)) {
                cerr << "Ошибка! Введите корректное число" << endl;
                break;
            }
            num = stod(num_input);
            insert(first, num);
            break;
        }
        case 2: {
            string num_input;
            double num;
            cout << "Введите число для удаления: ";
            getline(cin, num_input);
            if (!isValidNumber(num_input)) {
                cerr << "Ошибка! Введите корректное число" << endl;
                break;
            }
            num = stod(num_input);
            if (find(first, num)) {
                del(first, num);
            }
            else {
                cerr << "Элемент не найден!" << endl;
            }
            break;
        }
        case 3: {
            string num_input;
            double num;
            cout << "Введите число для поиска: ";
            getline(cin, num_input);
            if (!isValidNumber(num_input)) {
                cerr << "Ошибка! Введите корректное число" << endl;
                break;
            }
            num = stod(num_input);
            list* result = find(first, num);
            if (result) {
                cout << "Число найдено по адресу: " << result << endl;
            }
            else {
                cerr << "Элемент не найден!" << endl;
            }
            break;
        }
        case 4:
            print(first);
            break;
        case 5:
            saveToFile(first, filename);
            break;
        case 6:
            loadFromFile(first, filename);
            break;
        case 7:
            avgOfNegative(first);
            break;
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    }

    while (first) {
        del(first, first->number);
    }

    return 0;
}

void menu() {
    cout << "------МЕНЮ------" << endl;
    cout << "1. Добавить элемент" << endl
        << "2. Удалить элемент" << endl
        << "3. Найти элемент" << endl
        << "4. Вывести список" << endl
        << "5. Сохранить в файл" << endl
        << "6. Загрузить из файла" << endl
        << "7. Среднее отрицательных элементов" << endl
        << "0. Выход" << endl;
}

void insert(list*& begin, double value) {
    list* newNode = new list{ value, begin };
    begin = newNode;
}

void del(list*& begin, double value) {
    if (!begin) return;

    list* current = begin;
    list* previous = nullptr;

    while (current && current->number != value) {
        previous = current;
        current = current->next;
    }

    if (!current) return;

    if (previous) {
        previous->next = current->next;
    }
    else {
        begin = current->next;
    }

    delete current;
}

list* find(list* begin, double value) {
    list* current = begin;
    while (current) {
        if (current->number == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool isEmpty(list* begin) {
    return begin == nullptr;
}

void print(list* begin) {
    if (isEmpty(begin)) {
        cout << "Список пуст!" << endl;
        return;
    }

    list* current = begin;
    while (current) {
        cout << current->number << " ";
        current = current->next;
    }
    cout << endl;
}

void saveToFile(list* begin, const string& filename) {
    ofstream fout(filename);
    fout.imbue(locale::classic());
    if (!fout) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    list* current = begin;
    while (current) {
        fout << current->number << endl;
        current = current->next;
    }
    fout.close();
    cout << "Список сохранён в файл." << endl;
}

void loadFromFile(list*& begin, const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    while (begin) {
        del(begin, begin->number);
    }

    string line;
    while (getline(fin, line)) {
        replace(line.begin(), line.end(), ',', '.');
        if (!isValidNumber(line)) {
            cerr << "Ошибка! Некорректные данные в файле: " << line << endl;
            fin.close();
            return;
        }
        try {
            double value = stod(line);
            insert(begin, value);
        }
        catch (...) {
            cerr << "Ошибка при чтении числа: " << line << endl;
            fin.close();
            return;
        }
    }

    fin.close();
    cout << "Список загружен из файла." << endl;
}

void avgOfNegative(list* begin) {
    double sum = 0;
    int i = 0;
    list* current = begin;
    while (current) {
        if (current->number < 0) {
            sum += current->number;
            i++;
        }
        current = current->next;
    }
    cout << "Среднее отрицательных элементов: " << sum / i << endl;
}