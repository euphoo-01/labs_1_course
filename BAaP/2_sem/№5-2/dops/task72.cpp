#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>
#include <windows.h> 

using namespace std;

enum MarkupPercent {
    PERCENT_5 = 5,
    PERCENT_10 = 10,
    PERCENT_15 = 15,
    PERCENT_20 = 20,
    PERCENT_30 = 30,
    PERCENT_35 = 35
};

struct Product {
    char name[50];
    double price;
    int quantity;
    MarkupPercent markup;
};

template<typename T>
bool parseNumber(const string& str, T& num) {
    stringstream ss(str);
    ss >> num;
    return !ss.fail() && ss.eof();
}

bool isValidMarkup(int value) {
    switch (value) {
        case 5: case 10: case 15: case 20: case 30: case 35:
            return true;
        default:
            return false;
    }
}

void inputProduct(Product& product) {
    string input;
    
    while (true) {
        cout << "Введите наименование товара (до 50 символов): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "Наименование не может быть пустым!\n";
        } else if (input.length() >= sizeof(product.name)) {
            cout << "Слишком длинное название! Максимум 50 символов.\n";
        } else {
            strcpy_s(product.name, input.c_str());
            break;
        }
    }

    while (true) {
        cout << "Введите цену товара (>0): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "Цена не может быть пустой!\n";
            continue;
        }
        
        double tempPrice;
        if (!parseNumber(input, tempPrice)) {
            cout << "Некорректный формат цены!\n";
            continue;
        }
        
        if (tempPrice <= 0) {
            cout << "Цена должна быть положительным числом!\n";
            continue;
        }
        
        product.price = tempPrice;
        break;
    }

    while (true) {
        cout << "Введите количество товара (>0): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "Количество не может быть пустым!\n";
            continue;
        }
        
        int tempQty;
        if (!parseNumber(input, tempQty)) {
            cout << "Некорректный формат количества!\n";
            continue;
        }
        
        if (tempQty <= 0) {
            cout << "Количество должно быть положительным целым числом!\n";
            continue;
        }
        
        product.quantity = tempQty;
        break;
    }

    while (true) {
        cout << "Выберите процент торговой надбавки (5, 10, 15, 20, 30, 35): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "Процент не может быть пустым!\n";
            continue;
        }
        
        int tempMarkup;
        if (!parseNumber(input, tempMarkup)) {
            cout << "Введите числовое значение из списка!\n";
            continue;
        }
        
        if (!isValidMarkup(tempMarkup)) {
            cout << "Недопустимый процент надбавки!\n";
            continue;
        }
        
        product.markup = static_cast<MarkupPercent>(tempMarkup);
        break;
    }
}

void printProduct(const Product& product) {
    double finalPrice = product.price * (1 + product.markup / 100.0);
    cout << setw(20) << left << product.name
         << setw(10) << right << fixed << setprecision(2) << product.price
         << setw(10) << product.quantity
         << setw(10) << product.markup
         << setw(15) << finalPrice << "\n";
}

void writeToFile(Product products[], int count, const string& filename) {
    if (count <= 0) {
        cout << "Нет данных для записи!\n";
        return;
    }
    
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Ошибка при открытии файла для записи!\n";
        return;
    }
    
    outFile << count << endl;
    for (int i = 0; i < count; ++i) {
        outFile << products[i].name << endl;
        outFile << products[i].price << endl;
        outFile << products[i].quantity << endl;
        outFile << products[i].markup << endl;
    }
    
    if (outFile.fail()) {
        cout << "Ошибка при записи файла!\n";
    } else {
        cout << "Данные успешно записаны в файл.\n";
    }
    
    outFile.close();
}

int readFromFile(Product products[], const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Ошибка при открытии файла для чтения!\n";
        return 0;
    }
    
    int count;
    inFile >> count;
    inFile.ignore(9999, '\n');
    
    if (count < 0 || count > 100) {
        cout << "Некорректные данные в файле!\n";
        return 0;
    }
    
    for (int i = 0; i < count; ++i) {
        Product& p = products[i];
        
        // Чтение наименования
        inFile.getline(p.name, 50);
        if (inFile.fail()) {
            cout << "Ошибка чтения наименования!\n";
            return i;
        }
        
        // Чтение цены
        string priceStr;
        getline(inFile, priceStr);
        if (!parseNumber(priceStr, p.price) || p.price <= 0) {
            cout << "Ошибка чтения цены!\n";
            return i;
        }
        
        // Чтение количества
        string qtyStr;
        getline(inFile, qtyStr);
        if (!parseNumber(qtyStr, p.quantity) || p.quantity <= 0) {
            cout << "Ошибка чтения количества!\n";
            return i;
        }
        
        // Чтение процента
        string markupStr;
        getline(inFile, markupStr);
        int tempMarkup;
        if (!parseNumber(markupStr, tempMarkup) || !isValidMarkup(tempMarkup)) {
            cout << "Ошибка чтения процента надбавки!\n";
            return i;
        }
        p.markup = static_cast<MarkupPercent>(tempMarkup);
    }
    
    cout << "Данные успешно считаны из файла.\n";
    return count;
}

void searchByName(Product products[], int count) {
    if (count == 0) {
        cout << "Список товаров пуст.\n";
        return;
    }
    
    string searchName;
    cout << "Введите наименование товара для поиска: ";
    getline(cin, searchName);
    
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strcmp(products[i].name, searchName.c_str()) == 0) {
            cout << "\nТовар найден:\n";
            cout << setw(20) << left << "Наименование"
                 << setw(10) << "Цена"
                 << setw(10) << "Кол-во"
                 << setw(10) << "Надбавка"
                 << setw(15) << "Итоговая цена\n";
            printProduct(products[i]);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Товар с названием \"" << searchName << "\" не найден.\n";
    }
}

void printMenu() {
    cout << "\nМеню:\n"
         << "1. Добавить товар\n"
         << "2. Просмотреть все товары\n"
         << "3. Записать в файл\n"
         << "4. Загрузить из файла\n"
         << "5. Поиск по названию\n"
         << "6. Выход\n"
         << "Выберите действие: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Product products[100];
    int productCount = 0;
    string filename = "products"; // Файл без расширения
    
    while (true) {
        printMenu();
        
        string choiceStr;
        int choice;
        while (true) {
            getline(cin, choiceStr);
            if (parseNumber(choiceStr, choice) && choice >= 1 && choice <= 6) {
                break;
            }
            cout << "Неверный выбор. Введите число от 1 до 6: ";
        }
        
        switch (choice) {
            case 1:
                if (productCount < 100) {
                    inputProduct(products[productCount++]);
                } else {
                    cout << "Достигнут лимит в 100 товаров!\n";
                }
                break;
                
            case 2:
                if (productCount > 0) {
                    cout << "\nСписок товаров:\n";
                    cout << setw(20) << left << "Наименование"
                         << setw(10) << "Цена"
                         << setw(10) << "Кол-во"
                         << setw(10) << "Надбавка"
                         << setw(15) << "Итоговая цена\n";
                    for (int i = 0; i < productCount; ++i) {
                        printProduct(products[i]);
                    }
                } else {
                    cout << "Список товаров пуст.\n";
                }
                break;
                
            case 3:
                writeToFile(products, productCount, filename);
                break;
                
            case 4: {
                int newCount = readFromFile(products, filename);
                if (newCount > 0) {
                    productCount = newCount;
                }
                break;
            }
                
            case 5:
                searchByName(products, productCount);
                break;
                
            case 6:
                cout << "Выход из программы.\n";
                return 0;
        }
    }
}