#include <iostream>
#include <cfloat>
#include "Varparm.h"

using namespace std;

int main() {
    cout << "ivarparm:" << endl;
    cout << Varparm::ivarparm(1, 5) << endl;                  // 5
    cout << Varparm::ivarparm(2, 2, 3) << endl;               // 6
    cout << Varparm::ivarparm(3, 2, 3, 4) << endl;            // 24
    cout << Varparm::ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl; // 5040

    cout << "\nsvarparm:" << endl;
    cout << Varparm::svarparm(1, 5) << endl;                  // 5
    cout << Varparm::svarparm(2, 2, 7) << endl;               // 7
    cout << Varparm::svarparm(3, 2, 3, 9) << endl;            // 9
    cout << Varparm::svarparm(7, 1, 2, 3, 4, 8, 5, 6) << endl; // 8

    cout << "\nfvarparm:" << endl;
    cout << Varparm::fvarparm(5.0f, FLT_MAX) << endl;         // 5
    cout << Varparm::fvarparm(2.0f, 3.0f, FLT_MAX) << endl;   // 5
    cout << Varparm::fvarparm(1.0f, 2.0f, 3.0f, FLT_MAX) << endl; // 6
    cout << Varparm::fvarparm(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, FLT_MAX) << endl; // 28

    cout << "\ndvarparm:" << endl;
    cout << Varparm::dvarparm(5.0, DBL_MAX) << endl;          // 5
    cout << Varparm::dvarparm(2.0, 3.0, DBL_MAX) << endl;     // 5
    cout << Varparm::dvarparm(1.0, 2.0, 3.0, DBL_MAX) << endl; // 6
    cout << Varparm::dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, DBL_MAX) << endl; // 28

    return 0;
}
