#include <iostream>
using namespace std;

// ������ - ���������, ���� �� � ������� ���� �� ���� ������, ���������� �������, ������ ����, � ����� �� �����. 
// ��������� ��� �������� ������� �� �������� ������� �������� ��������� ������.

const int m = 3;
const int n = 3;

int main() {
	system("chcp 1251");

	int A[m][n];
	
	// ���� �����
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			 cin >> *(*(A + i) + j);
		}
		cout << "\n";
	}

	bool nullElementExists = false;
	int nullElementRow;

	for (int i = 0; i < m; i++) { // ���������� ����. �������� ������� �� ���������� �������
		for (int j = 0; j < n; j++) {
			if ( *(*(A + i) + j) == 0 ) {
				nullElementExists = true;
				nullElementRow = i;
			}
			if (nullElementExists) {
				break;
			}
		}
	}

	if (nullElementExists) { // ��������� ��� �������� ������� �� �������� ������� �������� ��������� ������.
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (*(*(A + i) + j) != *(*(A + nullElementRow) + 0)) {
					*(*(A + i) + j) -= *(*(A + nullElementRow) + 0);
				}
			}
		}
		cout << "� ������� ���� ���� �� ���� ������, ���������� �������, ������ ����. �� ����� - " << nullElementRow+1 << endl;
	}
	else {
		cerr << "� ������� ����������� ��������, ���������� ��� �������. ������� ������� ��� ���������." << endl;
	}

	for (int i = 0; i < m; i++) { // ����� �������
		for (int j = 0; j < n; j++) {
			cout << *(*(A + i) + j) << '\t';
		}
		cout << endl;
	}

	return 0;
}