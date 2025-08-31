#include <iostream>
#include <ctime>
using namespace std;

// ������ ��� ������� A � B, ������ �� n ���������. ���������� ���������� ����� ����� k, ��� �������: A[k] = B[k], A[k] > B[k] � A[k] < B[k].
void v12e1() {
	int n;
	cout << "������� n: "; cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	int max = 10,
		min = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) { // ���� �����
		A[i] = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		B[i] = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << A[i] << '\t' << B[i] << '\n';
	}

	int counter = 0, counter2 = 0, counter3 = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == B[i])
			counter++;
		else if (A[i] > B[i])
			counter2++;
		else if (A[i] < B[i])
			counter3++;
	}
	cout << "���������� k, ��� ������� A[k] = B[k]: " << counter << endl;
	cout << "���������� k, ��� ������� A[k] > B[k]: " << counter2 << endl;
	cout << "���������� k, ��� ������� A[k] < B[k]: " << counter3 << endl;
	
	delete[] A;
	delete[] B;
}

// � ���������� ������� A ����� ������ ���� ��������� �������, ������� �����, ������ � ������ ��������-�� ����� k.
void v12e2() {
	int k;
	cout << "������� k: "; cin >> k;
	int A[10]={},
		min = 0,
		max = 10;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) { // ���� �����
		*(A+i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << *(A+i) << '\t';
	}

	int counter = 0, counter2 = 0, counter3 = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] == k)
			counter++;
		else if (A[i] > k)
			counter2++;
		else if (A[i] < k)
			counter3++;
		else
			cout << "\n����� ��������� ���!";
	}
	cout << "\n���������� ����� A[i], A[i] = k: " << counter << endl;
	cout << "���������� ����� A[i], A[i] > k: " << counter2 << endl;
	cout << "���������� ����� A[i], A[i] < k: " << counter3 << endl;
}

void v14e1() {
	int A[15]={}, B[15]={},
		max = 18,
		min = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++) { // ���� �����
		*(A + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		*(B + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << *(A + i) << '\t' << *(B + i) << '\n';
	}
	
	cout << "=============\n";
	int counter = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (*(A + i) == *(B + j)) {
				cout << *(A + i) << '\t' << *(B + j) << '\n';
				counter++;
			}
		}
	}

	cout << "���������� ���������� ���: " << counter << endl;
}

// ������������� ������ K ���, ����� ������� ��� ����� ������� ����� t, � ����� - �������. 
void v14e2() {
	int t;
	cout << "������� k: "; cin >> t;
	int K[10] = {},
		min = 0,
		max = 10;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) { // ���� �����
		*(K + i) = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << *(K + i) << '\t';
	}

	int* left = K;
	int* right = K + 9;

	while (left < right) {

		while (*left < t && left < right) {
			++left;
		}


		while (*right >= t && left < right) {
			--right;
		}

		if (left < right) {
			swap(*left, *right);
			++left;
			--right;
		}
	}

	cout << "\n��������������� ������: \n";
	for (int i = 0; i < 10; ++i) {
		std::cout << K[i] << '\t';
	}
	std::cout << std::endl;

}

// ��� ������ X, ���������� k ���������, � ������ Y, ���������� n ���������. ������������ ������ Z, ��-�������� ����� �������� �������� P � Q.
void v16e1() {
	int n, k;
	cout << "������� k: "; cin >> k;
	cout << "������� n: "; cin >> n;
	int* X = new int[k];
	int* Y = new int[n];
	int max = 10,
		min = 0,
		minSize = k;

	srand((unsigned)time(NULL));

	for (int i = 0; i < k; i++) { // ���� �����
		X[i] = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << X[i] << '\t';
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		Y[i] = (int)(((double)rand() / (double)RAND_MAX) * (max - min) + min);
		cout << Y[i] << '\t';
	}

	cout << endl;
	if (n < minSize) n = minSize;
	int* Z = new int[minSize];
	Z[0] = -1;
	int i = 0;
	cout << "===================================================" << endl;
	for (int j = 0; j < minSize; j++) {
		if (X[j] == Y[j]) {
			Z[i] = X[j];
			cout << Z[i] << '\t'; i++;
		}
	}
	if (Z[0] == -1)
		cout << "������� ���.";

	delete[] X;
	delete[] Y;
	delete[] Z;

}

// ������ � ������� n �� �������� ������� ���������. ������������� ������ ���, ����� ������� ��� ������-������� ��������, � ����� �������������. 
int v16e2() {
	int n;

	cout << "������� ������ �������: ";
	cin >> n;

	if (n <= 0) {
		cout << "������ ������� ������ ���� ������ ����." << endl;
		return 1;
	}

	int* A = new int[n];

	cout << "������� �������� �������: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int* temp = new int[n];
	temp[0] = {}; // ����� �������������� � �������������������� ������
	int* ptr = temp;

	// ������� ������������� ���������
	for (int i = 0; i < n; i++) {
		if (A[i] < 0) {
			*ptr = A[i];
			ptr++;
		}
	}
	// ������� ������������� ���������
	for (int i = 0; i < n; i++) {
		if (A[i] > 0) {
			*ptr = A[i];
			ptr++;
		}
	}
	for (int i = 0; i < n; i++) {
		A[i] = temp[i];
	}

	delete[] temp;

	for (int i = 0; i < n; i++) {
		cout << A[i] << '\t';
	}
	cout << endl;

	delete[] A;
	return 0;
}

int main() {
	setlocale(LC_CTYPE, "RUSSIAN");
	//v12e1();
	//v12e2();
	//v14e1();
	//v14e2();
	//v16e1();
	//v16e2();
	return 0;
}