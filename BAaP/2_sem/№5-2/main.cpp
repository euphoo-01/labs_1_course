#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <windows.h>

struct Time {
    unsigned int hours : 5;
    unsigned int minutes : 6;
};

enum Days {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Train {
    int number;
    std::string destination;
    unsigned int schedule;
    Time arrival;
    Time departure;
};

// ��������� �������
int getIntInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);
Time getTimeInput(const std::string& prompt);
unsigned int getDaysInput();

void addTrain(std::vector<Train>& trains) {
    Train newTrain;
    
    // ���� ������ ������ � ���������
    while (true) {
        newTrain.number = getIntInput("������� ����� ������: ");
        bool exists = std::any_of(trains.begin(), trains.end(),
            [&](const Train& t) { return t.number == newTrain.number; });
        if (!exists) break;
        std::cout << "����� � ����� ������� ��� ����������!\n";
    }

    // ���� ������ ����������
    newTrain.destination = getStringInput("������� ����� ����������: ");
    
    // ���� ���� ����������
    newTrain.schedule = getDaysInput();

    // ���� �������
    newTrain.arrival = getTimeInput("����� �������� (��:��): ");
    newTrain.departure = getTimeInput("����� ����������� (��:��): ");

    trains.push_back(newTrain);
    std::cout << "����� ��������!\n";
}

// ������� ��������� �����
int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            return value;
        }
        std::cout << "������! ������� ����� ������������� �����\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

std::string getStringInput(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        std::cout << "������! ���� �� ����� ���� ������\n";
    }
}

Time getTimeInput(const std::string& prompt) {
    Time time = {0, 0};
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.size() != 5 || input[2] != ':') {
            std::cout << "����������� ������ ��:��\n";
            continue;
        }

        try {
            int h = std::stoi(input.substr(0, 2));
            int m = std::stoi(input.substr(3, 2));
            
            if (h >= 0 && h <= 23 && m >= 0 && m <= 59) {
                time.hours = h;
                time.minutes = m;
                return time;
            }
            std::cout << "����: 0-23, ������: 0-59\n";
        } catch (...) {
            std::cout << "������������ ���� �������!\n";
        }
    }
}

unsigned int getDaysInput() {
    unsigned int schedule = 0;
    while (true) {
        std::cout << "��� ���������� (����� ������, 1-��..7-��): ";
        std::string line;
        std::getline(std::cin, line);
        
        bool valid = true;

        for (char day : line) {
            if (!isdigit(day) && day != ' ') {
                valid = false;
                break;
            }
            else if (day != ' ') {
                int iday = day - '0';
                if (iday < 1 || iday > 7) {
                    valid = false;
                    break;
                }
                schedule |= (1 << (iday - 1));
            }

        }
        
        if (valid && !line.empty()) return schedule;
        std::cout << "������! ����������� ����� 1-7 ����� ������\n";
        schedule = 0;
    }
}

void printSchedule(unsigned int schedule) {
    const char* days[] = {"��", "��", "��", "��", "��", "��", "��"};
    bool first = true;
    for (int i = 0; i < 7; i++) {
        if (schedule & (1 << i)) {
            std::cout << (first ? "" : ", ") << days[i];
            first = false;
        }
    }
}

void printTrains(const std::vector<Train>& trains) {
    if (trains.empty()) {
        std::cout << "������ ������� ����!\n";
        return;
    }
    for (const auto& t : trains) {
        std::cout << "\n�����: " << t.number
                  << "\n�����: " << t.destination
                  << "\n���: ";
        printSchedule(t.schedule);
        std::cout << "\n��������: " 
                  << std::setw(2) << std::setfill('0') << t.arrival.hours << ":"
                  << std::setw(2) << std::setfill('0') << t.arrival.minutes
                  << "\n�����������: "
                  << std::setw(2) << std::setfill('0') << t.departure.hours << ":"
                  << std::setw(2) << std::setfill('0') << t.departure.minutes
                  << "\n";
    }
}

void deleteTrain(std::vector<Train>& trains) {
    if (trains.empty()) {
        std::cout << "������ ������� ����!\n";
        return;
    }
    
    int num = getIntInput("������� ����� ������ ��� ��������: ");
    
    auto it = std::remove_if(trains.begin(), trains.end(),
        [num](const Train& t) { return t.number == num; });
    
    if (it != trains.end()) {
        trains.erase(it, trains.end());
        std::cout << "������� �������: " << std::distance(it, trains.end()) << "\n";
    } else {
        std::cout << "����� �� ������!\n";
    }
}

void searchByDestination(const std::vector<Train>& trains) {
    if (trains.empty()) {
        std::cout << "������ ������� ����!\n";
        return;
    }
    
    std::string dest = getStringInput("������� ����� ����������: ");
    bool found = false;
    
    for (const auto& t : trains) {
        if (t.destination == dest) {
            std::cout << "\n�����: " << t.number
                      << "\n���: ";
            printSchedule(t.schedule);
            std::cout << "\n��������: " 
                      << std::setw(2) << std::setfill('0') << t.arrival.hours << ":"
                      << std::setw(2) << std::setfill('0') << t.arrival.minutes
                      << "\n�����������: "
                      << std::setw(2) << std::setfill('0') << t.departure.hours << ":"
                      << std::setw(2) << std::setfill('0') << t.departure.minutes
                      << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "������� � '" << dest << "' �� �������!\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<Train> trains;
    
    while (true) {
        std::cout << "\n����:\n"
                  << "1. �������� �����\n"
                  << "2. �������� ��� ������\n"
                  << "3. ������� �����\n"
                  << "4. ����� �� ������\n"
                  << "5. �����\n";
        
        int choice = getIntInput("�������� �����: ");
        
        switch(choice) {
            case 1: addTrain(trains); break;
            case 2: printTrains(trains); break;
            case 3: deleteTrain(trains); break;
            case 4: searchByDestination(trains); break;
            case 5: return 0;
            default: std::cout << "�������� ����� ����!\n";
        }
    }
}