#include <iostream>
#include <cmath>
using namespace std;
// a=5 b=11 n=200
int f (double x){
    return exp(x)+6;
}
int main(){
    double a, b, n, h, s1, s2, s, x;
    cout << "Введите a, b, n: "; cin >> a >> b >> n;
    h = (b-a)/(2*n);
    s1 = 0;
    s2 = 0;
    x = a + 2*h;
    for (int i = 1; i < n; i++){
        s2 = s2 + f(x);
        x = x + h;
        s1 = s1 + f(x);
        x = x + h;
    }
    s=h/3*(f(a)+4*f(a+h)+4*s1+2*s2+f(b));
    cout << "S = " << s << endl;
    return 0;
}