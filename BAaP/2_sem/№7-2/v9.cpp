#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "stack.h"

void input_stack(Node** stack, const char* name) {
    char input[100];
    printf("Введите элементы %s (exit для завершения):\n", name);
    while (1) {
        printf("> ");
        if (scanf("%99s", input) != 1 || !strcmp(input, "exit")) break;

        char* endptr;
        long num = strtol(input, &endptr, 10);
        if (*endptr || num < INT_MIN || num > INT_MAX) {
            printf("Ошибка: введите целое число.\n");
        }
        else {
            push(stack, (int)num);
        }
    }
}

void print_stack(Node* top) {
    if (!top) {
        printf("Стек пуст.\n");
        return;
    }
    printf("Элементы: ");
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* stack1 = NULL, * stack2 = NULL, * result = NULL;
    int choice;

    do {
        printf("\nМеню:\n");
        printf("1. Добавить в Stack1\n");
        printf("2. Добавить в Stack2\n");
        printf("3. Найти элементы, которые есть в одном стеке, но нет в другом\n");
        printf("4. Сохранить стек в файл\n");
        printf("5. Загрузить стек из файла\n");
        printf("6. Вывести все стеки\n");
        printf("7. Вывести результирующий стек\n");
        printf("8. Очистить все стеки\n");
        printf("0. Выход\n> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            input_stack(&stack1, "Stack1");
            break;
        }
        case 2: {
            input_stack(&stack2, "Stack2");
            break;
        }
        case 3: {
            clear(result); 
            result = vipolnit_zadanie(stack1, stack2); 
            printf("Результат создан.\n");
            break;
        }
        case 4: {
            printf("Выберите стек для сохранения:\n");
            printf("1. Stack1\n2. Stack2\n3. Результат\n> ");
            int saveChoice;
            scanf("%d", &saveChoice);

            Node* stackToSave = NULL;
            switch (saveChoice) {
            case 1: stackToSave = stack1; break;
            case 2: stackToSave = stack2; break;
            case 3: stackToSave = result; break;
            default:
                printf("Неверный выбор\n");
                break;
            }

            if (stackToSave) {
                if (save_stack(stackToSave, "FILE.txt")) { 
                    printf("Стек успешно сохранен в FILE.txt\n");
                }
                else {
                    printf("Ошибка при сохранении\n");
                }
            }
            else {
                printf("Выбранный стек пуст или не существует\n");
            }
            break;
        }
        case 5: {
            printf("Какой стек загрузить?\n");
            printf("1. Stack1\n2. Stack2\n> ");
            int loadChoice;
            scanf("%d", &loadChoice);

            Node** targetStack = NULL;
            switch (loadChoice) {
            case 1: targetStack = &stack1; break;
            case 2: targetStack = &stack2; break;
            default:
                printf("Неверный выбор\n");
                break;
            }

            if (targetStack) {
                clear(*targetStack); 
                *targetStack = load_stack("FILE.txt");
                if (*targetStack) {
                    printf("Стек успешно загружен из FILE.txt\n");
                }
                else {
                    printf("Ошибка при загрузке\n");
                }
            }
            break;
        }
        case 6: {
            printf("Stack1:\n");
            print_stack(stack1);
            printf("Stack2:\n");
            print_stack(stack2);
            if (result) {
                printf("Результирующий стек:\n");
                print_stack(result);
            }
            else {
                printf("Результирующий стек не создан\n");
            }
            break;
        }
        case 7: {
            if (result) {
                printf("Результирующий стек:\n");
                print_stack(result);
            }
            else {
                printf("Результирующий стек не создан\n");
            }
            break;
        }
        case 8: {
            clear(stack1);
            clear(stack2);
            clear(result); 
            stack1 = stack2 = result = NULL;
            printf("Все стеки очищены.\n");
            break;
        }
        case 0: {
            printf("Выход...\n");
            break;
        }
        default: {
            printf("Неверный выбор\n");
            break;
        }
        }
    } while (choice != 0);

    clear(stack1); 
    clear(stack2); 
    clear(result); 
    return 0;
}