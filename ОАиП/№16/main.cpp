#include <iostream>
#include <string>
using namespace std;

// ������� 10

const string name = "matrix";

void deleteArray(int**, int);
int findIndexHasK(int**, int, int, int);

int countWords(string);
string swapCentralWords(string, int);
int main() {
	system("chcp 1251");

	int choice;
	cout << "����� ������� ���������? "; cin >> choice;
	
	switch (choice) {
	case 1: {
		int n, m;

		cout << "������� ���������� ����� �������: "; cin >> n;
		cout << "������� ���������� �������� �������: "; cin >> m;

		// ������������� �������
		int** matrix = new int* [n];
		for (int i{}; i < n; ++i) {
			matrix[i] = new int[m];
		}

		// ���� �������
		cout << "������� �������� �������: " << endl;
		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				cin >> matrix[i][j];
			}
			cout << endl;
		}

		int k;
		cout << "������� ����� k: "; cin >> k;

		int kIndex = findIndexHasK(matrix, n, m, k);

		// �����
		if (kIndex)
			cout << "������� �������, � ������� ���� k: " << kIndex << endl;
		else
			cerr << "����� k ��� � �������." << endl;

		deleteArray(matrix, n);

		break;
	}
	case 2: {
		string s{};

		cout << "������� ������: "; 
		cin.ignore(); // ������� ������ \n
		getline(cin, s);

		int wordCount = countWords(s);
		if (wordCount % 2 == 0) { // ���� ���������� ���� ������
			s = swapCentralWords(s, wordCount);
			cout << "���������: " << endl << s << endl;
		}
		else {
			cerr << "���������� ���� � ������ ��������!" << endl;
		}

		break;
	}
	default: {
		cerr << "������ �������� �� ����������!";
		break;
	}
	}
}

// ������� ��� �������
void deleteArray(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

int findIndexHasK(int** arr, int n, int m, int k) {
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (*(*(arr + i) + j) == k) {
				return j+1;
			}
		}
	}
	return 0;
}


// ������� ��� ������
int countWords(string str) {
	int count = 0;
	for (int i{}; i < str.length(); i++) {
		if (i == 0 || str[i] == ' ')
			count++;
	}
	return count;
}

string swapCentralWords(string str, int words) {
	string left, right;
	int currentWord = 0,
		leftStartIndex = 0, leftEndIndex = 0, rightStartIndex = 0, rightEndIndex = 0;
	for (int i{}; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (++currentWord == words / 2 - 1) { // ���� ������� ����� - ����� �� ������
				int j = i + 1, // ���������� ������
					k = 0;

				leftStartIndex = j;

				while (str[j++] != ' ') { // ���������� ����� ������ �� ������ �����
					k++;
				}
				left = str.substr(leftStartIndex, k);

				rightStartIndex = leftEndIndex = j;
				k = 0;


				while (str[j++] != ' ') { // ���������� ����� ������� �� ������ �����
					k++;
				}
				right = str.substr(rightStartIndex, k);

				rightEndIndex = j;
				break;
			}
		}
	}
	string swapped = right + ' ' + left + ' '; // ����� � ������ �� ������ �����, ���������� �������

	str.erase(rightStartIndex, rightEndIndex-rightStartIndex); // ������� �������� ������ �� ������� �����
	str.erase(leftStartIndex, leftEndIndex - leftStartIndex); // ������� �������� ������ �� ������ �����

	str.insert(leftStartIndex, swapped); // ��������� ����� � ���������� �������

	return str;
}