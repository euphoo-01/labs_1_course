#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct AVIALINES {
    int flightNumber;      // Номер рейса
    string destination;    // Пункт назначения
    string departureTime;  // Время вылета
    string departureDate;  // Дата вылета
    double ticketPrice;    // Стоимость билета
    int seatCount;         // Количество мест
};

const int MAX_LINES = 100;
AVIALINES lines[MAX_LINES];
int lineCount = 0;

void addLine();
void displayLines();
void deleteLine();
void searchLine();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    setlocale(LC_ALL, "rus");
    do {
        cout << "1 - Добавить рейс\n";
        cout << "2 - Показать все рейсы\n";
        cout << "3 - Удалить рейс\n";
        cout << "4 - Поиск рейса по пункту назначения\n";
        cout << "5 - Сохранить в файл\n";
        cout << "6 - Загрузить из файла\n";
        cout << "7 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addLine(); 
            break;
        case 2: 
            displayLines();
            break;
        case 3:
            deleteLine(); 
            break;
        case 4: 
            searchLine();
            break;
        case 5: 
            saveToFile();
            break;
        case 6:
            loadFromFile();
            break;
        case 7: 
            cout << "Выход из программы.\n"; 
            break;
        default: 
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}

void addLine() {
    if (lineCount >= MAX_LINES) {
        cout << "Массив заполнен. Невозможно добавить больше рейсов.\n";
        return;
    }
    AVIALINES line;
    cout << "Введите номер рейса: ";
    cin >> line.flightNumber;
    cin.ignore();
    cout << "Введите пункт назначения: ";
    getline(cin, line.destination);
    cout << "Введите время вылета (чч:мм): ";
    getline(cin, line.departureTime);
    cout << "Введите дату вылета (дд.мм.гггг): ";
    getline(cin, line.departureDate);
    cout << "Введите стоимость билета: ";
    cin >> line.ticketPrice;
    cout << "Введите количество мест: ";
    cin >> line.seatCount;

    lines[lineCount++] = line;
    cout << "Рейc добавлен!\n";
}

void displayLines() {
    if (lineCount == 0) {
        cout << "Список рейсов пуст.\n";
        return;
    }
    for (int i = 0; i < lineCount; i++) {
        cout << "\nРейс #" << i + 1 << ":\n";
        cout << "Номер рейса: " << lines[i].flightNumber << "\n";
        cout << "Пункт назначения: " << lines[i].destination << "\n";
        cout << "Время вылета: " << lines[i].departureTime << "\n";
        cout << "Дата вылета: " << lines[i].departureDate << "\n";
        cout << "Стоимость билета: " << lines[i].ticketPrice << "\n";
        cout << "Количество мест: " << lines[i].seatCount << "\n";
    }
}

void deleteLine() {
    int flightNumber;
    cout << "Введите номер рейса для удаления: ";
    cin >> flightNumber;
    int index = -1;
    for (int i = 0; i < lineCount; i++) {
        if (lines[i].flightNumber == flightNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Рейс с таким номером не найден :/\n";
        return;
    }
    for (int i = index; i < lineCount - 1; i++) {
        lines[i] = lines[i + 1];
    }
    --lineCount;
    cout << "Рейс успешно удален.\n";
}

void searchLine() {
    string destination;
    cout << "Введите пункт назначения для поиска: ";
    cin.ignore();
    getline(cin, destination);

    bool isFound = false;
    for (int i = 0; i < lineCount; i++) {
        if (lines[i].destination == destination) {
            cout << "\nНайден рейс:\n";
            cout << "Номер рейса: " << lines[i].flightNumber << "\n";
            cout << "Время вылета: " << lines[i].departureTime << "\n";
            cout << "Дата вылета: " << lines[i].departureDate << "\n";
            cout << "Стоимость билета: " << lines[i].ticketPrice << "\n";
            cout << "Количество мест: " << lines[i].seatCount << "\n";
            isFound = true;
        }
    }

    if (!isFound) {
        cout << "Рейсы с таким пунктом назначения не найдены.\n";
    }
}

void saveToFile() {
    ofstream file("avialines.txt");
    if (!file) {
        cout << "Ошибка при открытии файла.\n";
        return;
    }
    file << lineCount << "\n";
    for (int i = 0; i < lineCount; i++) {
        file << lines[i].flightNumber << "\n"
            << lines[i].destination << "\n"
            << lines[i].departureTime << "\n"
            << lines[i].departureDate << "\n"
            << lines[i].ticketPrice << "\n"
            << lines[i].seatCount << "\n";
    }
    file.close();
    cout << "Данные успешно сохранены в файл.\n";
}

void loadFromFile() {
    ifstream file("lines.txt");
    if (!file) {
        cout << "Ошибка при открытии файла.\n";
        return;
    }
    file >> lineCount;
    file.ignore();
    for (int i = 0; i < lineCount; i++) {
        file >> lines[i].flightNumber;
        file.ignore();
        getline(file, lines[i].destination);
        getline(file, lines[i].departureTime);
        getline(file, lines[i].departureDate);
        file >> lines[i].ticketPrice;
        file >> lines[i].seatCount;
        file.ignore();
    }
    file.close();
    cout << "Данные успешно загружены из файла.\n";
}
