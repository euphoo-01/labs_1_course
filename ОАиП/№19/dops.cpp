#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool haveSimmilar(vector<int> &, int);

int main()
{
    system("chcp 1251");

    printf("Введите вариант: ");
    int choice;
    scanf_s("%i", &choice);

    switch (choice)
    {
    case 12:
    {
        printf("Введите номер задания: ");
        int variant;
        scanf_s("%d", &variant);
        if (variant == 1)
        {
            FILE *file = fopen("var_12/input_12.dat", "r");
            if (file == NULL)
            {
                printf("Не удалось открыть файл!\n");
                break;
            }

            int n;
            fscanf(file, "%i", &n);

            float **matrix = new float *[n];
            for (int i = 0; i < n; i++)
            {
                matrix[i] = new float[n];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fscanf(file, "%f", &matrix[i][j]);
                }
            }

            fclose(file);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%f\t", matrix[i][j]);
                }
                printf("\n");
            }

            int k;
            printf("Введите k: ");
            scanf_s("%i", &k);

            FILE *out_file = fopen("var_12/output_12.dat", "w");
            if (out_file == NULL)
            {
                printf("Не удалось открыть файл для записи!\n");
            }

            for (int i = 0; i < n; i++)
            {
                fprintf(out_file, "%f ", matrix[k][i]);
            }

            fclose(out_file);

            printf("ГОТОВО!\n");
        }
        else if (variant == 2)
        {
            FILE *fileA = fopen("var_12/nameA.dat", "r");
            FILE *fileB = fopen("var_12/nameB.dat", "r");
            FILE *fileC = fopen("var_12/nameC.dat", "r");

            if (fileA == NULL && fileB == NULL && fileC == NULL)
            {
                printf("Не удалось открыть один из файлов.\n");
                break;
            }

            FILE *out_file = fopen("var_12/output2_12.dat", "w");

            float a, b, c, min;
            while (((fscanf_s(fileA, "%f", &a)) == 1) && ((fscanf_s(fileB, "%f", &b)) == 1) && ((fscanf_s(fileC, "%f", &c)) == 1))
            {
                fprintf(out_file, "%f ", fmin(fmin(a, b), c));
            }
            if (((fscanf_s(fileA, "%f", &a)) != 1) || ((fscanf_s(fileB, "%f", &b)) == 1) || ((fscanf_s(fileC, "%f", &c)) == 1))
            {
                printf("ГОТОВО!\n");
            }
            else if (((fscanf_s(fileA, "%f", &a)) != 1) && ((fscanf_s(fileB, "%f", &b)) != 1) && ((fscanf_s(fileC, "%f", &c)) != 1))
            {
                printf("Файлы не одинаковой длины.\n");
            }

            fclose(fileA);
            fclose(fileB);
            fclose(fileC);
            fclose(out_file);
        }
        else
        {
            printf("Такого варианта нет.");
        }
        break;
    }
    case 14:
    {
        printf("Введите вариант: ");
        int variant;
        scanf_s("%d", &variant);
        if (variant == 1)
        {
            FILE *file = fopen("var_14/input_14.dat", "r");
            if (file == NULL)
            {
                printf("Не удалось открыть файл!\n");
                break;
            }

            int n;
            fscanf(file, "%i", &n);

            float **matrix = new float *[n];
            for (int i = 0; i < n; i++)
            {
                matrix[i] = new float[n];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fscanf(file, "%f", &matrix[i][j]);
                }
            }

            fclose(file);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%f\t", matrix[i][j]);
                }
                printf("\n");
            }

            int k;
            printf("Введите k: ");
            scanf_s("%i", &k);

            FILE *out_file = fopen("var_14/output_14.dat", "w");
            if (out_file == NULL)
            {
                printf("Не удалось открыть файл для записи!\n");
            }

            fprintf(out_file, "%i ", n);
            for (int i = 0; i < n; i++)
            {
                fprintf(out_file, "%f\n", matrix[i][k]);
            }

            fclose(out_file);

            printf("ГОТОВО!\n");
        }
        else if (variant == 2)
        {
            FILE *file = fopen("var_14/f.dat", "r");
            if (file == NULL)
            {
                printf("Не удалось открыть файл!\n");
            }

            vector<int> nums;
            float a;
            while ((fscanf_s(file, "%f", &a)) == 1)
            {
                nums.push_back(a);
            }

            for (float i : nums)
            {
                printf("%f \t", i);
            }

            FILE *out_file = fopen("var_14/g.dat", "w");
            if (out_file == NULL)
            {
                printf("Не удалось открыть файл для записи.\n");
            }

            for (int i : nums)
            {
                if (!haveSimmilar(nums, i))
                {
                    fprintf(out_file, "%i ", i);
                }
            }

            printf("ГОТОВО!\n");
        }
        else
        {
            printf("Такого варианта нет.");
        }
        break;
    }
    case 16:
    {
        printf("Введите вариант: ");
        int variant;
        scanf_s("%d", &variant);
        if (variant == 1)
        {
            FILE *fileA = fopen("var_16/fileA.dat", "r");
            FILE *fileB = fopen("var_16/fileB.dat", "r");

            if (fileA == NULL && fileB == NULL)
            {
                printf("Не удалось открыть файлы.\n");
                break;
            }

            FILE *fileC = fopen("var_16/fileC.dat", "w");
            if (fileC == NULL)
            {
                printf("Не удалось открыть файл для записи.\n");
                break;
            }

            int a, b;
            while ((fscanf_s(fileA, "%i", &a) == 1) && (fscanf_s(fileB, "%i", &b) == 1))
            {
                fprintf(fileC, "%i ", a + b);
            }
            if ((fscanf_s(fileA, "%i", &a) != 1) && (fscanf_s(fileB, "%i", &b) != 1))
            {
                printf("ГОТОВО!\n");
            }
            else if ((fscanf_s(fileA, "%i", &a) != 1) || (fscanf_s(fileB, "%i", &b) != 1))
            {
                printf("Файлы разной длины.\n");
            }
        }
        else if (variant == 2)
        {
            FILE *file1 = fopen("var_16/file1.dat", "r");
            if (file1 == NULL)
            {
                printf("Не удалось открыть файл.\n");
                break;
            }
            int a;
            int n = 0;
            vector<int> positive, negative;
            while (fscanf_s(file1, "%i", &a) == 1)
            {
                if (a > 0)
                {
                    positive.push_back(a);
                }
                else if (a < 0)
                {
                    negative.push_back(a);
                }
            }

            fclose(file1);

            FILE *file2 = fopen("var_16/file2.dat", "w");
            if (file2 == NULL)
            {
                printf("Не удалось открыть файл для записи!\n");
                break;
            }

            size_t i_positive = 0, i_negative = 0;
            while (i_positive < positive.size() || i_negative < negative.size())
            {
                for (int i = 0; i < 10 && i_positive < positive.size(); i++)
                {
                    fprintf(file2, "%i ", positive[i_positive++]);
                }
                for (int i = 0; i < 10 && i_negative < negative.size(); i++)
                {
                    fprintf(file2, "%i ", negative[i_negative++]);
                }
            }
        }
        else
        {
            printf("Такого варианта нет.");
        }
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

bool haveSimmilar(vector<int> &arr, int x)
{
    int count = 0;
    for (float i : arr)
    {
        if (i == x)
        {
            count++;
            if (count > 1)
            {
                return true;
            }
        }
    }
    return false;
}