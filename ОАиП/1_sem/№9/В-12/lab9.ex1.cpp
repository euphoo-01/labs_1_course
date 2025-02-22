#include <iostream>
#include <cmath>
using namespace std;
// a=5 b=11 n=200
double f (double x){
    return exp(x)+6;
}
int main() {
    double x, h, a, b, n=200, s=0, che;
    cout << "Введите а: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    h = (b-a)/n;
    che = b-h;
    for (x = a; x < che; x = x + h){
        s=s+h*(f(x)+f(x+h))/2;
    }
    cout << "S = " << s << endl;
    return 0;
}