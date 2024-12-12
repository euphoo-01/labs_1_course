#include <iostream>
using namespace std;

//  �������� �������
void input1DArray(int* arr, int sz);
void input2DArray(int** arr, int* n, int* m);
void initialize2DArray(int** arr, int n, int m);

// ������� 12
int countNegative(int* inputArr, int n);

int findRowOfNegative(int** arr, int n, int m);
void decraseCol(int** arr, int n, int col);

// ������� 14
int findMinElement(int** arr, int n);

// ������� 16

int main() {
	system("chcp 1251");

	int variant, exercise;
	cout << "������� �������: "; cin >> variant;
	cout << "������� ����� �������: "; cin >> exercise;

	switch (variant) {
	case 12: {
		if (exercise == 1) {
			cout << "===== ������� 1 =====" << endl;
			
			int n;
			cout << "������� n: "; cin >> n;
			int* line = new int[n];

			input1DArray(line, n);

			if (int nNegatives = countNegative(line, n)) {
				cout << "���������� ������������� ��������� � �������: " << nNegatives << endl;
			}
			else {
				cerr << "� ������� ��� ������������� ���������!";
			}
		}
		else if (exercise == 2) {
			cout << "===== ������� 2 =====" << endl;

			int n, m;
			cout << "������� ���������� ����� �������: "; cin >> n;
			cout << "������� ���������� �������� �������:"; cin >> m;

			int** matrix = nullptr;
			initialize2DArray(matrix, n, m);

			if (int row = findRowOfNegative(matrix, n, m)) {
				decraseCol(matrix, n, row);
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "� ������� ��� ������������� ���������." << endl;
			}
			
		}
		else {
			cerr << "������ ������� ���!" << endl;
		}
		break;
	}
	case 14: {
		if (exercise == 1) {

		}
		else if (exercise == 2) {

		}
		else {
			cerr << "������ ������� ���!" << endl;
		}
		break;
	}
	case 16: {
		if (exercise == 1) {

		}
		else if (exercise == 2) {

		}
		else {
			cerr << "������ ������� ���!" << endl;
		}
		break;
	}
	default: {
		cerr << "������ �������� ���!" << endl;
		break;
	}
	}

	return 0;
}

// ���������������� �������

// �������� �������
void input1DArray(int* arr, int sz) {
	for (int i{}; i < sz; i++) {
		cout << "������� ������� ������� [" << i + 1 << "]: "; 
		cin >> arr[i];
	}
}
void input2DArray(int** arr, int* n, int* m) {
	for (int i{}; i < *n; i++) {
		cout << i + 1 << "-� ������: " << endl;
		for (int j{}; j < *m; j++) {
			cin >> arr[i][j];
		}
		cout << endl;
	}
}
void print2DArray(int** arr, int n, int m) {
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

void initialize2DArray(int** arr, int n, int m) {
	arr = new int* [n];
	for (int i{}; i < n; i++) {
		arr[i] = new int[m];
	}
}


// ������� 12
int countNegative(int* inputArr, int n) {
	int count = 0;
	for (int i = 1; i < n; i+=2)
		if (inputArr[i] < 0)
			count++;
}

int findRowOfNegative(int** arr, int n, int m) {
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (arr[i][j] < 0) {
				return i;
			}
		}
	}
}

void decraseCol(int** arr, int n, int col) {
	for (int i{}; i < n; i++) {
		arr[i][col] /= 2;
	}
}
