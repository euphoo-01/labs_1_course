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

// Прототипы функций
int getIntInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);
Time getTimeInput(const std::string& prompt);
unsigned int getDaysInput();

void addTrain(std::vector<Train>& trains) {
    Train newTrain;
    
    // Ввод номера поезда с проверкой
    while (true) {
        newTrain.number = getIntInput("Введите номер поезда: ");
        bool exists = std::any_of(trains.begin(), trains.end(),
            [&](const Train& t) { return t.number == newTrain.number; });
        if (!exists) break;
        std::cout << "Поезд с таким номером уже существует!\n";
    }

    // Ввод пункта назначения
    newTrain.destination = getStringInput("Введите пункт назначения: ");
    
    // Ввод дней следования
    newTrain.schedule = getDaysInput();

    // Ввод времени
    newTrain.arrival = getTimeInput("Время прибытия (ЧЧ:ММ): ");
    newTrain.departure = getTimeInput("Время отправления (ЧЧ:ММ): ");

    trains.push_back(newTrain);
    std::cout << "Поезд добавлен!\n";
}

// Функции валидации ввода
int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            return value;
        }
        std::cout << "Ошибка! Введите целое положительное число\n";
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
        std::cout << "Ошибка! Ввод не может быть пустым\n";
    }
}

Time getTimeInput(const std::string& prompt) {
    Time time = {0, 0};
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.size() != 5 || input[2] != ':') {
            std::cout << "Используйте формат ЧЧ:ММ\n";
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
            std::cout << "Часы: 0-23, минуты: 0-59\n";
        } catch (...) {
            std::cout << "Некорректный ввод времени!\n";
        }
    }
}

unsigned int getDaysInput() {
    unsigned int schedule = 0;
    while (true) {
        std::cout << "Дни следования (через пробел, 1-Пн..7-Вс): ";
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
        std::cout << "Ошибка! Используйте числа 1-7 через пробел\n";
        schedule = 0;
    }
}

void printSchedule(unsigned int schedule) {
    const char* days[] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
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
        std::cout << "Список поездов пуст!\n";
        return;
    }
    for (const auto& t : trains) {
        std::cout << "\nНомер: " << t.number
                  << "\nПункт: " << t.destination
                  << "\nДни: ";
        printSchedule(t.schedule);
        std::cout << "\nПрибытие: " 
                  << std::setw(2) << std::setfill('0') << t.arrival.hours << ":"
                  << std::setw(2) << std::setfill('0') << t.arrival.minutes
                  << "\nОтправление: "
                  << std::setw(2) << std::setfill('0') << t.departure.hours << ":"
                  << std::setw(2) << std::setfill('0') << t.departure.minutes
                  << "\n";
    }
}

void deleteTrain(std::vector<Train>& trains) {
    if (trains.empty()) {
        std::cout << "Список поездов пуст!\n";
        return;
    }
    
    int num = getIntInput("Введите номер поезда для удаления: ");
    
    auto it = std::remove_if(trains.begin(), trains.end(),
        [num](const Train& t) { return t.number == num; });
    
    if (it != trains.end()) {
        trains.erase(it, trains.end());
        std::cout << "Удалено поездов: " << std::distance(it, trains.end()) << "\n";
    } else {
        std::cout << "Поезд не найден!\n";
    }
}

void searchByDestination(const std::vector<Train>& trains) {
    if (trains.empty()) {
        std::cout << "Список поездов пуст!\n";
        return;
    }
    
    std::string dest = getStringInput("Введите пункт назначения: ");
    bool found = false;
    
    for (const auto& t : trains) {
        if (t.destination == dest) {
            std::cout << "\nНомер: " << t.number
                      << "\nДни: ";
            printSchedule(t.schedule);
            std::cout << "\nПрибытие: " 
                      << std::setw(2) << std::setfill('0') << t.arrival.hours << ":"
                      << std::setw(2) << std::setfill('0') << t.arrival.minutes
                      << "\nОтправление: "
                      << std::setw(2) << std::setfill('0') << t.departure.hours << ":"
                      << std::setw(2) << std::setfill('0') << t.departure.minutes
                      << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Поездов в '" << dest << "' не найдено!\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<Train> trains;
    
    while (true) {
        std::cout << "\nМеню:\n"
                  << "1. Добавить поезд\n"
                  << "2. Показать все поезда\n"
                  << "3. Удалить поезд\n"
                  << "4. Поиск по пункту\n"
                  << "5. Выход\n";
        
        int choice = getIntInput("Выберите пункт: ");
        
        switch(choice) {
            case 1: addTrain(trains); break;
            case 2: printTrains(trains); break;
            case 3: deleteTrain(trains); break;
            case 4: searchByDestination(trains); break;
            case 5: return 0;
            default: std::cout << "Неверный пункт меню!\n";
        }
    }
}