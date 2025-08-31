#include <iostream>

using namespace std;

// ����� � ������� ������ ������, ��� �������� ������� ������������. ��������� ��� �������� ������� �� ���-����� ������� �������� ��������� ������.

int main() {
	system("chcp 1251");


	int n,m;
	cout << "������� ���������� �����: "; cin >> n;
	cout << "������� ���������� ��������: "; cin >> m;
	

	// ���������� �����
	int** cells{ new int* [n] {} };
	// ���������� �������� ��� ������ ������
	for (int i{}; i < n; i++) {
		cells[i] = new int[m] {};
	}


	// ����
	cout << "������� �������� �������: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cin >> cells[i][j];
		}
		cout << endl;
	}
	cout << "�������� �������: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}


	// ���������� ����
	int negativeIndex = -1;
	for (int i{}; i < n; i++) {
		bool havePositiveValue;
		for (int j{}; j < m; j++) {
			havePositiveValue = false;
			if (cells[i][j] > 0) {
				havePositiveValue = true;
				break;
			}
		}
		if (!havePositiveValue) {
			negativeIndex = i;
			break;
		}
	}

	if (negativeIndex+1) {
		cout << "������ ������, � ������� ��� �������� �������������: " << negativeIndex + 1 << endl;

		// ��������� ������� �� ������ ������� ��������� ������
		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				if (cells[i][j] != cells[negativeIndex][0]) {
					cells[i][j] += cells[negativeIndex][0];
				}
			}
		}

		// �����
		cout << "���������: " << endl;
		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				cout << cells[i][j] << '\t';
			}
			cout << endl;
		}
	}
	else {

		cerr << "� ���� ������� ��� ����� ������, � ������� ��� �������� �������������.";
	
	}


	// ������� ������
	for (int i{}; i < n; i++) {
		delete[] cells[i];
	}
	delete[] cells;

	return 0;
}