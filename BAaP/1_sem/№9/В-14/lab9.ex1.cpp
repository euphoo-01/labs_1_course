#include <iostream>
#include <cmath>
using namespace std;
// a=1 b=4 n=200
double f (double x){
    return x*x*x*x+4;
}
int main() {
    double x, h, a, b, n=200, s=0, che;
    cout << "¬ведите а: "; cin >> a;
    cout << "¬ведите b: "; cin >> b;
    h = (b-a)/n;
    che = b-h;
    for (x = a; x < che; x = x + h){
        s=s+h*(f(x)+f(x+h))/2;
    }
    cout << "S = " << s << endl;
    return 0;
}