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
            (c >= 192 && c <= 255))) { // �������� ������� ���� � CP1251
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
            (c >= 192 && c <= 255))) { // �������� ������� ���� � CP1251
            return false;
        }
    }
    return !str.empty();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<TRAIN> trains;

    cout << "���� ������ � ������� (��� ���������� ������� 'exit' � ������ ����������):\n";

    while (true) {
        if (trains.size() + 1 > 8) break;
        TRAIN newTrain;
        cout << "\n����� #" << (trains.size() + 1) << ":\n";

        // ���� ������ ����������

        while (true) {
            cout << "������� ����� ����������: ";
            getline(cin, newTrain.destination);
            if (isValidNameProfile(newTrain.destination)) break;
            else cerr << "������! ������� ���������� ����� ����������" << endl;
        }



        // ���� ������ ������ � ��������� ������������
        while (true) {
            cout << "������� ����� ������: ";
            if (cin >> newTrain.trainNumber && isValidNumber(newTrain.trainNumber)) {
                cin.ignore(9999, '\n');

                // �������� �� ��������
                bool duplicateExists = any_of(trains.begin(), trains.end(),
                    [&](const TRAIN& t) { return t.trainNumber == newTrain.trainNumber; });

                if (duplicateExists) {
                    cout << "������: ����� � ����� ������� ��� ����������!\n";
                    continue;
                }
                break;
            }
            cout << "������: ������������ �����!\n";
            cin.clear();
            cin.ignore(9999, '\n');
        }

        // ���� �������
        do {
            cout << "������� ����� ����������� (��:��): ";
            getline(cin, newTrain.departureTime);
        } while (!isValidTime(newTrain.departureTime) &&
            (cout << "������: ������������ ������ �������!\n"));

        trains.push_back(newTrain);
    }

    sortTrainsByDestination(trains);

    // ���� ������� ��� ������
    string searchTime;
    do {
        cout << "\n������� ����� ��� ������ (��:��): ";
        getline(cin, searchTime);
    } while (!isValidTime(searchTime) &&
        (cout << "������: ������������ ������ �������!\n"));

    // ����� �����������
    cout << "\n������, �������������� ����� " << searchTime << ":\n";
    bool found = false;
    for (const auto& train : trains) {
        if (isAfterTime(train.departureTime, searchTime)) {
            cout << "�����������: " << train.destination
                << "\t�����: " << train.trainNumber
                << "\t�����: " << train.departureTime << endl;
            found = true;
        }
        else if (searchTime == "00:00" && train.departureTime == "00:00") {
            cout << "�����������: " << train.destination
                << "\t�����: " << train.trainNumber
                << "\t�����: " << train.departureTime << endl;
            found = true;
        }
    }
    if (!found) cout << "��� ���������� �������\n";

    return 0;
}