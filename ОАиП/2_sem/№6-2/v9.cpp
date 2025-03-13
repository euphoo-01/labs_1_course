#include <iostream>
using namespace std;

struct list {
    float number;
    list *next;
};

void insert (list *&, float);
void del (list *&, float);
bool isEmpty (list *);
void print (list *);
void menu (void);
void sumNegative (list *);

int main () {
    
    return 0;
}