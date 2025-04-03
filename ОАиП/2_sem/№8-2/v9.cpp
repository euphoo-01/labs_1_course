#include <iostream>
#include <Windows.h>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

struct Queue {
    int* data;
    int capacity;
    int front;
    int rear;
    int size;
};

void initQueue(Queue& q, int capacity) {
    q.data = new int[capacity];
    q.capacity = capacity;
    q.front = 0;
    q.rear = -1;
    q.size = 0;
}

void freeQueue(Queue& q) {
    delete[] q.data;
    q.data = nullptr;
    q.size = 0;
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(const Queue& q) { return q.size == 0; }
bool isFull(const Queue& q) { return q.size == q.capacity; }
int getSize(const Queue& q) { return q.size; }

bool enqueue(Queue& q, int value) {
    if (isFull(q)) {
        cout << "Ошибка: очередь переполнена!" << endl;
        return false;
    }

    q.rear = (q.rear + 1) % q.capacity;
    q.data[q.rear] = value;
    q.size++;
    return true;
}

bool dequeue(Queue& q, int& value) {
    if (isEmpty(q)) {
        cout << "Ошибка: очередь пуста!" << endl;
        return false;
    }

    value = q.data[q.front];
    q.front = (q.front + 1) % q.capacity;
    q.size--;
    return true;
}

void printQueue(const Queue& q) {
    if (isEmpty(q)) {
        cout << "Очередь пуста" << endl;
        return;
    }

    cout << "Элементы очереди: ";
    for (int i = 0; i < q.size; i++) {
        int idx = (q.front + i) % q.capacity;
        cout << q.data[idx] << " ";
    }
    cout << endl;
}

// Функция для проверки ввода целого числа
bool getValidInt(int& value, const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    // Удаляем пробелы из строки
    string noSpaces;
    for (char c : input) {
        if (c != ' ') noSpaces += c;
    }

    if (noSpaces.empty()) return false;

    // Проверка, что строка содержит только цифры и возможно знак минус в начале
    bool isValid = true;
    if (noSpaces[0] == '-' || noSpaces[0] == '+') {
        if (noSpaces.length() == 1) return false; // Только знак без числа
        for (size_t i = 1; i < noSpaces.length(); i++) {
            if (!isdigit(noSpaces[i])) {
                isValid = false;
                break;
            }
        }
    }
    else {
        for (char c : noSpaces) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }
    }

    if (!isValid) return false;

    // Проверка на переполнение
    try {
        value = stoi(noSpaces);
        return true;
    }
    catch (out_of_range&) {
        cout << "Ошибка: число вне допустимого диапазона" << endl;
        return false;
    }
    catch (exception&) {
        return false;
    }
}

void inputQueue(Queue& q) {
    int n;
    bool valid = false;

    do {
        valid = getValidInt(n, "Введите количество элементов для добавления: ");
        if (!valid) cout << "Ошибка ввода. Пожалуйста, введите целое число." << endl;
        else if (n <= 0) {
            cout << "Ошибка: количество должно быть положительным числом." << endl;
            valid = false;
        }
    } while (!valid);

    if (n > q.capacity - q.size) {
        cout << "Предупреждение: можно добавить только " << (q.capacity - q.size) << " элементов" << endl;
        n = q.capacity - q.size;
    }

    cout << "Введите " << n << " элементов (через пробел или по одному):" << endl;

    string line;
    getline(cin, line);

    if (line.empty()) {
        // Ввод по одному числу
        int count = 0;
        while (count < n) {
            int val;
            if (getValidInt(val, "")) {
                enqueue(q, val);
                count++;
            }
            else if (!cin.eof()) {
                cout << "Ошибка ввода. Пожалуйста, введите целое число." << endl;
            }
        }
    }
    else {
        // Ввод через пробел
        istringstream iss(line);
        string token;
        int count = 0;

        while (iss >> token && count < n) {
            try {
                int val = stoi(token);
                enqueue(q, val);
                count++;
            }
            catch (exception&) {
                cout << "Предупреждение: '" << token << "' не является целым числом и будет пропущено." << endl;
            }
        }

        // Если было введено меньше чисел, чем требовалось
        if (count < n) {
            cout << "Было введено только " << count << " из " << n << " чисел." << endl;
        }
    }
}

void splitQueue(const Queue& src, Queue& even, Queue& odd) {
    Queue temp;
    initQueue(temp, src.capacity);

    for (int i = 0; i < src.size; i++)
        enqueue(temp, src.data[(src.front + i) % src.capacity]);

    int val;
    while (!isEmpty(temp)) {
        dequeue(temp, val);
        (val % 2 == 0) ? enqueue(even, val) : enqueue(odd, val);
    }

    freeQueue(temp);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Queue mainQ, evenQ, oddQ;
    int maxSize;
    bool init = false;
    int choice;
    string input;

    do {
        cout << "\n===== МЕНЮ РАБОТЫ С ОЧЕРЕДЬЮ =====\n"
            << "1. Инициализация очереди\n"
            << "2. Добавить элемент\n"
            << "3. Извлечь элемент\n"
            << "4. Вывести элементы\n"
            << "5. Ввести несколько элементов\n"
            << "6. Получить размер очереди\n"
            << "7. Разделить на четные/нечетные\n"
            << "8. Вывести разделенные очереди\n"
            << "0. Выход\n"
            << "Выберите действие: ";

        // Очищаем буфер ввода перед каждым новым вводом
        cin.clear();
        getline(cin, input);

        // Валидация выбора пункта меню
        try {
            choice = stoi(input);
        }
        catch (exception&) {
            choice = -1; // Значение, которое вызовет default в switch
        }

        switch (choice) {
        case 1: {
            if (init) {
                freeQueue(mainQ);
                if (evenQ.data) freeQueue(evenQ);
                if (oddQ.data) freeQueue(oddQ);
            }

            bool validSize = false;
            do {
                validSize = getValidInt(maxSize, "Введите максимальный размер очереди: ");
                if (!validSize) {
                    cout << "Ошибка ввода. Введите целое положительное число." << endl;
                    continue;
                }

                if (maxSize <= 0) {
                    cout << "Размер должен быть положительным числом!" << endl;
                    validSize = false;
                }
            } while (!validSize);

            initQueue(mainQ, maxSize);
            init = true;
            cout << "Очередь инициализирована" << endl;
            break;
        }

        case 2: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            int val;
            bool validVal = false;

            do {
                validVal = getValidInt(val, "Введите значение: ");
                if (!validVal) cout << "Ошибка ввода. Введите целое число." << endl;
            } while (!validVal);

            if (enqueue(mainQ, val))
                cout << "Элемент добавлен" << endl;
            break;
        }

        case 3: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            int val;
            if (dequeue(mainQ, val))
                cout << "Извлечен элемент: " << val << endl;
            break;
        }

        case 4: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            printQueue(mainQ);
            break;
        }

        case 5: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            inputQueue(mainQ);
            break;
        }

        case 6: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            cout << "Текущий размер: " << getSize(mainQ) << endl;
            cout << "Максимальный размер: " << mainQ.capacity << endl;
            break;
        }

        case 7: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            if (isEmpty(mainQ)) {
                cout << "Очередь пуста, нечего разделять" << endl;
                break;
            }

            if (evenQ.data) freeQueue(evenQ);
            if (oddQ.data) freeQueue(oddQ);

            initQueue(evenQ, mainQ.capacity);
            initQueue(oddQ, mainQ.capacity);

            splitQueue(mainQ, evenQ, oddQ);

            cout << "Очередь разделена на две" << endl;
            break;
        }

        case 8: {
            if (!init) {
                cout << "Сначала инициализируйте очередь (пункт 1)" << endl;
                break;
            }

            if (!evenQ.data || !oddQ.data) {
                cout << "Сначала разделите очередь (пункт 7)" << endl;
                break;
            }

            cout << "Queue1 (четные): ";
            printQueue(evenQ);

            cout << "Queue2 (нечетные): ";
            printQueue(oddQ);
            break;
        }

        case 0:
            cout << "Программа завершена" << endl;
            break;

        default:
            cout << "Неверный выбор. Введите число от 0 до 8." << endl;
        }

    } while (choice != 0);

    if (init) {
        freeQueue(mainQ);
        if (evenQ.data) freeQueue(evenQ);
        if (oddQ.data) freeQueue(oddQ);
    }

    return 0;
}