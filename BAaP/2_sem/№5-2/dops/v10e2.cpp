#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

enum Type {
    ���������� = 1,
    ��������,
    ������������,
    ����������,
    ������������,
    ���������,
    ���������,
    ������������
};

struct Government {
    string name;
    string capital;
    long int population;
    float area;
    Type type[3];
};

int main() {
    setlocale(LC_ALL, "Russia.Russian_1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Government gov;
    gov.name = "Belarus";
    gov.capital = "Minsk";
    gov.population = 9499999;
    gov.area = 207595;
    gov.type[0] = static_cast<Type>(����������);

    cout << "�����������: \n" << "��������: " << gov.name << "\n" << "�������: " << gov.capital << "\n" << "���������: " << gov.population << "\n" << "�������: " << gov.area << "\n" << "���: " << gov.type[0] << endl;
    return 0;
}