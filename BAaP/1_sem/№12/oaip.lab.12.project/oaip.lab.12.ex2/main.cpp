#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	int A[15]={}, B[15]={},
		max = 18,
		min = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++) {
		A[i] = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << A[i] << '\t';
	}

	cout << '\n';
	for (int i = 0; i < 15; i++) {
		B[i] = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << B[i] << '\t';
	}
	cout << "\nРезультат суммирования: \n";

	int C[15] = {};
	for (int i = 0; i < 15; i++) {
		*(C + i) = *(A + i) + *(B + i);
		cout << *(C + i) << '\t';
	}
	return 0;
}