#include <iostream>

using namespace std;

void var12_ex1();
void var12_ex2();
void var14_ex1();
void var14_ex2();
void var16_ex1();
void var16_ex2();

int main() {
	system("chcp 1251");

	int variant;
	int exercise;
	cout << "�������� �������: "; cin >> variant;
	cout << "�������� �������: "; cin >> exercise;

	switch (variant) {
	case 12: {
		if (exercise == 1)
			var12_ex1();
		else if (exercise == 2)
			var12_ex2();
		else
			cerr << "������!" << endl;
		break;
	}
	case 14: {
		if (exercise == 1)
			var14_ex1();
		else if (exercise == 2)
			var14_ex2();
		else
			cerr << "������!" << endl;
		break;
	}
	case 16: {
		if (exercise == 1)
			var16_ex1();
		else if (exercise == 2)
			var16_ex2();
		else
			cerr << "������!" << endl;
		break;
	}
	default:
		cerr << "������!" << endl;
		break;
	}
	return 0;
}

// ������ - ����� ������ A �� n ���������. ����������, ������� ��� ����������� � ��� ������������ �����.

void var12_ex1() {

	int* arrayPtr = nullptr;
	int i, n;
	printf("������� ������ ������� (������ 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (int*)malloc(n * sizeof(int))))
	{
		puts("������! ������������ ������!");
	}
	for (i = 0; i < n; i++)
	{
		printf("������� ������� [%d]\n", i + 1);
		scanf_s("%d", arrayPtr + i);
	}


	printf("\n��������� ������: \n");
	for (i = 0; i < n; i++)
		printf("%d ", *(arrayPtr + i));
	printf("\n");

	int max = *arrayPtr;
	int maxIndex = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (*(arrayPtr + i) > max) {
			max = *(arrayPtr + i);
			maxIndex = i;
			count = 1;
		}
		if ((*(arrayPtr + i) == max) && (maxIndex != i))
			count++;
	}

	free(arrayPtr);
	printf("\n���������� ������������ ���������: %d", count);
}

// ������ - ���������, ���� �� � ������� ���� �� ���� ������, ���������� ������������� �������, � ����� �� �����. 
// ����� ��������� ���������� ������ �������� �� ���������������.
void var12_ex2() {
	system("chcp 1251");


	int n, m;
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

	int positiveRow = 0;
	bool isPositive = false;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (cells[i][j] > 0) {
				positiveRow = i;
				isPositive = true;
			}
		}
		if (isPositive) {
			break;
		}
	}

	cout << "������ � ���� �� ����� ������������� ���������: " << positiveRow + 1 << endl;
	
	if (positiveRow > 0) {
		for (int j{}; j < m; j++) {
			cells[positiveRow - 1][j] *= -1;
		}
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}
}

// ������ - � �������, ��������� �� ������������ ���������, ��������� ���������� ��������� �������, ������� ���������� ��������� ����� �, � ������������ ��������� 
// �������, ������������� ����� ������������� �� ������ ��������.
void var14_ex1() {

	float* arrayPtr;
	int i, n;
	printf("������� ������ ������� (������ 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (float*)malloc(n * sizeof(float))))
	{
		puts("������! ������������ ������!");
		return;
	}
	for (i = 0; i < n; i++)
	{
		printf("������� ������� [%d]\n", i + 1);
		scanf_s("%f", arrayPtr + i);
	}


	printf("\n��������� ������: \n");
	for (i = 0; i < n; i++)
		printf("%f ", *(arrayPtr + i));
	printf("\n");


	float C;
	cout << "������� C: "; cin >> C;
	
	float maxAbsoluteElement = *arrayPtr;

	int count = 0, maxAbsoluteIndex = 0;
	for (int i{}; i < n; i++) {
		if (*(arrayPtr + i) > C)
			count++;
		if (abs(*(arrayPtr + i)) > maxAbsoluteElement) {
			maxAbsoluteElement = abs(*(arrayPtr + i));
			maxAbsoluteIndex = i+1;
		}
	}

	float prod = 1;
	for (int i = maxAbsoluteIndex; i < n; i++) {
		prod *= *(arrayPtr + i);
	}

	printf("���������� ��������� ������� ���, ����� C: %i\n", count);
	printf("������������ ��������� ����� �������� �� ������ ����� %f: %f\n", maxAbsoluteElement, prod);

	free(arrayPtr);

}

// ������ - ���������, ���� �� � ������� ���� �� ���� ������, ���������� �������, ������ ����, � ����� �� �����. 
// ��������� ��� �������� ������� �� �������� ������� �������� ��������� ������.
void var14_ex2() {

	int n, m;
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

	bool isNull = false;
	int nullIndex = 0;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (cells[i][j] == 0)
			{
				isNull = true;
				nullIndex = i;
			}
		}
		if (isNull)
			break;
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			if (cells[i][j] != cells[nullIndex][0]) {
				cells[i][j] -= cells[nullIndex][0];
			}
		}
	}

	// �����
	cout << "���� �� ���� ������, ������� ����� ���� �� ���� ����: " << nullIndex + 1 << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}
}

// ������ - � ���������� �������, ��������� �� ������������ ���������, ��������� ����� ������������ �� ������ �������� ������� � ����� ������� ��������� �������, 
// ������������� ����� ������� �������������� ��������.
void var16_ex1() {
	float* arrayPtr;
	int i, n;
	printf("������� ������ ������� (������ 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (float*)malloc(n * sizeof(float))))
	{
		puts("������! ������������ ������!");
		return;
	}
	for (i = 0; i < n; i++)
	{
		printf("������� ������� [%d]\n", i + 1);
		scanf_s("%f", arrayPtr + i);
	}


	printf("\n��������� ������: \n");
	for (i = 0; i < n; i++)
		printf("%f ", *(arrayPtr + i));
	printf("\n");

	float minAbsoluteElement = *arrayPtr;
	int firstNegativeIndex = 0;
	bool haveNegative = false;

	for (int i{}; i < n; i++) {
		if (abs(*(arrayPtr + i)) < minAbsoluteElement) {
			minAbsoluteElement = *(arrayPtr + i);
		}
		if (!haveNegative) {
			if (*(arrayPtr + i) < 0) {
				firstNegativeIndex = i;
			}
		}
	}

	float summ = 0;

	for (int i = firstNegativeIndex+1; i < n; i ++) {
		summ += *(arrayPtr + i);
	}

	printf("����� ��������� ����� ������� �������������� %f: %f", *(arrayPtr + firstNegativeIndex), summ);
	printf("����������� �� ������ �������: %f", minAbsoluteElement);

	free(arrayPtr);
}

// ������ - ���� ������������� ���������� �������. ���������� ������������ ��������� � ��� �������, ������� �� �����-��� ������������� ��������� � 
// �������� ����� ���� ��������� ����������, ������������ ������� ��������� �������.
void var16_ex2() {

	int n;
	cout << "������� ������� �������: "; cin >> n;


	// ���������� �����
	int** cells{ new int* [n] {} };
	// ���������� �������� ��� ������ ������
	for (int i{}; i < n; i++) {
		cells[i] = new int[n] {};
	}


	// ����
	cout << "������� �������� �������: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cin >> cells[i][j];
		}
		cout << endl;
	}
	cout << "�������� �������: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}

	// ������ ��� ������������� �����
	for (int i{}; i < n; i++) {
		bool notHaveNegative = true;
		int prod = 1;
		for (int j{}; j < n; j++) {
			if (cells[i][j] < 0) {
				notHaveNegative = false;
			}
		}
		prod = 1;
		if (notHaveNegative) {
			for (int j{}; j < n; j++) {
				prod *= cells[i][j];
			}
			cout << "������ " << i + 1 << " �� ����� ������������� ���������, ������������ �� ���������: " << prod << endl;
		}
	}

	// ������ ��� ����������
	int  maxDiagSum = 0;
	for (int i{}; i < n; i++) {
		int sumOfDiag = 0;
		for (int d = -(n - 2); d < n - 2; d++) {
			sumOfDiag += cells[i][i + d];
		}
		maxDiagSum = sumOfDiag > maxDiagSum ? sumOfDiag : maxDiagSum;
	}
	
	cout << "�������� ����� ���� ���������, ������������ ������� ���������: " << maxDiagSum << endl;
} 