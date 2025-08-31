#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string a = "10.53423553";
    string b = "10,53423553";
    cout << stod(a) << '\t' << stod(b) << endl;
    return 0;
}