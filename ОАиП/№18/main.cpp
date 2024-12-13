#include <iostream>
#include <cmath>
using namespace std;

double calculateRoot(double (*func)(double), double a, double b, double e) {
    double x;
    while (abs(a-b)>2*e) {
        x = (a+b)/2;
        if (func(x) * func(a) <= 0) {
            b = x;
        } 
        else {
            a = x;
        }
    }
    return x;
}

double f1(double x) {
    return sin(x) + x * x * x;
}

double f2(double x) {
    return 0.4 + x * x * x;
}

int main() {
    system("chcp 1251");

    double e = 0.001, a, b;
    cout << "===== ЗАДАНИЕ 1 ======" << endl;
    cout << "Введите значения a, b: "; cin >> a >> b;

    double f1X = calculateRoot(f1, a, b, e);
    double f2X = calculateRoot(f2, a, b, e);

    if (f1X) {
        cout << "Корень первой функции: " << f1X << endl;
        cout << "Корень второй функции: " << f2X << endl;
    }

    return 0;
}