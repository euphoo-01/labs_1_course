#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "stack.h"

void input_stack(Node** stack, const char* name) {
    char input[100];
    printf("������� �������� %s (exit ��� ����������):\n", name);
    while (1) {
        printf("> ");
        if (scanf("%99s", input) != 1 || !strcmp(input, "exit")) break;

        char* endptr;
        long num = strtol(input, &endptr, 10);
        if (*endptr || num < INT_MIN || num > INT_MAX) {
            printf("������: ������� ����� �����.\n");
        }
        else {
            push(stack, (int)num);
        }
    }
}

void print_stack(Node* top) {
    if (!top) {
        printf("���� ����.\n");
        return;
    }
    printf("��������: ");
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
        printf("\n����:\n");
        printf("1. �������� � Stack1\n");
        printf("2. �������� � Stack2\n");
        printf("3. ����� ��������, ������� ���� � ����� �����, �� ��� � ������\n");
        printf("4. ��������� ���� � ����\n");
        printf("5. ��������� ���� �� �����\n");
        printf("6. ������� ��� �����\n");
        printf("7. ������� �������������� ����\n");
        printf("8. �������� ��� �����\n");
        printf("0. �����\n> ");
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
            printf("��������� ������.\n");
            break;
        }
        case 4: {
            printf("�������� ���� ��� ����������:\n");
            printf("1. Stack1\n2. Stack2\n3. ���������\n> ");
            int saveChoice;
            scanf("%d", &saveChoice);

            Node* stackToSave = NULL;
            switch (saveChoice) {
            case 1: stackToSave = stack1; break;
            case 2: stackToSave = stack2; break;
            case 3: stackToSave = result; break;
            default:
                printf("�������� �����\n");
                break;
            }

            if (stackToSave) {
                if (save_stack(stackToSave, "FILE.txt")) { 
                    printf("���� ������� �������� � FILE.txt\n");
                }
                else {
                    printf("������ ��� ����������\n");
                }
            }
            else {
                printf("��������� ���� ���� ��� �� ����������\n");
            }
            break;
        }
        case 5: {
            printf("����� ���� ���������?\n");
            printf("1. Stack1\n2. Stack2\n> ");
            int loadChoice;
            scanf("%d", &loadChoice);

            Node** targetStack = NULL;
            switch (loadChoice) {
            case 1: targetStack = &stack1; break;
            case 2: targetStack = &stack2; break;
            default:
                printf("�������� �����\n");
                break;
            }

            if (targetStack) {
                clear(*targetStack); 
                *targetStack = load_stack("FILE.txt");
                if (*targetStack) {
                    printf("���� ������� �������� �� FILE.txt\n");
                }
                else {
                    printf("������ ��� ��������\n");
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
                printf("�������������� ����:\n");
                print_stack(result);
            }
            else {
                printf("�������������� ���� �� ������\n");
            }
            break;
        }
        case 7: {
            if (result) {
                printf("�������������� ����:\n");
                print_stack(result);
            }
            else {
                printf("�������������� ���� �� ������\n");
            }
            break;
        }
        case 8: {
            clear(stack1);
            clear(stack2);
            clear(result); 
            stack1 = stack2 = result = NULL;
            printf("��� ����� �������.\n");
            break;
        }
        case 0: {
            printf("�����...\n");
            break;
        }
        default: {
            printf("�������� �����\n");
            break;
        }
        }
    } while (choice != 0);

    clear(stack1); 
    clear(stack2); 
    clear(result); 
    return 0;
}