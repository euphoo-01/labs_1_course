#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void qsort(int*, int);

int main() {
    setlocale(LC_ALL, "Russian");
    long N;
    cout << "Введите число N: "; cin >> N;

    int* A = new int[N];

    cout << "Массив А[" << N << "]: " << endl;
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        A[i] = rand();
        cout << A[i] << '\t';
    }

    int* B = new int[N];
    int* C = new int[N];
    int* D = new int[N];
    int* E = new int[N];
    for (int i = 0; i < N; ++i) {
        B[i] = C[i] = D[i] = E[i] = A[i];
    }

    clock_t start = clock();
    //Пузырьковая сортировка
    for (int i = N - 1; i > 0; --i) {
        for (int j = 0; j < i; j++) {
            if (B[j] > B[j + 1])
                swap(B[j], B[j + 1]);
        }
    }
    clock_t end = clock();

    cout << "\nМассив B: \n";
    for (int i = 0; i < N; ++i) {
        cout << B[i] << '\t';
    }
    cout << "\nВремя пузырьковой сортировки: " << ((double)end - start) / CLOCKS_PER_SEC << " секунд(-ы)." << endl;
    system("pause");


    // Сортировка Шелла
    start = clock();

    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i++) {
            int temp = C[i];

            int j;
            for (j = i; j >= gap && C[j - gap] > temp; j -= gap)
                C[j] = C[j - gap];

            C[j] = temp;
        }
    }

    end = clock();

    cout << "\nМассив C: \n";
    for (int i = 0; i < N; ++i) {
        cout << C[i] << '\t';
    }
    cout << "\nВремя сортировки Шелла: " << ((double)end - start) / CLOCKS_PER_SEC << " секунд(-ы)." << endl;
    system("pause");


    // Сортивка выбором
    start = clock();
    for (int i = 0; i < N - 1; i++) {
        int smallest = i;

        for (int j = i + 1; j < N; j++) {
            if (D[j] < D[smallest]) {
                smallest = j;
            }
        }

        swap(D[i], D[smallest]);
    }
    end = clock();

    cout << "Массив D: \n";
    for (int i = 0; i < N; ++i) {
        cout << D[i] << '\t';
    }
    cout << "\nВремя сортировки выбором: " << ((double)end - start) / CLOCKS_PER_SEC << " секунд(-ы)." << endl;
    system("pause");


    // Быстрая сортировка
    start = clock();
    qsort(E, N);
    end = clock();

    cout << "Массив E: \n";
    for (int i = 0; i < N; ++i) {
        cout << E[i] << '\t';
    }
    cout << "\nВремя быстрой сортировки: " << ((double)end - start) / CLOCKS_PER_SEC << " секунд(-ы)." << endl;
    system("pause");
}

void qsort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int i = 0;
    int j = size - 1;

    int mid = arr[size / 2];

    do {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
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
