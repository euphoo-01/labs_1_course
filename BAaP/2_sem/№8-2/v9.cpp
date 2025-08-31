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
        cout << "������: ������� �����������!" << endl;
        return false;
    }

    q.rear = (q.rear + 1) % q.capacity;
    q.data[q.rear] = value;
    q.size++;
    return true;
}

bool dequeue(Queue& q, int& value) {
    if (isEmpty(q)) {
        cout << "������: ������� �����!" << endl;
        return false;
    }

    value = q.data[q.front];
    q.front = (q.front + 1) % q.capacity;
    q.size--;
    return true;
}

void printQueue(const Queue& q) {
    if (isEmpty(q)) {
        cout << "������� �����" << endl;
        return;
    }

    cout << "�������� �������: ";
    for (int i = 0; i < q.size; i++) {
        int idx = (q.front + i) % q.capacity;
        cout << q.data[idx] << " ";
    }
    cout << endl;
}

// ������� ��� �������� ����� ������ �����
bool getValidInt(int& value, const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    // ������� ������� �� ������
    string noSpaces;
    for (char c : input) {
        if (c != ' ') noSpaces += c;
    }

    if (noSpaces.empty()) return false;

    // ��������, ��� ������ �������� ������ ����� � �������� ���� ����� � ������
    bool isValid = true;
    if (noSpaces[0] == '-' || noSpaces[0] == '+') {
        if (noSpaces.length() == 1) return false; // ������ ���� ��� �����
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

    // �������� �� ������������
    try {
        value = stoi(noSpaces);
        return true;
    }
    catch (out_of_range&) {
        cout << "������: ����� ��� ����������� ���������" << endl;
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
        valid = getValidInt(n, "������� ���������� ��������� ��� ����������: ");
        if (!valid) cout << "������ �����. ����������, ������� ����� �����." << endl;
        else if (n <= 0) {
            cout << "������: ���������� ������ ���� ������������� ������." << endl;
            valid = false;
        }
    } while (!valid);

    if (n > q.capacity - q.size) {
        cout << "��������������: ����� �������� ������ " << (q.capacity - q.size) << " ���������" << endl;
        n = q.capacity - q.size;
    }

    cout << "������� " << n << " ��������� (����� ������ ��� �� ������):" << endl;

    string line;
    getline(cin, line);

    if (line.empty()) {
        // ���� �� ������ �����
        int count = 0;
        while (count < n) {
            int val;
            if (getValidInt(val, "")) {
                enqueue(q, val);
                count++;
            }
            else if (!cin.eof()) {
                cout << "������ �����. ����������, ������� ����� �����." << endl;
            }
        }
    }
    else {
        // ���� ����� ������
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
                cout << "��������������: '" << token << "' �� �������� ����� ������ � ����� ���������." << endl;
            }
        }

        // ���� ���� ������� ������ �����, ��� �����������
        if (count < n) {
            cout << "���� ������� ������ " << count << " �� " << n << " �����." << endl;
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
        cout << "\n===== ���� ������ � �������� =====\n"
            << "1. ������������� �������\n"
            << "2. �������� �������\n"
            << "3. ������� �������\n"
            << "4. ������� ��������\n"
            << "5. ������ ��������� ���������\n"
            << "6. �������� ������ �������\n"
            << "7. ��������� �� ������/��������\n"
            << "8. ������� ����������� �������\n"
            << "0. �����\n"
            << "�������� ��������: ";

        // ������� ����� ����� ����� ������ ����� ������
        cin.clear();
        getline(cin, input);

        // ��������� ������ ������ ����
        try {
            choice = stoi(input);
        }
        catch (exception&) {
            choice = -1; // ��������, ������� ������� default � switch
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
                validSize = getValidInt(maxSize, "������� ������������ ������ �������: ");
                if (!validSize) {
                    cout << "������ �����. ������� ����� ������������� �����." << endl;
                    continue;
                }

                if (maxSize <= 0) {
                    cout << "������ ������ ���� ������������� ������!" << endl;
                    validSize = false;
                }
            } while (!validSize);

            initQueue(mainQ, maxSize);
            init = true;
            cout << "������� ����������������" << endl;
            break;
        }

        case 2: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            int val;
            bool validVal = false;

            do {
                validVal = getValidInt(val, "������� ��������: ");
                if (!validVal) cout << "������ �����. ������� ����� �����." << endl;
            } while (!validVal);

            if (enqueue(mainQ, val))
                cout << "������� ��������" << endl;
            break;
        }

        case 3: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            int val;
            if (dequeue(mainQ, val))
                cout << "�������� �������: " << val << endl;
            break;
        }

        case 4: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            printQueue(mainQ);
            break;
        }

        case 5: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            inputQueue(mainQ);
            break;
        }

        case 6: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            cout << "������� ������: " << getSize(mainQ) << endl;
            cout << "������������ ������: " << mainQ.capacity << endl;
            break;
        }

        case 7: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            if (isEmpty(mainQ)) {
                cout << "������� �����, ������ ���������" << endl;
                break;
            }

            if (evenQ.data) freeQueue(evenQ);
            if (oddQ.data) freeQueue(oddQ);

            initQueue(evenQ, mainQ.capacity);
            initQueue(oddQ, mainQ.capacity);

            splitQueue(mainQ, evenQ, oddQ);

            cout << "������� ��������� �� ���" << endl;
            break;
        }

        case 8: {
            if (!init) {
                cout << "������� ��������������� ������� (����� 1)" << endl;
                break;
            }

            if (!evenQ.data || !oddQ.data) {
                cout << "������� ��������� ������� (����� 7)" << endl;
                break;
            }

            cout << "Queue1 (������): ";
            printQueue(evenQ);

            cout << "Queue2 (��������): ";
            printQueue(oddQ);
            break;
        }

        case 0:
            cout << "��������� ���������" << endl;
            break;

        default:
            cout << "�������� �����. ������� ����� �� 0 �� 8." << endl;
        }

    } while (choice != 0);

    if (init) {
        freeQueue(mainQ);
        if (evenQ.data) freeQueue(evenQ);
        if (oddQ.data) freeQueue(oddQ);
    }

    return 0;
}