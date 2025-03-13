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
    for (int i = 0; i < N; ++i){
        A[i] = rand();
        cout << A[i] << '\t';
    }

    int* B = new int[N];
    int* C = new int[N];
    int* D = new int[N];
    int* E = new int[N];
    for (int i = 0; i < N; ++i){
        B[i] = C[i] = D[i] = E[i] = A[i];
    }

    clock_t start = clock();
    //Пузырьковая сортировка
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N - 1; ++j){
            if (B[j] > B[j + 1]){
                swap(B[j], B[j + 1]);
            }
        }
    }
    clock_t end = clock();

    cout << "\nМассив B: \n";
    for (int i = 0; i < N; ++i){
        cout << B[i] << '\t';
    }
    cout << "\nВремя пузырьковой сортировки: " << ((double)end - start) / CLOCKS_PER_SEC << endl;

    
    // Сортировка вставкой
    start = clock();
    for(int i = 1; i < N; i++)     
	for(int j = i; j > 0 && C[j-1] > C[j]; j--)
			swap(C[j-1], C[j]);
    end = clock();

    cout << "\nМассив C: \n";
    for (int i = 0; i < N; ++i){
        cout << C[i] << '\t';
    }
    cout << "\nВремя сортировки вставкой: " << ((double)end - start) / CLOCKS_PER_SEC << endl;


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
    for (int i = 0; i < N; ++i){
        cout << D[i] << '\t';
    }
    cout << "\nВремя сортировки выбором: " << ((double)end - start) / CLOCKS_PER_SEC << endl;


    // Быстрая сортировка
    start = clock();
    qsort(E, N);
    end = clock();

    cout << "Массив E: \n";
    for (int i = 0; i < N; ++i){
        cout << E[i] << '\t';
    }
    cout << "\nВремя быстрой сортировки: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
}

void qsort(int* arr, int size) {
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
        qsort(arr, j+1);
    }
    if (j < size) {
        qsort(&arr[i], size - i);
    }
}