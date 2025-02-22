#include <iostream>
#include <ctime>

using namespace std;

void ex_1();
void ex_2();
void ex_3();


int main() {
	system("chcp 1251");

	// ����� �������
	int choice;
	cout << "�������� �������, ������� ����� ���������: "; cin >> choice;

	switch (choice) {
	case 1: 
		ex_1();
		break;
	case 2:
		ex_2();
		break;
	case 3:
		ex_3();
		break;
	}

	return 0;
}


// ������ - ���� ���������� ������� ������� 2n, �������� ������� ����������� ��������� ������� � ��������� � �������� �� -10 �� 10. 
// �������� ����� �������, ����������� �� ����� ������� n x n � ������������ �� ������.

void ex_1() {

	const int n = 3;

	int A[2 * n][2 * n]; // ���������� ������� ������� 2n
	int maxValue = 10,
		minValue = -10;

	for (int i = 0; i < 2 * n; i++) { // ��������� ����� �� -10 �� 10
		for (int j = 0; j < 2 * n; j++) {
			A[i][j] = (int)(((double)rand() / (double)RAND_MAX) * (maxValue - minValue) + minValue);
			cout << A[i][j] << '\t';
			j == n-1 ? printf("\t") : j;
		}
		cout << '\n';
		i == n-1 ? printf("\n") : i;
	}

	int B[2 * n][2 * n];

	// ������������ ������
	for (int i = 0; i < n; i++) { // ������ ����
		for (int j = 0; j < n; j++) {
			B[i + n][j + n] = A[i][j];
		}
	}

	for (int i = 0; i < n; i++) { // ������ ����
		for (int j = n; j < 2 * n; j++) {
			B[i+n][j-n] = A[i][j];
		}
	}

	for (int i = n; i < 2 * n; i++) { // ������ ����
		for (int j = 0; j < n; j++) {
			B[i - n][j + n] = A[i][j];
		}
	}

	for (int i = n; i < 2 * n; i++) { // ��������� ����
		for (int j = n; j < 2 * n; j++) {
			B[i - n][j - n] = A[i][j];
		}
	}

	// �����
	cout << "���������:" << '\n';
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << B[i][j] << '\t';
			j == n-1 ? printf("\t") : j;
		}
		cout << '\n';
		i == n-1 ? printf("\n") : i;
	}

}

// ������� - ��������� ��������� ������� n ���������� ���������� ������� �������� n � n, 
// ������ ������ � ������ ������� ������� �������� ��� ����� �� 1 �� n. ��� ��������� n � ������� L(n, n) ��������� ��������� ������� ������� n. 


void ex_2() {

	const int n = 3;
	int L[n][n];

	// ��������� ���������� ��������
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			L[i][j] = (i + j) % n + 1; // �������� ���������, �.�. � ������� ��������� ���������� � 0
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << L[i][j] << '\t';
		}
		cout << '\n';
	}

}

// ������� - ����� ������������ ��������� ���������� ������������ ������� �������� ����, ����� �� ������������ ������� ��������� � ����� ������� ����,
// ��������� �� �������� - � ������� (2, 2), ��������� - � ������� (3, 3) � �. �., �������� ����� ������� ��� ������� ���������.

void ex_3() { // �
	const int n = 3;
	float F[n][n];

	cout << "������� ������: " << endl; // ���� �����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> F[i][j];
		}
		cout << "\n";
	}

	cout << "�������� �������: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << F[i][j] << '\t';
		}
		cout << '\n';
	}
	
	for (int diag = 0; diag < n; ++diag) {
		int maxRow = diag, maxCol = diag;
		for (int i = diag; i < n; ++i) {
			for (int j = diag; j < n; ++j) {
				if (F[i][j] > F[maxRow][maxCol] && F[i][j] != F[diag][diag]) {
					maxRow = i;
					maxCol = j;
					swap(F[diag][diag], F[maxRow][maxCol]);
				}
			}
		}
	}

	cout << "���������: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << F[i][j] << '\t';
		}
		cout << '\n';
	}
}