#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>
#include <algorithm>

using namespace std;

struct TRAIN {
    string destination;
    string trainNumber;
    string departureTime;
};

bool isAfterTime(string trainTime, string& inputTime) {
    return trainTime > inputTime;
}

bool isValidTime(const string& time) {
    if (time.length() != 5 || time[2] != ':') return false;
    for (int i = 0; i < 5; ++i) {
        if (i != 2 && !isdigit(time[i])) return false;
    }
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60);
}

void sortTrainsByDestination(vector<TRAIN>& trains) {
    for (size_t i = 0; i < trains.size() - 1; ++i) {
        for (size_t j = 0; j < trains.size() - i - 1; ++j) {
            if (trains[j].destination > trains[j + 1].destination) {
                swap(trains[j], trains[j + 1]);
            }
        }
    }
}

bool isValidNameProfile(const string& str) {
    for (unsigned char c : str) {
        if (!(c == '-' || (c == ' ') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 192 && c <= 255))) { // Диапазон русских букв в CP1251
            return false;
        }
    }
    return !str.empty();
}

bool isValidNumber(const string& str) {
    for (unsigned char c : str) {
        if (!(c == '-' || (c == ' ') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 48 && c <= 57) ||
            (c >= 192 && c <= 255))) { // Диапазон русских букв в CP1251
            return false;
        }
    }
    return !str.empty();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<TRAIN> trains;

    cout << "Ввод данных о поездах (для завершения введите 'exit' в пункте назначения):\n";

    while (true) {
        if (trains.size() + 1 > 8) break;
        TRAIN newTrain;
        cout << "\nПоезд #" << (trains.size() + 1) << ":\n";

        // Ввод пункта назначения

        while (true) {
            cout << "Введите пункт назначения: ";
            getline(cin, newTrain.destination);
            if (isValidNameProfile(newTrain.destination)) break;
            else cerr << "Ошибка! Введите корректный пункт назначения" << endl;
        }



        // Ввод номера поезда с проверкой уникальности
        while (true) {
            cout << "Введите номер поезда: ";
            if (cin >> newTrain.trainNumber && isValidNumber(newTrain.trainNumber)) {
                cin.ignore(9999, '\n');

                // Проверка на дубликат
                bool duplicateExists = any_of(trains.begin(), trains.end(),
                    [&](const TRAIN& t) { return t.trainNumber == newTrain.trainNumber; });

                if (duplicateExists) {
                    cout << "Ошибка: Поезд с таким номером уже существует!\n";
                    continue;
                }
                break;
            }
            cout << "Ошибка: Некорректный номер!\n";
            cin.clear();
            cin.ignore(9999, '\n');
        }

        // Ввод времени
        do {
            cout << "Введите время отправления (ЧЧ:ММ): ";
            getline(cin, newTrain.departureTime);
        } while (!isValidTime(newTrain.departureTime) &&
            (cout << "Ошибка: Некорректный формат времени!\n"));

        trains.push_back(newTrain);
    }

    sortTrainsByDestination(trains);

    // Ввод времени для поиска
    string searchTime;
    do {
        cout << "\nВведите время для поиска (ЧЧ:ММ): ";
        getline(cin, searchTime);
    } while (!isValidTime(searchTime) &&
        (cout << "Ошибка: Некорректный формат времени!\n"));

    // Вывод результатов
    cout << "\nПоезда, отправляющиеся после " << searchTime << ":\n";
    bool found = false;
    for (const auto& train : trains) {
        if (isAfterTime(train.departureTime, searchTime)) {
            cout << "Направление: " << train.destination
                << "\tНомер: " << train.trainNumber
                << "\tВремя: " << train.departureTime << endl;
            found = true;
        }
        else if (searchTime == "00:00" && train.departureTime == "00:00") {
            cout << "Направление: " << train.destination
                << "\tНомер: " << train.trainNumber
                << "\tВремя: " << train.departureTime << endl;
            found = true;
        }
    }
    if (!found) cout << "Нет подходящих поездов\n";

    return 0;
}