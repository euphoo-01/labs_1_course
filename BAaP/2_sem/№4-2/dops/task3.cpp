#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <cctype>
#include <locale>
#include <algorithm>
#include <tuple>

using namespace std;

struct Sanatorium {
    string name;         // �������� ���������
    string location;     // ������������
    string profile;      // �������� �������
    int voucherCount;    // �������
};

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

void sortSanatoriums(vector<Sanatorium>& sanatoriums) {
    sort(sanatoriums.begin(), sanatoriums.end(),
        [](const Sanatorium& a, const Sanatorium& b) {
            return tie(a.profile, a.name) < tie(b.profile, b.name);
        });
}

void printSanatoriums(const vector<Sanatorium>& sanatoriums) {
    cout << "\n���������:\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "| �������� �������   | �������� ���������         | �������������� | �������|\n";
    cout << "----------------------------------------------------------------------------\n";

    for (const auto& s : sanatoriums) {
        printf("| %-19s| %-25s| %-15s| %-7d|\n",
            s.profile.c_str(), s.name.c_str(), s.location.c_str(), s.voucherCount);
    }

    cout << "----------------------------------------------------------------------------\n";
}

void searchSanatoriums(const vector<Sanatorium>& sanatoriums, const string& searchProfile) {
    cout << "\n���������� ������ �� ��������� ������� \"" << searchProfile << "\":\n";
    bool found = false;

    for (const auto& s : sanatoriums) {
        if (s.profile == searchProfile) {
            if (!found) {
                cout << "----------------------------------------------------------------------------\n";
                cout << "| �������� ���������         | ��������������     | ������� |\n";
                cout << "----------------------------------------------------------------------------\n";
            }
            printf("| %-25s| %-20s| %-7d|\n", s.name.c_str(), s.location.c_str(), s.voucherCount);
            found = true;
        }
    }

    if (!found) {
        cout << "���������� � ����� �������� �������� �� �������.\n";
    }
    else {
        cout << "----------------------------------------------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    vector<Sanatorium> sanatoriums;
    int count;

    // ���� ���������� ����������
    do {
        cout << "������� ���������� ����������: ";
        if (!(cin >> count)) {
            cout << "������: ������� ����� �����!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (count <= 0) {
            cout << "������: ���������� ������ ���� �������������!\n";
        }
    } while (count <= 0);
    cin.ignore(10000, '\n');

    // ���� ������ � ����������
    for (int i = 0; i < count; ++i) {
        Sanatorium s;
        cout << "\n��������� #" << (i + 1) << ":\n";

        // ���� ��������
        do {
            cout << "������� �������� (������ ����� � ������): ";
            getline(cin, s.name);
            if (!isValidNameProfile(s.name)) {
                cout << "������: ��������� ������ �������/���������� ����� � �����!\n";
            }
        } while (!isValidNameProfile(s.name));

        // ���� �������������� (����� �������)
        cout << "������� ����� ������������: ";
        getline(cin, s.location);

        // ���� �������
        do {
            cout << "������� �������� ������� (������ ����� � ������): ";
            getline(cin, s.profile);
            if (!isValidNameProfile(s.profile)) {
                cout << "������: ��������� ������ �������/���������� ����� � �����!\n";
            }
        } while (!isValidNameProfile(s.profile));

        // ���� ���������� �������
        do {
            cout << "������� ���������� �������: ";
            if (!(cin >> s.voucherCount)) {
                cout << "������: ������� ����� �����!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else if (s.voucherCount < 0) {
                cout << "������: ���������� �� ����� ���� �������������!\n";
            }
            else {
                break;
            }
        } while (true);
        cin.ignore(10000, '\n');

        sanatoriums.push_back(s);
    }

    sortSanatoriums(sanatoriums);
    printSanatoriums(sanatoriums);

    // ����� �� �������
    string searchProfile;
    do {
        cout << "\n������� �������� ������� ��� ������: ";
        getline(cin, searchProfile);
        if (searchProfile.empty()) {
            cout << "������: ������� �� ����� ���� ������!\n";
        }
    } while (searchProfile.empty());

    searchSanatoriums(sanatoriums, searchProfile);

    return 0;
}