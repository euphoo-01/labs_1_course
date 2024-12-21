#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int have_digit(const char*);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    printf("Какое задание выполнять? ");
    scanf("%i", &choice);

    switch (choice) {
        case 1: {

            FILE *file = fopen("fileA.dat", "r");
            if (file == NULL) {
                printf("Не удалось открыть файл.\n");
                return 1;
            }

            int x;
            printf("Введите x: ");
            scanf("%i", &x);

            int numbers[1000];
            int count = 0;    // Счётчик чисел

            while (fscanf(file, "%d", &numbers[count]) == 1) {
                count++;
                if (count >= 1000) {
                    printf("Слишком много чисел в файле.\n");
                    break;
                }
            }
            fclose(file);

            if (count < 2) {
                printf("В файле недостаточно данных.\n");
                return 1;
            }

            int result1 = 0, result2 = 0;
            double min_diff = INT_MAX;

            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    double avg = (numbers[i] + numbers[j]) / 2;
                    double diff = abs(avg - x);

                    if (diff < min_diff) {
                        min_diff = diff;
                        result1 = numbers[i];
                        result2 = numbers[j];
                    }
                }
            }

            printf("Результат: %d и %d\n", result1, result2);
            break;
        }

        case 2: {
            FILE *f1 = fopen("F1.txt", "w");

            if (f1 == NULL) {
                printf("Не удалось создать файл F1.\n");
                return 1;
            }

            int row_count;

            printf("Сколько строк записать?: "); scanf("%i", &row_count);
            cin.ignore();
            for (int i = 0; i < row_count; i++) {
                string line{};
                getline(cin, line);
                fprintf(f1, line.c_str());
                fprintf(f1, "\n");
            }
            fclose(f1);

            f1 = fopen("F1.txt", "r");
            if (f1 == NULL) {
                printf("Не удалось открыть файл F1.\n");
                return 1;
            }

            FILE *f2 = fopen("F2.txt", "w");
            if (f2 == NULL) {
                printf("Не удалось создать файл F2.\n");
                fclose(f1);
                return 1;
            }

            char line[256];
            while (fgets(line, sizeof(line), f1)) {
                if (!have_digit(line)) {
                    fputs(line, f2);
                }
            }

            fclose(f1);
            fclose(f2);
                    
            break;
        }
        default:
            printf("Задание не выбрано.\n");
            break;
    }

    return 0;
}


int have_digit(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
};
