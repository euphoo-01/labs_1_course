#include <iostream>
#include <cmath>

using namespace std;

// ������ - � ���������� �������, ��������� �� n ������������ ���������, ��������� ����� ������������� ��������� ������� � ������������ ��������� �������, 
// ������������� ����� ������������ �� ������ � ����������� �� ������ ����������.

int main() {
	system("chcp 1251");


	float* arrayPtr;
	int i, n;
	printf("������� ������ ������� (������ 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (float*)malloc(n * sizeof(float))))
	{	                                      
		puts("������! ������������ ������!");
		return 1;
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


	float maxCellValue = abs(*(arrayPtr)),
		minCellValue = abs(*(arrayPtr));
	int maxCellIndex = 0,
		minCellIndex = 0;

	for (i = 0; i < n; i++) {
		if (abs(*(arrayPtr + i)) > maxCellValue) {
			maxCellValue = abs(*(arrayPtr + i));
			maxCellIndex = i;
		}
		if (abs(*(arrayPtr + i)) < minCellValue) {
			minCellValue = abs(*(arrayPtr + i));
			minCellIndex = i;
		}
	}

	float sum = 0, prod = 1;
	if (minCellIndex > maxCellIndex) { // ���� ����������� ������ �����, ��� ������������
		for (i = maxCellIndex; i <= minCellIndex; i++) {
			if (*(arrayPtr + i) > 0) {
				sum += *(arrayPtr + i);
			}
			prod *= *(arrayPtr + i);
		}
	}
	else if (minCellIndex < maxCellIndex) { // ���� ������������ ������ �����, ��� �����������
		for (i = minCellIndex; i <= maxCellIndex; i++) {
			if (*(arrayPtr)+i) {
				sum += *(arrayPtr + i);
			}
			prod *= *(arrayPtr + i);
		}
	}

	free(arrayPtr);

	printf("������������ ������� ������� �� ������ ��������� ��� �������� %d � ����� %f.\n", maxCellIndex, maxCellValue);
	printf("����������� ������� ������� �� ������ ��������� ��� �������� %d � ����� %f.\n", minCellIndex, minCellValue);

	printf("����� ������������� ���������, ����������� ����� ����������� � ������������ �� ������ ���������� ������� (������������): %f\n", sum);
	printf("������������ ���������, ����������� ����� ����������� � ������������ �� ������ ���������� ������� (������������): %f\n", prod);

	return 0;
}