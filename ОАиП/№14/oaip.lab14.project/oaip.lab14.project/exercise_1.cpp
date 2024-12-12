#include <iostream>

using namespace std;

const int n = 2;
const int m = 2;

// ������� - ���� ������� �(n, m). ��������� ������������ ������ ������������� ��������� �������. 
int main() {

	system("chcp 1251");

	int B[n][m];
	// ���� �����
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "������� ������� B[" << i << "][" << j << "] �������: "; cin >> B[i][j];
		}

	// ���� ����������
	int cellsProduct = 1;
	for (int i = 0, cellNumber = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ( cellNumber++ && (B[i][j] > 0) ) {
				cellsProduct *= B[i][j];
			}
		}

	if (cellsProduct) {
		cout << "������������ ������ ������������� ��������� ������� B(n, m): " << cellsProduct << endl;
	}
	else {
		cerr << "��� ����������, ���������� ��� �������!";
	}
	return 0;
}