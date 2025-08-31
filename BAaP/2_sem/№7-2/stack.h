#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int contains(Node* stack, int value);
void push(Node** top, int data);
Node* vipolnit_zadanie(Node* stack1, Node* stack2); 
void clear(Node* stack); 
int save_stack(Node* stack, const char* filename);
Node* load_stack(const char* filename);

#endif