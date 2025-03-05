#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Определение структуры AVIALINES
struct AVIALINES {
    int flightNumber;      // Номер рейса
    string destination;    // Пункт назначения
    string departureTime;  // Время вылета
    string departureDate;  // Дата вылета
    double ticketPrice;    // Стоимость билета
    int seatCount;         // Количество мест
};

// Константы
const int MAX_FLIGHTS = 100;
AVIALINES flights[MAX_FLIGHTS];
int flightCount = 0;

// Функции
void addFlight();
void displayFlights();
void deleteFlight();
void searchFlight();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    setlocale(LC_ALL, "rus");
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить рейс\n";
        cout << "2. Показать все рейсы\n";
        cout << "3. Удалить рейс\n";
        cout << "4. Поиск рейса по пункту назначения\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: addFlight(); break;
        case 2: displayFlights(); break;
        case 3: deleteFlight(); break;
        case 4: searchFlight(); break;
        case 5: saveToFile(); break;
        case 6: loadFromFile(); break;
        case 0: cout << "Выход из программы.\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}

// Функция для добавления рейса
void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
        cout << "Массив заполнен. Невозможно добавить больше рейсов.\n";
        return;
    }
    AVIALINES flight;
    cout << "Введите номер рейса: ";
    cin >> flight.flightNumber;
    cin.ignore();
    cout << "Введите пункт назначения: ";
    getline(cin, flight.destination);
    cout << "Введите время вылета (чч:мм): ";
    getline(cin, flight.departureTime);
    cout << "Введите дату вылета (дд.мм.гггг): ";
    getline(cin, flight.departureDate);
    cout << "Введите стоимость билета: ";
    cin >> flight.ticketPrice;
    cout << "Введите количество мест: ";
    cin >> flight.seatCount;

    flights[flightCount++] = flight;
    cout << "Рейс успешно добавлен!\n";
}

// Функция для отображения всех рейсов
void displayFlights() {
    if (flightCount == 0) {
        cout << "Список рейсов пуст.\n";
        return;
    }
    for (int i = 0; i < flightCount; ++i) {
        cout << "\nРейс #" << i + 1 << ":\n";
        cout << "Номер рейса: " << flights[i].flightNumber << "\n";
        cout << "Пункт назначения: " << flights[i].destination << "\n";
        cout << "Время вылета: " << flights[i].departureTime << "\n";
        cout << "Дата вылета: " << flights[i].departureDate << "\n";
        cout << "Стоимость билета: " << flights[i].ticketPrice << "\n";
        cout << "Количество мест: " << flights[i].seatCount << "\n";
    }
}

// Функция для удаления рейса
void deleteFlight() {
    int flightNumber;
    cout << "Введите номер рейса для удаления: ";
    cin >> flightNumber;

    int index = -1;
    for (int i = 0; i < flightCount; ++i) {
        if (flights[i].flightNumber == flightNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Рейс с таким номером не найден.\n";
        return;
    }

    for (int i = index; i < flightCount - 1; ++i) {
        flights[i] = flights[i + 1];
    }
    --flightCount;
    cout << "Рейс успешно удален.\n";
}

// Функция для поиска рейса по пункту назначения
void searchFlight() {
    string destination;
    cout << "Введите пункт назначения для поиска: ";
    cin.ignore();
    getline(cin, destination);

    bool found = false;
    for (int i = 0; i < flightCount; ++i) {
        if (flights[i].destination == destination) {
            cout << "\nНайден рейс:\n";
            cout << "Номер рейса: " << flights[i].flightNumber << "\n";
            cout << "Время вылета: " << flights[i].departureTime << "\n";
            cout << "Дата вылета: " << flights[i].departureDate << "\n";
            cout << "Стоимость билета: " << flights[i].ticketPrice << "\n";
            cout << "Количество мест: " << flights[i].seatCount << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Рейсы с таким пунктом назначения не найдены.\n";
    }
}

// Функция для сохранения данных в файл
void saveToFile() {
    ofstream file("flights.txt");
    if (!file) {
        cout << "Ошибка при открытии файла.\n";
        return;
    }

    file << flightCount << "\n";
    for (int i = 0; i < flightCount; ++i) {
        file << flights[i].flightNumber << "\n"
            << flights[i].destination << "\n"
            << flights[i].departureTime << "\n"
            << flights[i].departureDate << "\n"
            << flights[i].ticketPrice << "\n"
            << flights[i].seatCount << "\n";
    }

    file.close();
    cout << "Данные успешно сохранены в файл.\n";
}

// Функция для загрузки данных из файла
void loadFromFile() {
    ifstream file("flights.txt");
    if (!file) {
        cout << "Ошибка при открытии файла.\n";
        return;
    }

    file >> flightCount;
    file.ignore();
    for (int i = 0; i < flightCount; ++i) {
        file >> flights[i].flightNumber;
        file.ignore();
        getline(file, flights[i].destination);
        getline(file, flights[i].departureTime);
        getline(file, flights[i].departureDate);
        file >> flights[i].ticketPrice;
        file >> flights[i].seatCount;
        file.ignore();
    }

    file.close();
    cout << "Данные успешно загружены из файла.\n";
}

