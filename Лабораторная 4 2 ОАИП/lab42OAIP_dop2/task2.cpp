#include <iostream>
#include <string>

using namespace std;

struct TRAIN {
    string destination; // Название пункта назначения
    int trainNumber;    // Номер поезда
    string departureTime; // Время
};

bool isAfterTime(string& trainTime, string& inputTime) {
    return trainTime > inputTime;
}

void sortTrainsByDestination(TRAIN trains[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (trains[j].destination > trains[j + 1].destination) {
                TRAIN tmp = trains[j]; 
                trains[j] = trains[j + 1];
                trains[j + 1] = tmp;
            }
        }
    }
}

void main() {
    setlocale(LC_ALL, "rus");
    const int trainCount = 3;
    TRAIN trains[trainCount];
    cout << "Введите данные о " << trainCount << " поездах:\n";
    for (int i = 0; i < trainCount; i++) {
        cout << "\nПоезд #" << (i + 1) << ":\n";

        cout << "Введите пункт назначения: ";
        cin.ignore(); 
        getline(cin, trains[i].destination);

        cout << "Введите номер поезда: ";
        cin >> trains[i].trainNumber;

        cout << "Введите время отправления: ";
        cin >> trains[i].departureTime;
    }

    sortTrainsByDestination(trains, trainCount);

    string inputTime;
    cout << "\nВведите время, чтобы вывести поезда, отправляющиеся после него: ";
    cin >> inputTime;

    cout << "\nПоезда, отправляющиеся после " << inputTime << ":\n";
    bool found = false;
    for (int i = 0; i < trainCount; i++) {
        if (isAfterTime(trains[i].departureTime, inputTime)) {
            cout << "Пункт назначения: " << trains[i].destination
                << ", Номер поезда: " << trains[i].trainNumber
                << ", Время отправления: " << trains[i].departureTime << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Нет поездов, отправляющихся после " << inputTime << ".\n";
    }
}
