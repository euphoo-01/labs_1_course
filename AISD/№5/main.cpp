#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair (char open, char close)  {
    if (open == '(' && close == ')') {
        return true;
    }
    else if (open == '{' && close == '}') {
        return true;
    }
    else if (open == '[' && close == ']') {
        return true;
    }
    return false;
}

int main() {
    string str;
    cout << "Введите строку: "; cin >> str;

    stack<char> brackets;
    bool error = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            brackets.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (!isMatchingPair(brackets.top(), str[i])) {
                error = true;
                break;
            } else {
                brackets.pop();
            }
        }
    }

    if (!error && brackets.empty()) {
        cout << "\nСкобки расставлены правильно" << endl;
    } else {
        cout << "\nСкобки расставлены неверно" << endl;
    }

    return 0;
}