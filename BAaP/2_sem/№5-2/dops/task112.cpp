#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <windows.h>
#include <limits>

using namespace std;

const int VIN_LENGTH = 17;
const string DATE_FORMAT = "ДД.ММ.ГГГГ";

union CarID {
    int factoryNumber;
    char vin[VIN_LENGTH + 1];
};

struct Car {
    string brand;
    string color;
    CarID id;
    bool isVin;
    string releaseDate;
    string bodyType;
    string lastInspection;
    string owner;
};

bool isValidDate(const string& date) {
    if (date.size() != 10 || date[2] != '.' || date[5] != '.') return false;
    
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    return true;
}

bool isValidName (const string& name) {
    for (unsigned char c : name) {
        if (!(c == '-' ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 192 && c <= 255))) { // Диапазон русских букв в CP1251
            return false;
        }
    }
    if (name[0] == '-' || name[name.length() - 1] == '-') return false;
    return !name.empty();
}

bool isValidVin(const string& vin) {
    if (vin.size() != VIN_LENGTH) return false;
    for (char c : vin) {
        if (!isalnum(c) || c == 'I' || c == 'O' || c == 'Q') return false;
    }
    return true;
}

void inputCar(Car& car) {
    string temp;
    
    cout << "Марка автомобиля: ";
    getline(cin >> ws, car.brand);
    
    cout << "Цвет: ";
    getline(cin >> ws, car.color);
    
    while (true) {
        cout << "1 - VIN / 0 - Заводской номер: ";
        if (getline(cin >> ws, temp) && (temp == "1" || temp == "0")) {
            car.isVin = (temp == "1");
            break;
        }
        cout << "Ошибка! Введите 1 или 0\n";
    }
    
    if (car.isVin) {
        while (true) {
            cout << "VIN (" << VIN_LENGTH << " символов): ";
            getline(cin >> ws, temp);
            if (isValidVin(temp)) {
                strcpy_s(car.id.vin, temp.c_str());
                break;
            }
            cout << "Некорректный VIN\n";
        }
    } else {
        while (true) {
            cout << "Заводской номер (целое число > 0): ";
            if (getline(cin >> ws, temp) && all_of(temp.begin(), temp.end(), ::isdigit)) {
                car.id.factoryNumber = stoi(temp);
                if (car.id.factoryNumber > 0) break;
            }
            cout << "Ошибка! Введите положительное число\n";
        }
    }
    
    while (true) {
        cout << "Дата выпуска (" << DATE_FORMAT << "): ";
        getline(cin >> ws, temp);
        if (isValidDate(temp)) {
            car.releaseDate = temp;
            break;
        }
        cout << "Некорректная дата\n";
    }
    
    cout << "Тип кузова: ";
    getline(cin >> ws, car.bodyType);
    
    while (true) {
        cout << "Дата последнего ТО (" << DATE_FORMAT << "): ";
        getline(cin >> ws, temp);
        if (isValidDate(temp)) {
            car.lastInspection = temp;
            break;
        }
        cout << "Некорректная дата\n";
    }
    
    cout << "Владелец: ";
    getline(cin >> ws, car.owner);
    while (!isValidName(car.owner)) {
        cerr << "Ошибка! Неверное имя! Повторите попытку: ";
        getline(cin >> ws, car.owner);
    }
}

void printCar(const Car& car) {
    cout << "\nМарка: " << car.brand
         << "\nЦвет: " << car.color
         << "\nИдентификатор: " << (car.isVin ? car.id.vin : to_string(car.id.factoryNumber))
         << "\nДата выпуска: " << car.releaseDate
         << "\nТип кузова: " << car.bodyType
         << "\nПоследний ТО: " << car.lastInspection
         << "\nВладелец: " << car.owner << "\n\n";
}

void writeToFile(const vector<Car>& cars, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи\n";
        return;
    }
    
    int size = cars.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const auto& car : cars) {
        size_t brandSize = car.brand.size();
        outFile.write(reinterpret_cast<const char*>(&brandSize), sizeof(brandSize));
        outFile.write(car.brand.c_str(), brandSize);
        
        size_t colorSize = car.color.size();
        outFile.write(reinterpret_cast<const char*>(&colorSize), sizeof(colorSize));
        outFile.write(car.color.c_str(), colorSize);
        
        outFile.write(reinterpret_cast<const char*>(&car.isVin), sizeof(car.isVin));
        if (car.isVin) {
            outFile.write(car.id.vin, VIN_LENGTH);
        } else {
            outFile.write(reinterpret_cast<const char*>(&car.id.factoryNumber), sizeof(car.id.factoryNumber));
        }
        
        size_t dateSize = car.releaseDate.size();
        outFile.write(reinterpret_cast<const char*>(&dateSize), sizeof(dateSize));
        outFile.write(car.releaseDate.c_str(), dateSize);
        
        size_t bodySize = car.bodyType.size();
        outFile.write(reinterpret_cast<const char*>(&bodySize), sizeof(bodySize));
        outFile.write(car.bodyType.c_str(), bodySize);
        
        size_t inspectionSize = car.lastInspection.size();
        outFile.write(reinterpret_cast<const char*>(&inspectionSize), sizeof(inspectionSize));
        outFile.write(car.lastInspection.c_str(), inspectionSize);
        
        size_t ownerSize = car.owner.size();
        outFile.write(reinterpret_cast<const char*>(&ownerSize), sizeof(ownerSize));
        outFile.write(car.owner.c_str(), ownerSize);
    }
    
    outFile.close();
    cout << "Данные сохранены\n";
}

vector<Car> readFromFile(const string& filename) {
    vector<Car> cars;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения\n";
        return cars;
    }
    
    int size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
    
    for (int i = 0; i < size; ++i) {
        Car car;
        
        size_t brandSize;
        inFile.read(reinterpret_cast<char*>(&brandSize), sizeof(brandSize));
        car.brand.resize(brandSize);
        inFile.read(&car.brand[0], brandSize);
        
        size_t colorSize;
        inFile.read(reinterpret_cast<char*>(&colorSize), sizeof(colorSize));
        car.color.resize(colorSize);
        inFile.read(&car.color[0], colorSize);
        
        inFile.read(reinterpret_cast<char*>(&car.isVin), sizeof(car.isVin));
        if (car.isVin) {
            inFile.read(car.id.vin, VIN_LENGTH);
            car.id.vin[VIN_LENGTH] = '\0';
        } else {
            inFile.read(reinterpret_cast<char*>(&car.id.factoryNumber), sizeof(car.id.factoryNumber));
        }
        
        size_t dateSize;
        inFile.read(reinterpret_cast<char*>(&dateSize), sizeof(dateSize));
        car.releaseDate.resize(dateSize);
        inFile.read(&car.releaseDate[0], dateSize);
        
        size_t bodySize;
        inFile.read(reinterpret_cast<char*>(&bodySize), sizeof(bodySize));
        car.bodyType.resize(bodySize);
        inFile.read(&car.bodyType[0], bodySize);
        
        size_t inspectionSize;
        inFile.read(reinterpret_cast<char*>(&inspectionSize), sizeof(inspectionSize));
        car.lastInspection.resize(inspectionSize);
        inFile.read(&car.lastInspection[0], inspectionSize);
        
        size_t ownerSize;
        inFile.read(reinterpret_cast<char*>(&ownerSize), sizeof(ownerSize));
        car.owner.resize(ownerSize);
        inFile.read(&car.owner[0], ownerSize);
        if (!isValidName(car.owner)) {
            cerr << "Ошибка! Некорректное имя владельца!" << endl;
            return cars;
        }
        
        cars.push_back(car);
    }
    
    inFile.close();
    cout << "Данные загружены\n";
    return cars;
}

void searchByOwner(const vector<Car>& cars) {
    string searchOwner;
    cout << "Введите имя владельца: ";
    getline(cin >> ws, searchOwner);
    
    bool found = false;
    for (const auto& car : cars) {
        if (car.owner == searchOwner) {
            printCar(car);
            found = true;
        }
    }
    
    if (!found) {
        cout << "Автомобилей с владельцем \"" << searchOwner << "\" не найдено\n";
    }
}

void printMenu() {
    cout << "\nМеню:\n"
         << "1. Добавить автомобиль\n"
         << "2. Показать все автомобили\n"
         << "3. Сохранить в файл\n"
         << "4. Загрузить из файла\n"
         << "5. Поиск по владельцу\n"
         << "6. Выход\n"
         << "Выберите действие: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Car> cars;
    string filename = "cars.dat";
    int choice;

    while (true) {
        printMenu();
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Неверный ввод! Попробуйте снова: ";
            cin.clear();
            cin.ignore(9999, '\n');
        }
        cin.ignore(9999, '\n');

        switch (choice) {
            case 1: {
                Car car;
                inputCar(car);
                cars.push_back(car);
                break;
            }
            case 2:
                if (cars.empty()) {
                    cout << "Список пуст\n";
                } else {
                    for (const auto& car : cars) {
                        printCar(car);
                    }
                }
                break;
            case 3:
                writeToFile(cars, filename);
                break;
            case 4:
                cars = readFromFile(filename);
                break;
            case 5:
                searchByOwner(cars);
                break;
            case 6:
                cout << "Выход\n";
                return 0;
        }
    }
}