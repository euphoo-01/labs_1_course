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
        cout << "������� ������������ ������ (�� 50 ��������): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "������������ �� ����� ���� ������!\n";
        } else if (input.length() >= sizeof(product.name)) {
            cout << "������� ������� ��������! �������� 50 ��������.\n";
        } else {
            strcpy_s(product.name, input.c_str());
            break;
        }
    }

    while (true) {
        cout << "������� ���� ������ (>0): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "���� �� ����� ���� ������!\n";
            continue;
        }
        
        double tempPrice;
        if (!parseNumber(input, tempPrice)) {
            cout << "������������ ������ ����!\n";
            continue;
        }
        
        if (tempPrice <= 0) {
            cout << "���� ������ ���� ������������� ������!\n";
            continue;
        }
        
        product.price = tempPrice;
        break;
    }

    while (true) {
        cout << "������� ���������� ������ (>0): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "���������� �� ����� ���� ������!\n";
            continue;
        }
        
        int tempQty;
        if (!parseNumber(input, tempQty)) {
            cout << "������������ ������ ����������!\n";
            continue;
        }
        
        if (tempQty <= 0) {
            cout << "���������� ������ ���� ������������� ����� ������!\n";
            continue;
        }
        
        product.quantity = tempQty;
        break;
    }

    while (true) {
        cout << "�������� ������� �������� �������� (5, 10, 15, 20, 30, 35): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "������� �� ����� ���� ������!\n";
            continue;
        }
        
        int tempMarkup;
        if (!parseNumber(input, tempMarkup)) {
            cout << "������� �������� �������� �� ������!\n";
            continue;
        }
        
        if (!isValidMarkup(tempMarkup)) {
            cout << "������������ ������� ��������!\n";
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
        cout << "��� ������ ��� ������!\n";
        return;
    }
    
    ofstream outFile(filename);
    if (!outFile) {
        cout << "������ ��� �������� ����� ��� ������!\n";
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
        cout << "������ ��� ������ �����!\n";
    } else {
        cout << "������ ������� �������� � ����.\n";
    }
    
    outFile.close();
}

int readFromFile(Product products[], const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "������ ��� �������� ����� ��� ������!\n";
        return 0;
    }
    
    int count;
    inFile >> count;
    inFile.ignore(9999, '\n');
    
    if (count < 0 || count > 100) {
        cout << "������������ ������ � �����!\n";
        return 0;
    }
    
    for (int i = 0; i < count; ++i) {
        Product& p = products[i];
        
        // ������ ������������
        inFile.getline(p.name, 50);
        if (inFile.fail()) {
            cout << "������ ������ ������������!\n";
            return i;
        }
        
        // ������ ����
        string priceStr;
        getline(inFile, priceStr);
        if (!parseNumber(priceStr, p.price) || p.price <= 0) {
            cout << "������ ������ ����!\n";
            return i;
        }
        
        // ������ ����������
        string qtyStr;
        getline(inFile, qtyStr);
        if (!parseNumber(qtyStr, p.quantity) || p.quantity <= 0) {
            cout << "������ ������ ����������!\n";
            return i;
        }
        
        // ������ ��������
        string markupStr;
        getline(inFile, markupStr);
        int tempMarkup;
        if (!parseNumber(markupStr, tempMarkup) || !isValidMarkup(tempMarkup)) {
            cout << "������ ������ �������� ��������!\n";
            return i;
        }
        p.markup = static_cast<MarkupPercent>(tempMarkup);
    }
    
    cout << "������ ������� ������� �� �����.\n";
    return count;
}

void searchByName(Product products[], int count) {
    if (count == 0) {
        cout << "������ ������� ����.\n";
        return;
    }
    
    string searchName;
    cout << "������� ������������ ������ ��� ������: ";
    getline(cin, searchName);
    
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strcmp(products[i].name, searchName.c_str()) == 0) {
            cout << "\n����� ������:\n";
            cout << setw(20) << left << "������������"
                 << setw(10) << "����"
                 << setw(10) << "���-��"
                 << setw(10) << "��������"
                 << setw(15) << "�������� ����\n";
            printProduct(products[i]);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "����� � ��������� \"" << searchName << "\" �� ������.\n";
    }
}

void printMenu() {
    cout << "\n����:\n"
         << "1. �������� �����\n"
         << "2. ����������� ��� ������\n"
         << "3. �������� � ����\n"
         << "4. ��������� �� �����\n"
         << "5. ����� �� ��������\n"
         << "6. �����\n"
         << "�������� ��������: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Product products[100];
    int productCount = 0;
    string filename = "products"; // ���� ��� ����������
    
    while (true) {
        printMenu();
        
        string choiceStr;
        int choice;
        while (true) {
            getline(cin, choiceStr);
            if (parseNumber(choiceStr, choice) && choice >= 1 && choice <= 6) {
                break;
            }
            cout << "�������� �����. ������� ����� �� 1 �� 6: ";
        }
        
        switch (choice) {
            case 1:
                if (productCount < 100) {
                    inputProduct(products[productCount++]);
                } else {
                    cout << "��������� ����� � 100 �������!\n";
                }
                break;
                
            case 2:
                if (productCount > 0) {
                    cout << "\n������ �������:\n";
                    cout << setw(20) << left << "������������"
                         << setw(10) << "����"
                         << setw(10) << "���-��"
                         << setw(10) << "��������"
                         << setw(15) << "�������� ����\n";
                    for (int i = 0; i < productCount; ++i) {
                        printProduct(products[i]);
                    }
                } else {
                    cout << "������ ������� ����.\n";
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
                cout << "����� �� ���������.\n";
                return 0;
        }
    }
}