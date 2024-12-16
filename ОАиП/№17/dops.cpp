#include <iostream>
using namespace std;

//  �������� �������
void input1DArray(int*, int);
void input2DArray(int**, int*, int*);
void print2DArray(int**, int, int);
void print1DArray(int*, int);
void delete2DArray(int**, int);

// ������� 12
int countNegative(int*, int);

int findRowOfNegative(int**, int, int);
void decraseCol(int**, int, int);

// ������� 14
int findMinElement(int*, int);
int findMaxElement(int*, int);

int findPositiveRow(int**, int, int);
void inverseRow(int**, int, int, int);

// ������� 16
int findMaxNegativeElementIndex(int*, int);
void swapThisWithLast(int*, int, int);

bool everyRowHasNegative(int**, int, int);
void invertMatrix(int**, int, int);


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

			delete[] line;
		}
		else if (exercise == 2) {
			cout << "===== ������� 2 =====" << endl;

			int n, m;
			cout << "������� ���������� ����� �������: "; cin >> n;
			cout << "������� ���������� �������� �������:"; cin >> m;

			int** matrix = new int*[n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[m];
			}
            input2DArray(matrix, &n, &m);

			if (int row = findRowOfNegative(matrix, n, m)) {
                cout << "� ������� ����������� ������, ���������� ���� �� ���� ������������� ������� - " << row+1 << " ������." << endl;
				decraseCol(matrix, n, row);
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "� ������� ��� ������������� ���������." << endl;
			}
			
			delete2DArray(matrix, n);
		}
		else {
			cerr << "������ ������� ���!" << endl;
		}
		break;
	}
	case 14: {
		if (exercise == 1) {
			cout << "===== ������� 1 ======" << endl;
			
			int n;
			cout << "������� n: "; cin >> n;
			int* line = new int[n];
			input1DArray(line, n);
			
			int difference = findMaxElement(line, n) - findMinElement(line, n);
			cout << "�������� ������������� � ������������ ��������� �������: " << difference;
			cout << "����������� ������� �������: " << findMaxElement(line, n);
			cout << "����������� ������� �������: " << findMinElement(line, n);
			
			delete[] line;
		}
		else if (exercise == 2) {
			cout << "===== ������� 2 ======" << endl;

			int n, m;
			cout << "������� ���������� �����: "; cin >> n;
			cout << "������� ���������� ��������: "; cin >> m;

			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[m];
			}

			cout << "������� �������� �������: " << endl;
			input2DArray(matrix, &n, &m);
			int positiveRow;
			if (positiveRow = findPositiveRow(matrix, n, m)) {
				inverseRow(matrix, n, m, positiveRow);
				cout << "� ������� ���� �������, ��� ��� �������� �������������: " << positiveRow << endl;
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "� ������� ��� �������, ����������� ������ ������������� ��������." << endl;
			}

			delete2DArray(matrix, n);
		}
		else {
			cerr << "������ ������� ���!" << endl;
		}
		break;
	}
	case 16: {
		if (exercise == 1) {
			cout << "====== ������� 1 ======" << endl;

			int n;
			cout << "������� n: "; cin >> n;
			int* line = new int[n];

			int maxNegativeIndex = findMaxNegativeElementIndex(line, n);
			int maxNegativeElement = line[maxNegativeIndex];
			
			swapThisWithLast(line, n, maxNegativeIndex);
			cout << "������������ ������������� ������� �������: " << maxNegativeElement << endl;
			cout << "��������� ����� ����: " << endl;
			print1DArray(line, n);

			delete[] line;
		}
		else if (exercise == 2) {
			cout << "===== ������� 2 =====" << endl;

			int n, m;
			cout << "������� ���������� �����: "; cin >> n;
			cout << "������� ���������� ��������: "; cin >> m;
			
			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[m];
			}

			input2DArray(matrix, &n, &m);

			if (everyRowHasNegative(matrix, n, m)) {
				cout << "������ ������ ������� ����� ����-�� ���� ������������� �������." << endl;
				cout << "��������� ��������: " << endl;
				invertMatrix(matrix, n, m);
				print2DArray(matrix, n, m);
			}
			else {
				cerr << "� ����� �� ������ ������� ��� �������������� ��������." << endl;
			}

			delete2DArray(matrix, n);
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
void print1DArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\t';
	}
}

void delete2DArray(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

// ������� 12
int countNegative(int* inputArr, int n) {
	int count = 0;
	for (int i = 1; i < n; i+=2)
		if (inputArr[i] < 0)
			count++;
	return count;
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


// ������� 14
int findMinElement(int* arr, int n) {
	int min = *arr;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int findMaxElement(int* arr, int n) {
	int max = *arr;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int findPositiveRow(int** arr, int n, int m) {
	bool isPositive;
	for (int j = 0; j < m; j++) {
		isPositive = true;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] < 0)
			{
				isPositive = false;
				break;
			}
		}
		if (isPositive)
			return j+1;
	}
	return 0;
}
void inverseRow(int** arr, int n, int m, int row) {
	row = row - 1;
	if (row > 0 && row < m) {
		for (int i = 0; i < n; i++) {
			arr[i][row - 1] *= -1;
		}
	}
}


// ������� 16
int findMaxNegativeElementIndex(int* arr, int n) {
	int min = INT_MAX;
	int minIndex;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0 && arr[i] < min) {
			min = arr[i];
			minIndex = i;
		}
	}
	return min;
}
void swapThisWithLast(int* arr, int n, int index) {
	int buffer = arr[index];
	arr[index] = arr[n-1];
	arr[n - 1] = buffer;
}
bool everyRowHasNegative(int** arr, int n, int m) {
	bool currentRowHasNegative = false;
	for (int i = 0; i < n; i++) {
		currentRowHasNegative = false;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < 0) {
				currentRowHasNegative = true;
			}
		}
		if (!currentRowHasNegative)
			return false;
	}
	if (currentRowHasNegative)
		return true;
	else
		return false;
}
void invertMatrix(int** arr, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] *= -1;
}