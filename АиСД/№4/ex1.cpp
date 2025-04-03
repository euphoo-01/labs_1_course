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

    if (N >= 10000) {
        cerr << "Ошибка! N слишком большое." << endl;
        return 1;
    }

    srand(static_cast<int>(time(nullptr)));
    int* price_array = new int[N];
    for (int i = 0; i < N; i++) {
        price_array[i] = (std::rand() % 100) + 1;
    }

    qsort(price_array, N);

    // Отсортированный массив делим пополам. 
    // Левая половина - нечетные элементы, правая половина - четные элементы
    int* left_half = new int[N / 2];
    int* right_half = new int[N - N / 2];

    for (int i = 0; i < N / 2; i++) {
        left_half[i] = price_array[i];
    }
    for (int i = N / 2, j = 0; i < N; i++, j++) {
        right_half[j] = price_array[i];
    }


    int left_index = 0, right_index = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0 && left_index < N / 2) {
            price_array[i] = left_half[left_index++];
        }
        else if (right_index < N - N / 2) { // Те что по акции на халяву
            price_array[i] = right_half[right_index++];
        }
    }

    int max_sum = 0;
    for (int i = 0; i < N; i += 2) {
        max_sum += price_array[i];
    }

    cout << "Порядок пробивания товаров: ";
    for (int i = 0; i < N; i++) {
        cout << price_array[i] << '\t';
    }
    cout << endl;
    cout << "Максимальная сумма чека: " << max_sum << endl;

    delete[] price_array;
    delete[] left_half;
    delete[] right_half;
    return 0;
}