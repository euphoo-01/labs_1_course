#include "Varparm.h"
#include <iostream>

int main() {
    using namespace Varparm;
    using namespace std;

    // Примеры вызовов
    cout << "ivarparm(0): " << ivarparm(0) << endl; // 1
    cout << "ivarparm(2, 3, 4): " << ivarparm(2, 3, 4) << endl; // 12
    cout << "svarparm(3, 5, 1, 4): " << svarparm(3, 5, 1, 4) << endl; // 5
    cout << "fvarparm(1.5f, 2.3f, FLT_MAX): " << fvarparm(1.5f, 2.3f, FLT_MAX) << endl; // 3.8
    cout << "dvarparm(0.5, 1.2, 3.4, DBL_MAX): " << dvarparm(0.5, 1.2, 3.4, DBL_MAX) << endl; // 5.1

    return 0;
}