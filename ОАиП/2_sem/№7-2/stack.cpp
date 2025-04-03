#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains(Node* stack, int value) {
    Node* current = stack;
    while (current) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

void push(Node** top, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

Node* vipolnit_zadanie(Node* stack1, Node* stack2) {
    Node* result = NULL;
    Node* current1 = stack1;
    Node* current2 = stack2;

    while (current1) {
        int data = current1->data;
        if (!contains(stack2, data) && !contains(result, data))
            push(&result, data);
        current1 = current1->next;
    }

    while (current2) {
        int data = current2->data;
        if (!contains(stack1, data) && !contains(result, data))
            push(&result, data);
        current2 = current2->next;
    }
    return result;
}

void clear(Node* stack) { 
    while (stack) {
        Node* temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int save_stack(Node* stack, const char* filename) {
    if (!stack) {
        printf("Нечего сохранять: стек пуст\n");
        return 0;
    }
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка при открытии файла для записи\n");
        return 0;
    }
    Node* current = stack;
    while (current) {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }
    fclose(file);
    return 1;
}

Node* load_stack(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Файл не найден или ошибка при открытии\n");
        return NULL;
    }

    int capacity = 10, count = 0;
    int* nums = (int*)malloc(capacity * sizeof(int));
    if (!nums) {
        printf("Ошибка выделения памяти\n");
        fclose(file);
        return NULL;
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        if (count >= capacity) {
            capacity *= 2;
            nums = (int*)realloc(nums, capacity * sizeof(int));
            if (!nums) {
                printf("Ошибка реаллокации памяти\n");
                fclose(file);
                return NULL;
            }
        }
        nums[count++] = num;
    }
    fclose(file);

    Node* stack = NULL;
    for (int i = count - 1; i >= 0; i--)
        push(&stack, nums[i]);

    free(nums);
    return stack;
}