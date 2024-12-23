#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    unsigned char ch;
    cin >> ch;
    cout << static_cast<int>(ch);
    return 0;
}