#include <iostream>
#include <cmath>
using namespace std;
// a=0 b=4 e=0.0001
int f(double x){
    return x*x+4*x-2;
}
int main(){
    double a, b, e, x;
    cout << "Введите a, b, e: "; cin >> a >> b >> e;
    while (abs(a-b)>2*e)
    {
        x = (a+b)/2;
        if (f(x)*f(a)<=0){
            b = x;
        }
        else {
            a = x;
        }
    }
    cout << "X = " << x << endl;
    return 0;
}