#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

int have_digit(const char *);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    printf("Какое задание выполнять? ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
    {

        FILE *file = fopen("fileA.dat", "r");
        if (file == NULL)
        {
            printf("Не удалось открыть файл.\n");
            return 1;
        }

        int x;
        printf("Введите x: ");
        scanf("%i", &x);

        int numbers[1000];
        int count = 0; // Счётчик чисел

        while (fscanf(file, "%d", &numbers[count]) == 1)
        {
            count++;
            if (count >= 1000)
            {
                printf("Слишком много чисел в файле.\n");
                break;
            }
        }
        fclose(file);

        if (count < 2)
        {
            printf("В файле недостаточно данных.\n");
            return 1;
        }

        int result1 = 0, result2 = 0;
        double min_diff = INT_MAX;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                double avg = (numbers[i] + numbers[j]) / 2;
                double diff = abs(avg - x);

                if (diff < min_diff)
                {
                    min_diff = diff;
                    result1 = numbers[i];
                    result2 = numbers[j];
                }
            }
        }

        printf("Результат: %d и %d\n", result1, result2);
        break;
    }

    case 2:
    {

        FILE *file1 = fopen("F1.txt", "r");
        if (file1 == NULL)
        {
            printf("Не удалось прочитать файл. \n");
            break;
        }

        vector<string> input_arr;
        int str_num = 0;
        char ch;
        string temp;
        while (fscanf_s(file1, "%c", &ch) == 1)
        { // Запись в массив
            temp += ch;
            if (ch == '\n')
            {
                input_arr.push_back(temp);
                temp = "";
                str_num++;
            }
        }

        FILE *file2 = fopen("F2.txt", "w");
        for (int i = 0; i < str_num; i++)
        {
            if (!have_digit(input_arr[i].c_str()))
            {
                for (int j = 0; j < input_arr[i].length(); j++)
                {
                    fprintf(file2, "%c", input_arr[i][j]);
                }
            }
        }
        fclose(file1);
        fclose(file2);

        break;
    }
    default:
        printf("Задание не выбрано.\n");
        break;
    }

    return 0;
}

int have_digit(const char *str)
{
    while (*str)
    {
        if (isdigit(*str))
        {
            return 1;
        }
        str++;
    }
    return 0;
};
