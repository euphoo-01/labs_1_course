#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void qsort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int i = 0;
    int j = size - 1;

    int mid = arr[size / 2];

    do {
        while (arr[i] > mid) {
            i++;
        }
        while (arr[j] < mid) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort(arr, j + 1);
    }
    if (i < size) {
        qsort(arr + i, size - i);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введите N: ";
    cin >> N;

    if (N >= 10000 || N <= 0) {
        cerr << "Ошибка! Введите корректное N." << endl;
        return 1;
    }

    srand(static_cast<int>(time(nullptr)));
    int* results_array = new int[N];
    for (int i = 0; i < N; i++) {
        results_array[i] = (std::rand() % 100) + 1;
    }

    qsort(results_array, N);

    for (int i = 0; i < N; i++) {
        cout << results_array[i] << '\t';
    }
    cout << endl;

    int place = 1;
    int counter = 0;
    if (N > 3) {
        for (int i = 0; i < N - 1 && place <= 3; i++) {
            if (results_array[i] != results_array[i + 1]) {
                place++;
            }
            counter++;
        }
    }
    else {
        for (counter = 0; counter < N; counter++);
    }


    cout << "Количество призеров: " << counter << endl;

    return 0;

}