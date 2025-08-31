#include <iostream>
#include <ctime>
using namespace std;

bool isTrue(int* nowCell, int* B, int sizeB) { // �������� �� ������������
	for (int i = 0; i < sizeB; i++) {
		if (*nowCell == *(B + i)) return false;
	}
	return true;
}

int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	int A[15]={}, B[15]={},
		max = 18,
		min = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++) { // ���� �����
		*(A + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		*(B + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << *(A + i) << '\t' << *(B + i) << '\n';
	}

	int minArr = *A;

	cout << '\n';
	for (int i = 0; i < 15; i++) // �������� ����������
		if (isTrue((A + i), B, 15))
			if (*(A + i) < minArr) minArr = *(A + i);

	// ���� ������
	cout << "����������� �����, ������� ���� � ������� �, �� ��� � ������� �: " << minArr << endl; 
	return 0;
}