#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <limits>
#include <stdexcept>
#include <cmath>

using namespace std;

enum MarkupPercent {
    PERCENT_5 = 5,
    PERCENT_7 = 7,
    PERCENT_11 = 11,
    PERCENT_20 = 20,
    PERCENT_25 = 25,
    PERCENT_30 = 30
};

struct Product {
    string name;
    double price;
    int quantity;
    MarkupPercent markup;
};

bool isValidMarkup(int value) {
    switch (value) {
        case 5:
        case 7:
        case 11:
        case 20:
        case 25:
        case 30:
            return true;
        default:
            return false;
    }
}

bool isPositiveDouble(const string& str) {
    try {
        double value = stod(str);
        return value > 0;
    } catch (...) {
        return false;
    }
}

bool isPositiveInt(const string& str) {
    try {
        int value = stoi(str);
        return value > 0;
    } catch (...) {
        return false;
    }
}

void displayProducts(Product products[], int count) {
    if (count == 0) {
        cout << "Список товаров пуст.\n";
        return;
    }

    cout << "\nТовары на складе:\n";
    cout << setw(22) << left << "Наименование товара"
        << setw(11) << "Цена, BYN"
        << setw(13) << "Количество"
        << setw(22) << "Надбавка (%)"
        << setw(16) << "Итоговая цена, BYN\n";
    
    for (int i = 0; i < count; i++) {
        double finalPrice = products[i].price * (1 + products[i].markup / 100.0);
        
        cout << left 
            << setw(22) << products[i].name
            << setw(11) << fixed << setprecision(2) << products[i].price
            << setw(13) << products[i].quantity
            << setw(22) << to_string(products[i].markup) + "%"
            << setw(16) << fixed << setprecision(2) << finalPrice << "\n";
    }
}

void addProduct(Product products[], int& count) {
    if (count >= 100) {
        cout << "Склад заполнен, невозможно добавить больше товаров.\n";
        return;
    }

    string input;
    bool validInput = false;
    while (!validInput) {
        cout << "Введите данные о товаре:\n";

        // Ввод названия
        cout << "Наименование товара: ";
        getline(cin, input);
        if (input.empty()) {
            cout << "Ошибка: имя товара не может быть пустым. Повторите ввод.\n";
            continue;
        }
        products[count].name = input;

        // Ввод цены
        string priceStr;
        while (true) {
            cout << "Цена товара: ";
            getline(cin, priceStr);
            if (isPositiveDouble(priceStr)) {
                products[count].price = stod(priceStr);
                break;
            } else {
                cout << "Ошибка: цена должна быть положительным числом. Повторите ввод.\n";
            }
        }

        // Ввод количества
        string quantityStr;
        while (true) {
            cout << "Количество товара: ";
            getline(cin, quantityStr);
            if (isPositiveInt(quantityStr)) {
                products[count].quantity = stoi(quantityStr);
                break;
            } else {
                cout << "Ошибка: количество должно быть целым положительным числом. Повторите ввод.\n";
            }
        }

        // Ввод процента надбавки
        string markupStr;
        while (true) {
            cout << "Выберите процент торговой надбавки (5, 7, 11, 20, 25, 30): ";
            getline(cin, markupStr);
            try {
                int markup = stoi(markupStr);
                if (isValidMarkup(markup)) {
                    products[count].markup = static_cast<MarkupPercent>(markup);
                    break;
                } else {
                    cout << "Некорректный процент. Выберите из списка.\n";
                }
            } catch (...) {
                cout << "Ошибка: введите целое число.\n";
            }
        }

        count++;
        validInput = true;
    }
}

void deleteProduct(Product products[], int& count) {
    cout << "Введите наименование товара для удаления: ";
    string name;
    getline(cin, name);

    if (name.empty()) {
        cout << "Ошибка: имя товара не может быть пустым.\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (products[i].name == name) {
            for (int j = i; j < count - 1; j++) {
                products[j] = products[j + 1];
            }
            count--;
            cout << "Товар \"" << name << "\" удален.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Товар \"" << name << "\" не найден.\n";
    }
}

void searchByMaxPrice(Product products[], int count) {
    string maxPriceStr;
    while (true) {
        cout << "Введите максимальную цену для поиска: ";
        getline(cin, maxPriceStr);
        if (isPositiveDouble(maxPriceStr)) {
            double maxPrice = stod(maxPriceStr);
            cout << "\nТовары с ценой не выше " << fixed << setprecision(2) << maxPrice << " BYN:\n";
            
            cout << setw(22) << left << "Наименование товара"
                << setw(11) << "Цена"
                << setw(13) << "Количество"
                << setw(22) << "Надбавка (%)"
                << setw(16) << "Итоговая цена\n";
            
            bool found = false;
            for (int i = 0; i < count; i++) {
                double finalPrice = products[i].price * (1 + products[i].markup / 100.0);
                if (finalPrice <= maxPrice) {
                    cout << left 
                        << setw(22) << products[i].name
                        << setw(11) << fixed << setprecision(2) << products[i].price
                        << setw(13) << products[i].quantity
                        << setw(22) << to_string(products[i].markup) + "%"
                        << setw(16) << fixed << setprecision(2) << finalPrice << "\n";
                    found = true;
                }
            }
            if (!found) {
                cout << "Товары с заданной ценой не найдены.\n";
            }
            return;
        } else {
            cout << "Ошибка: цена должна быть положительным числом. Повторите ввод.\n";
        }
    }
}

void searchByExactPrice(Product products[], int count) {
    string priceStr;
    while (true) {
        cout << "Введите точную цену для поиска: ";
        getline(cin, priceStr);
        if (isPositiveDouble(priceStr)) {
            double searchPrice = stod(priceStr);
            cout << "\nТовары с ценой " << fixed << setprecision(2) << searchPrice << " BYN:\n";
            
            cout << setw(22) << left << "Наименование товара"
                << setw(11) << "Цена"
                << setw(13) << "Количество"
                << setw(22) << "Надбавка (%)"
                << setw(16) << "Итоговая цена\n";
            
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (abs(products[i].price - searchPrice) < 0.0001) {
                    double finalPrice = products[i].price * (1 + products[i].markup / 100.0);
                    
                    cout << left 
                        << setw(22) << products[i].name
                        << setw(11) << fixed << setprecision(2) << products[i].price
                        << setw(13) << products[i].quantity
                        << setw(22) << to_string(products[i].markup) + "%"
                        << setw(16) << fixed << setprecision(2) << finalPrice << "\n";
                    
                    found = true;
                }
            }
            if (!found) {
                cout << "Товары с заданной ценой не найдены.\n";
            }
            return;
        } else {
            cout << "Ошибка: цена должна быть положительным числом. Повторите ввод.\n";
        }
    }
}

void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Вывести список товаров\n";
    cout << "2. Добавить товар\n";
    cout << "3. Удалить товар\n";
    cout << "4. Найти товары по максимальной цене\n";
    cout << "5. Найти товары по точной цене\n";
    cout << "6. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Product products[100];
    int productCount = 0;
    string menuChoice;

    while (true) {
        displayMenu();
        getline(cin, menuChoice);

        try {
            int choice = stoi(menuChoice);
            switch (choice) {
                case 1:
                    displayProducts(products, productCount);
                    break;
                case 2:
                    addProduct(products, productCount);
                    break;
                case 3:
                    deleteProduct(products, productCount);
                    break;
                case 4:
                    searchByMaxPrice(products, productCount);
                    break;
                case 5:
                    searchByExactPrice(products, productCount);
                    break;
                case 6:
                    cout << "Выход из программы.\n";
                    return 0;
                default:
                    cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } catch (...) {
            cout << "Ошибка: введите число от 1 до 6.\n";
        }
    }
}