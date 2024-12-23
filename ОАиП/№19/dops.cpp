#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    system("chcp 1251");

    printf("Введите вариант: ");
    int choice;
    scanf("%i", &choice);

    switch (choice)
    {
    case 12:
    {
        FILE *file = fopen("input_12.dat", "r");
        if (file == NULL)
        {
            printf("Не удалось открыть файл!\n");
            break;
        }
        
        break;
    }
    case 14:
    {
        break;
    }
    case 16:
    {
        break;
    }
    default:
    {
        printf("Такого варианта нет!\n");
        break;
    }
    }
    return 0;
}