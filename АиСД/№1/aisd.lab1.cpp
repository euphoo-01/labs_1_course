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

    cout << "������� ����� N (��������� � 0): ";
    cin >> n;

    clock_t startTime = clock();
    for (int i = 2; i <= n + 1; i++)
    {
        fSum = f0 + f1;
        f0 = f1;
        f1 = fSum;
    }
    clock_t endTime = clock();
    double time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    int mins = time / 60;
    double secs = time - mins * 60;

    cout << "����� ��� ������� " << n << " � ������������������ ����� ���������: " << fSum << endl;
    cout << "����� ���������� �����: " << mins << (mins <= 1 ? " ������ " : (mins > 10 ? " ����� " : " ������ ")) << secs << " ������" << endl;

    startTime = clock();
    cout << "����� ��� ������� " << n << " � ������������������ ����� ���������: " << fibo(n + 1) << endl;
    endTime = clock();
    time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    mins = time / 60;
    secs = time - mins * 60;

    cout << "����� ���������� ��������: " << mins << (mins <= 1 ? " ������ " : (mins > 10 ? " ����� " : " ������ ")) << secs << " ������" << endl;
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