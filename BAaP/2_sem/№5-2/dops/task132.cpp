#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>
#include <algorithm>

using namespace std;

union Population {
    int populationInt;
    char populationStr[50];
};

struct Country {
    char name[100];
    char capital[100];
    Population population;
    bool isPopulationStr; // ���� ��� ����������� ���� ������ � �����������
    double area;
    char president[100];
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(9999, '\n');
}

bool isValidNumber(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

void inputCountry(Country& country) {
    cout << "������� �������� �����������: ";
    clearInputBuffer();
    do {
        cin.getline(country.name, 100);
    } while (strlen(country.name) == 0);

    cout << "������� �������: ";
    do {
        cin.getline(country.capital, 100);
    } while (strlen(country.capital) == 0);

    cout << "�������� ������ ����� ���������:\n"
         << "1. �������� ��������\n"
         << "2. ��������� ��������\n";
    int choice;
    do {
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cout << "������� 1 ��� 2: ";
            clearInputBuffer();
        }
    } while (choice != 1 && choice != 2);

    country.isPopulationStr = (choice == 2);
    clearInputBuffer();

    if (country.isPopulationStr) {
        cout << "������� ��������� (�����): ";
        do {
            cin.getline(country.population.populationStr, 50);
        } while (strlen(country.population.populationStr) == 0);
    } else {
        string input;
        do {
            cout << "������� ��������� (�����): ";
            getline(cin, input);
        } while (!isValidNumber(input));
        country.population.populationInt = stoi(input);
    }

    cout << "������� �������: ";
    while (!(cin >> country.area) || country.area <= 0) {
        cout << "������� ���������� �������� ��������: ";
        cin.clear();
        cin.ignore(9999, '\n');
    }

    cout << "������� ������� ����������: ";
    clearInputBuffer();
    do {
        cin.getline(country.president, 100);
    } while (strlen(country.president) == 0);
}

void printCountry(const Country& country) {
    cout << "�����������: " << country.name << endl;
    cout << "�������: " << country.capital << endl;
    cout << "���������: ";
    if (country.isPopulationStr) {
        cout << country.population.populationStr;
    } else {
        cout << country.population.populationInt;
    }
    cout << "\n�������: " << country.area << " ��.��" << endl;
    cout << "���������: " << country.president << endl << endl;
}

void writeToFile(const vector<Country>& countries, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return;
    }

    int count = countries.size();
    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (const auto& country : countries) {
        outFile.write(country.name, sizeof(country.name));
        outFile.write(country.capital, sizeof(country.capital));
        outFile.write(reinterpret_cast<const char*>(&country.isPopulationStr), sizeof(bool));
        if (country.isPopulationStr) {
            outFile.write(country.population.populationStr, sizeof(country.population.populationStr));
        } else {
            outFile.write(reinterpret_cast<const char*>(&country.population.populationInt), sizeof(int));
        }
        outFile.write(reinterpret_cast<const char*>(&country.area), sizeof(double));
        outFile.write(country.president, sizeof(country.president));
    }

    if (!outFile.good()) {
        cerr << "������ ������ � ����!" << endl;
    } else {
        cout << "������ ������� ��������" << endl;
    }
    outFile.close();
}

bool readFromFile(vector<Country>& countries, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return false;
    }

    int count;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count));
    if (count <= 0) {
        cerr << "���� ���� ��� ���������" << endl;
        return false;
    }

    countries.resize(count);
    for (auto& country : countries) {
        inFile.read(country.name, sizeof(country.name));
        inFile.read(country.capital, sizeof(country.capital));
        inFile.read(reinterpret_cast<char*>(&country.isPopulationStr), sizeof(bool));

        if (country.isPopulationStr) {
            inFile.read(country.population.populationStr, sizeof(country.population.populationStr));
        } else {
            inFile.read(reinterpret_cast<char*>(&country.population.populationInt), sizeof(int));
        }

        inFile.read(reinterpret_cast<char*>(&country.area), sizeof(double));
        inFile.read(country.president, sizeof(country.president));

        // ��������� ������
        if (strlen(country.name) == 0 || strlen(country.capital) == 0 || 
            strlen(country.president) == 0 || country.area <= 0) {
            cerr << "���������� ������������ ������ � �����!" << endl;
            countries.clear();
            return false;
        }
    }

    if (!inFile.eof()) {
        cerr << "������ ������ �����!" << endl;
        countries.clear();
        return false;
    }

    cout << "������ ������� ���������" << endl;
    return true;
}

void searchByName(const vector<Country>& countries) {
    if (countries.empty()) {
        cout << "������ ���������� ����!" << endl;
        return;
    }

    cout << "������� ��������: ";
    string searchName;
    clearInputBuffer();
    getline(cin, searchName);

    bool found = false;
    for (const auto& country : countries) {
        if (strcmp(country.name, searchName.c_str()) == 0) {
            cout << "\n������� �����������:\n";
            printCountry(country);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "����������� \"" << searchName << "\" �� �������!" << endl;
    }
}

void printMenu() {
    cout << "\n����:\n"
         << "1. �������� �����������\n"
         << "2. �������� ���\n"
         << "3. �������� � ����\n"
         << "4. ��������� �� �����\n"
         << "5. ����� �� ��������\n"
         << "6. �����\n"
         << "��� �����: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Country> countries;
    string filename = "countries.txt";

    while (true) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                Country country;
                inputCountry(country);
                countries.push_back(country);
                break;
            }
            case 2: {
                if (countries.empty()) {
                    cout << "������ ����!" << endl;
                } else {
                    for (const auto& country : countries) {
                        printCountry(country);
                    }
                }
                break;
            }
            case 3: {
                writeToFile(countries, filename);
                break;
            }
            case 4: {
                if (readFromFile(countries, filename)) {
                    cout << "������ ������� ���������" << endl;
                }
                break;
            }
            case 5: {
                searchByName(countries);
                break;
            }
            case 6: {
                cout << "����� �� ���������" << endl;
                return 0;
            }
            default: {
                cout << "�������� �����! ���������� �����" << endl;
                clearInputBuffer();
            }
        }
    }
}