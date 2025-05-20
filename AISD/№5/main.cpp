#include <iostream>
using namespace std;

struct node {
    char data;
    struct node *next;
};

node* push(node* head, char data);
node* pop(node* head);

bool isMatchingPair(char open, char close) {
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
    char str[99];
    cout << "Р’РІРµРґРёС‚Рµ СЃС‚СЂРѕРєСѓ: "; cin >> str;

    node* head = nullptr;
    bool error = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            head = push(head, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (head == nullptr) {
                error = true;
                break;
            } else if (!isMatchingPair(head->data, str[i])) {
                error = true;
                break;
            } else {
                head = pop(head);
            }
        }
    }

    if (!error && head == nullptr) {
        cout << "\nРЎРєРѕР±РєРё СЂР°СЃСЃС‚Р°РІР»РµРЅС‹ РїСЂР°РІРёР»СЊРЅРѕ" << endl;
    } else {
        cout << "\nРЎРєРѕР±РєРё СЂР°СЃСЃС‚Р°РІР»РµРЅС‹ РЅРµРІРµСЂРЅРѕ" << endl;
        while (head != nullptr) {
            pop(head);
        }
    }

    return 0;
}

node* push(node* head, char data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

node* pop(node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    node* ptrNext = head->next;
    delete head;
    return ptrNext;
}
