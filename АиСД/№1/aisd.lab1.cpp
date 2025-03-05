#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

long long int fibo(int);

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    long long int f0 = 0, f1 = 1, fSum;

    cout << "Введите число N (нумерация с 0): ";
    cin >> n;

    clock_t startTime = clock();
    for (int i = 2; i <= n; i++)
    {
        fSum = f0 + f1;
        f0 = f1;
        f1 = fSum;
    }
    clock_t endTime = clock();
    double time = (double)(endTime - startTime) / CLOCKS_PER_SEC; // Время в секундах
    int mins = time / 60;
    double secs = time - mins * 60;

    cout << "Число под номером " << n << " в последовательности чисел Фибоначчи: " << fSum << endl;
    cout << "Время выполнения цикла: " << mins << " минут(-а) " << secs << " секунд(-а)" << endl;

    startTime = clock();
    cout << "Число под номером " << n << " в последовательности чисел Фибоначчи: " << fibo(n) << endl;
    endTime = clock();
    time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    mins = time / 60;
    secs = time - mins * 60;

    cout << "Время выполнения рекурсии: " << mins << " минут(-а) " << secs << " секунд(-а)" << endl;
    return 0;
}

long long int fibo(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    return fibo(x - 1) + fibo(x - 2);
}