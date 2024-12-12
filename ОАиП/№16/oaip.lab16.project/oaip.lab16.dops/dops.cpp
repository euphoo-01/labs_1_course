#include <iostream>
#include <string>
using namespace std;

// ����� �������
void input2DArray(int** arr, int n, int m);
void input1DArray(float* arr, int sz);
void printArray(int** arr, int n, int m);
void deleteArray(int** arr, int n);

//������� 12
int findMinElement(int** arr, int n, int m);
bool isSimillar(int** arr, int sz, int k);

//������� 14
int minAbsoluteElementIndex(float* arr, int sz);
int firstNegativeIndex(float* arr, int sz);
float sumOfAbsoluteElements(float* arr, int sz, int pos);

bool haveBSTU(string str);

//������� 16
int maxNumber(int* arr, int sz);
int countMatch(int* arr, int sz, int number);

string shortestWord(string str);
string longestWord(string str);


int main() {
	system("chcp 1251");

	int variant, exercise;
	cout << "������� �������: "; cin >> variant;
	cout << "������� ����� �������: "; cin >> exercise;

	switch (variant) {
	case 12: {
		if (exercise == 1) {
			cout << "====== ������� 1 =======" << endl;

			int d, p;
			cout << "������� ���������� ����� �������(<= 16): "; cin >> d;
			cout << "������� ��������� �������� �������(<= 18): "; cin >> p;

			if (d <= 16 && p <= 18) {
				int** F2 = new int* [d];
				for (int i{}; i < d; ++i) {
					F2[i] = new int[p];
				}

				input2DArray(F2, d, p);

				for (int i{}; i < d; i++) {
					F2[i][i] = findMinElement(F2, i, p);
				}

				printArray(F2, d, p);
				deleteArray(F2, d);
				
			}
		}
		else if (exercise == 2) {
			cout << "====== ������� 2 ======" << endl;

			const int SIZE = 4;
			int** matrix = new int* [SIZE];
			for (int i{}; i < SIZE; ++i) {
				matrix[i] = new int[SIZE];
			}
			
			input2DArray(matrix, SIZE, SIZE);

			for (int k{}; k < SIZE; k++) {
				if (isSimillar(matrix, SIZE, k)) {
					cout << "k = " << k << endl;
				}
			}
			deleteArray(matrix, SIZE);
		}
		else {
			cerr << "������ ������� ���." << endl;
		}
		break;
	}
	case 14: {
		if (exercise == 1) {
			cout << "===== ������� 1 =====" << endl;

			int n;
			cout << "������� ������ �������: "; cin >> n;

			float* line = new float[n];

			input1DArray(line, n);

			cout << "����������� �� ������ ������� ������� ��������� ��� �������" << minAbsoluteElementIndex(line, n) + 1
				<< " � ����� " << line[minAbsoluteElementIndex(line, n)] << endl;

			int negativeIndex;
			if ((negativeIndex = firstNegativeIndex(line, n)) >= 0)
			{
				cout << "����� ������� ��������� �������, ������������� ����� ������� �������������� ��������: "
					<< sumOfAbsoluteElements(line, n, negativeIndex) << endl;
			}
			else {
				cerr << "� ������� ��� ������������� ���������!" << endl;
			}
			
			delete[] line;
		}
		else if (exercise == 2) {
			cout << "===== ������� 2 =====" << endl;

			string input;
			cout << "������� ������: ";
			cin.ignore();
			getline(cin, input);

			if (haveBSTU(input)) {
				cout << "������ �������� ����� \"����\"." << endl;
			}
			else {
				cerr << "������ �� �������� ����� \"����\"." << endl;
			}
		}
		else {
			cerr << "������ ������� ���." << endl;
		}
		
		break;
	}
	case 16: {
		if (exercise == 1) {
			cout << "===== ������� 1 =====" << endl;

			int n;
			cout << "������� n: "; cin >> n;

			int* A = new int[n];

			int max = maxNumber(A, n);
			cout << "���������� ������������� ������������ ��������� \"" << max << "\" � �������: " 
				<< countMatch(A, n, max) << endl;
		}
		else if (exercise == 2) {
			cout << "===== ������� 2 =====" << endl;

			string str;
			cout << "������� ������: "; cin.ignore();
			getline(cin, str);
			
			string shortest = shortestWord(str),
				longest = longestWord(str);

			cout << "����� �������� ����� � ������: " << shortest << endl;
			cout << "����� ������� ����� � ������: " << longest << endl;
		}
		else {
			cerr << "������ ������� ���." << endl;
		}
		break;
	}
	default: {
		cerr << "������, ������ �������� ���." << endl;
		break;
	}
	}
	return 0;
}


// ����� �������
void input2DArray(int** arr, int n, int m) {
	cout << "������� �������� ������� (" << n << ", " << m << "): " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cin >> arr[i][j];
		}
		cout << endl;
	}
}

void input1DArray(float* arr, int sz) {
	cout << "������� �������� ������� (" << sz << "): " << endl;
	for (int i{}; i < sz; i++) {
		cin >> arr[i];
	}
}

void printArray(int** arr, int n, int m) {
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

void deleteArray(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}


// ������� 12
int findMinElement(int** arr, int row, int m) {
	int tempMin = arr[row][0];
	for (int j{}; j < m; j++) {
		if (arr[row][j] < tempMin) {
			tempMin = arr[row][j];
		}
	}
	return tempMin;
}

bool isSimillar(int** arr, int sz, int k) {
	for (int j{}; j < sz; j++) {
		if (arr[k][j] != arr[j][k]) {
			return false;
		}
	}
	return true;
}


// ������� 14
int minAbsoluteElementIndex(float* arr, int sz) {
	float tempMin = abs(*arr);
	int minIndex = 0;
	for (int i{}; i < sz; i++) {
		if (abs(arr[i]) < tempMin) {
			tempMin = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}
float sumOfAbsoluteElements(float* arr, int sz, int pos) {
	float sum = 0;
	for (int i = pos + 1; i < sz; i++) {
		sum += arr[i];
	}
	return sum;
}

int firstNegativeIndex(float* arr, int sz) {
	for (int i{}; i < sz; i++) {
		if (arr[i] < 0) {
			return i;
		}
	}
	return -1;
}

bool haveBSTU(string str) {
	
	for (size_t i = 1; i < str.length() - 3; i++) {
		if (str.substr(i, 4) == "����") {
			return true;
		}
	}
	return false;
}


// ������� 16
int maxNumber(int* arr, int sz) {
	int maxNumber = *arr;
	for (int i{}; i < sz; i++) {
		maxNumber = arr[i] > maxNumber ? arr[i] : maxNumber;
	}
	return maxNumber;
}

int countMatch(int* arr, int sz, int number) {
	int count = 0;
	for (int i{}; i < sz; i++) {
		if (arr[i] == number) {
			count++;
		}
	}
	return count;
}

string shortestWord(string str) {
	string current = "", shortest = str;
	
	for (char ch : str) {
		if (isspace(ch)) {
			if (current.length() < shortest.length() && current.length() != 0) {
				shortest = current;
			}
			current.clear();
		}
		else {
			current += ch;
		}
	}

	if (current.length() < shortest.length() && current.length() != 0) {
		shortest = current;
	}
	current.clear();

	return shortest;
}

string longestWord(string str) {
	string current = "", longest = "";

	for (char ch : str) {
		if (isspace(ch)) {
			if (current.length() > longest.length() && current.length() != 0) {
				longest = current;
			}
			current.clear();
		}
		else {
			current += ch;
		}
	}

	if (current.length() > longest.length() && current.length() != 0) {
		longest = current;
	}
	current.clear();

	return longest;
}