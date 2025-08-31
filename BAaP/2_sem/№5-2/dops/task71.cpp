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
        cout << "������ ������� ����.\n";
        return;
    }

    cout << "\n������ �� ������:\n";
    cout << setw(22) << left << "������������ ������"
        << setw(11) << "����, BYN"
        << setw(13) << "����������"
        << setw(22) << "�������� (%)"
        << setw(16) << "�������� ����, BYN\n";
    
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
        cout << "����� ��������, ���������� �������� ������ �������.\n";
        return;
    }

    string input;
    bool validInput = false;
    while (!validInput) {
        cout << "������� ������ � ������:\n";

        // ���� ��������
        cout << "������������ ������: ";
        getline(cin, input);
        if (input.empty()) {
            cout << "������: ��� ������ �� ����� ���� ������. ��������� ����.\n";
            continue;
        }
        products[count].name = input;

        // ���� ����
        string priceStr;
        while (true) {
            cout << "���� ������: ";
            getline(cin, priceStr);
            if (isPositiveDouble(priceStr)) {
                products[count].price = stod(priceStr);
                break;
            } else {
                cout << "������: ���� ������ ���� ������������� ������. ��������� ����.\n";
            }
        }

        // ���� ����������
        string quantityStr;
        while (true) {
            cout << "���������� ������: ";
            getline(cin, quantityStr);
            if (isPositiveInt(quantityStr)) {
                products[count].quantity = stoi(quantityStr);
                break;
            } else {
                cout << "������: ���������� ������ ���� ����� ������������� ������. ��������� ����.\n";
            }
        }

        // ���� �������� ��������
        string markupStr;
        while (true) {
            cout << "�������� ������� �������� �������� (5, 7, 11, 20, 25, 30): ";
            getline(cin, markupStr);
            try {
                int markup = stoi(markupStr);
                if (isValidMarkup(markup)) {
                    products[count].markup = static_cast<MarkupPercent>(markup);
                    break;
                } else {
                    cout << "������������ �������. �������� �� ������.\n";
                }
            } catch (...) {
                cout << "������: ������� ����� �����.\n";
            }
        }

        count++;
        validInput = true;
    }
}

void deleteProduct(Product products[], int& count) {
    cout << "������� ������������ ������ ��� ��������: ";
    string name;
    getline(cin, name);

    if (name.empty()) {
        cout << "������: ��� ������ �� ����� ���� ������.\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (products[i].name == name) {
            for (int j = i; j < count - 1; j++) {
                products[j] = products[j + 1];
            }
            count--;
            cout << "����� \"" << name << "\" ������.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "����� \"" << name << "\" �� ������.\n";
    }
}

void searchByMaxPrice(Product products[], int count) {
    string maxPriceStr;
    while (true) {
        cout << "������� ������������ ���� ��� ������: ";
        getline(cin, maxPriceStr);
        if (isPositiveDouble(maxPriceStr)) {
            double maxPrice = stod(maxPriceStr);
            cout << "\n������ � ����� �� ���� " << fixed << setprecision(2) << maxPrice << " BYN:\n";
            
            cout << setw(22) << left << "������������ ������"
                << setw(11) << "����"
                << setw(13) << "����������"
                << setw(22) << "�������� (%)"
                << setw(16) << "�������� ����\n";
            
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
                cout << "������ � �������� ����� �� �������.\n";
            }
            return;
        } else {
            cout << "������: ���� ������ ���� ������������� ������. ��������� ����.\n";
        }
    }
}

void searchByExactPrice(Product products[], int count) {
    string priceStr;
    while (true) {
        cout << "������� ������ ���� ��� ������: ";
        getline(cin, priceStr);
        if (isPositiveDouble(priceStr)) {
            double searchPrice = stod(priceStr);
            cout << "\n������ � ����� " << fixed << setprecision(2) << searchPrice << " BYN:\n";
            
            cout << setw(22) << left << "������������ ������"
                << setw(11) << "����"
                << setw(13) << "����������"
                << setw(22) << "�������� (%)"
                << setw(16) << "�������� ����\n";
            
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
                cout << "������ � �������� ����� �� �������.\n";
            }
            return;
        } else {
            cout << "������: ���� ������ ���� ������������� ������. ��������� ����.\n";
        }
    }
}

void displayMenu() {
    cout << "\n����:\n";
    cout << "1. ������� ������ �������\n";
    cout << "2. �������� �����\n";
    cout << "3. ������� �����\n";
    cout << "4. ����� ������ �� ������������ ����\n";
    cout << "5. ����� ������ �� ������ ����\n";
    cout << "6. �����\n";
    cout << "�������� ��������: ";
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
                    cout << "����� �� ���������.\n";
                    return 0;
                default:
                    cout << "�������� �����. ���������� �����.\n";
            }
        } catch (...) {
            cout << "������: ������� ����� �� 1 �� 6.\n";
        }
    }
}