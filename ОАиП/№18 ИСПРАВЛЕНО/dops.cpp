#include <iostream>
#include <string>
#include <stdarg.h>
#include <cmath>
using namespace std;

// Задание 1
double calculateRoot(double (*func)(double), double, double, double);

// Вариант 12
// Написать функцию, проверяющую есть ли отрицательные элементы в заданном одномерном массиве размерностью n.
// Удалить из массива все отрицательные элементы, удаленный элемент заполняется нулем и переносится в конец массива.
int *delNegative(int, ...);
bool hasNegative(int *, int);

// Вариант 14
// Написать функцию, которая удаляет все пробелы из строк
void compr(int, ...);

// Вариант 16
// Написать функцию, которая определяет, есть ли в тексте слова, начинающиеся с буквы а, и сколько та-ких слов.
// С помощью этой функции проверить несколько строк.
void findWordsStartsA(int, ...);

// Функции для задания 1
double f12_1(double x)
{
    return 2 * x + x * x * x - 7;
}
double f12_2(double x)
{
    return exp(x) + 2 * x;
}
double f14_1(double x)
{
    return exp(x) + x - 4;
}
double f14_2(double x)
{
    return x * x - 4;
}
double f16_1(double x)
{
    return sin(x) + 2 + x;
}
double f16_2(double x)
{
    return 2 + x * x * x;
}

int main()
{
    system("chcp 1251");

    int variant, exercise;
    cout << "Введите вариант: ";
    cin >> variant;
    switch (variant)
    {
    case 12:
    {
        cout << "Введите задание: ";
        cin >> exercise;
        if (exercise == 1)
        {
            double e = 0.001, a, b;
            cout << "===== ЗАДАНИЕ 1 ======" << endl;
            cout << "Введите значения a, b: ";
            cin >> a >> b;

            double f1X = calculateRoot(f12_1, a, b, e);
            double f2X = calculateRoot(f12_2, a, b, e);

            if (f1X)
            {
                cout << "Корень первой функции: " << f1X << endl;
                cout << "Корень второй функции: " << f2X << endl;
            }
        }
        else if (exercise == 2) // Исправлено
        {
            cout << "===== ЗАДАНИЕ 2 =====" << endl;

            int n1 = 6, n2 = 5, n3 = 4;
            int *arrPtr1 = delNegative(n1, 1, 2, 3, -5, -8, 2);
            int *arrPtr2 = delNegative(n2, -5, -3, 2, 5, 3);
            int *arrPtr3 = delNegative(n3, -1, -2, -3, 4);

            for (int i = 0; i < n1; i++)
            {
                cout << arrPtr1[i] << '\t';
            }
            cout << endl;
            for (int i = 0; i < n2; i++)
            {
                cout << arrPtr2[i] << '\t';
            }
            cout << endl;
            for (int i = 0; i < n3; i++)
            {
                cout << arrPtr3[i] << '\t';
            }
            cout << endl;
        }
        else
        {
            cerr << "Такого задания нет." << endl;
        }
        break;
    }
    case 14:
    {
        cout << "Введите задание: ";
        cin >> exercise;
        if (exercise == 1)
        {
            double e = 0.001, a, b;
            cout << "===== ЗАДАНИЕ 1 ======" << endl;
            cout << "Введите значения a, b: ";
            cin >> a >> b;

            double f1X = calculateRoot(f14_1, a, b, e);
            double f2X = calculateRoot(f14_2, a, b, e);

            if (f1X)
            {
                cout << "Корень первой функции: " << f1X << endl;
                cout << "Корень второй функции: " << f2X << endl;
            }
        }
        else if (exercise == 2)
        {
            cout << "===== ЗАДАНИЕ 2 =====" << endl;

            compr(2, "hello world apple", "airplane yellow black red");

            compr(1, "English Russian Belarusian");

            compr(3, "blackberry blueberry raspberry", "anime tomorrow England", "Nikolay Beloded");
        }
        else
        {
            cerr << "Такого задания нет." << endl;
        }
        break;
    }
    case 16:
    {
        cout << "Введите задание: ";
        cin >> exercise;
        if (exercise == 1)
        {
            double e = 0.001, a, b;
            cout << "===== ЗАДАНИЕ 1 ======" << endl;
            cout << "Введите значения a, b: ";
            cin >> a >> b;

            double f1X = calculateRoot(f16_1, a, b, e);
            double f2X = calculateRoot(f16_2, a, b, e);

            if (f1X)
            {
                cout << "Корень первой функции: " << f1X << endl;
                cout << "Корень второй функции: " << f2X << endl;
            }
        }
        else if (exercise == 2)
        {
            cout << "===== ЗАДАНИЕ 2 ======" << endl;

            findWordsStartsA(2, "biba", "aboba");
            findWordsStartsA(5, "Abema", "arangutang", "homosapiens");
            findWordsStartsA(3, "hernya", "haval", "aston martin");
        }
        else
        {
            cerr << "Такого задания нет." << endl;
        }
        break;
    }
    default:
    {
        cerr << "Такого варианта нет" << endl;
    }
    }
    return 0;
}

// Задание 1
double calculateRoot(double (*func)(double), double a, double b, double e)
{
    double x;
    while (abs(a - b) > 2 * e)
    {
        x = (a + b) / 2;
        if (func(x) * func(a) <= 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
    }
    return x;
}

// Вариант 12
int *delNegative(int n, ...)
{
    if (n <= 0)
        return nullptr;

    int *output = new int[n];
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
    {
        output[i] = va_arg(args, int);
    }
    va_end(args);

    while (hasNegative(output, n))
    {
        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (output[i] < 0 && output[j] != 0)
            {
                std::swap(output[i] = 0, output[j--]);
            }
            else if (output[i] < 0)
                output[i] = 0;
        }
    }

    return output;
}

bool hasNegative(int *arrStart, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arrStart[i] < 0)
        {
            return true;
        }
    }
    return false;
}

// Вариант 14

void compr(int n, ...)
{
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
    {
        const char *str = va_arg(args, const char *);
        string output;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] != ' ')
            {
                output += str[i];
            }
        }
        cout << "Сжатая строка: " << output << endl;
    }
    va_end(args);
}

// Вариант 16

void findWordsStartsA(int n, ...)
{
    va_list args;
    va_start(args, n);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        const char *word = va_arg(args, const char *);
        if (word[0] == 'a' || word[0] == 'A')
        {
            count++;
            cout << "Слово начинается с \"a\": " << word << endl;
        }
    }
    cout << "Количество слов, начинающихся с \"a\": " << count << endl;
}