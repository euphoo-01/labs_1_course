#include <iostream>
#include <cmath>

using namespace std;

// Задача - В одномерном массиве, состоящем из n вещественных элементов, вычислить сумму положительных элементов массива и произведение элементов массива, 
// расположенных между максимальным по модулю и минимальным по модулю элементами.

int main() {
	system("chcp 1251");


	float* arrayPtr;
	int i, n;
	printf("Введите размер массива (меньше 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (float*)malloc(n * sizeof(float))))
	{	                                      
		puts("Ошибка! Недостаточно памяти!");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		printf("Введите элемент [%d]\n", i + 1);
		scanf_s("%f", arrayPtr + i);
	}


	printf("\nВведенный массив: \n");
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
	if (minCellIndex > maxCellIndex) { // Если минимальный индекс левее, чем максимальный
		for (i = maxCellIndex; i <= minCellIndex; i++) {
			if (*(arrayPtr + i) > 0) {
				sum += *(arrayPtr + i);
			}
			prod *= *(arrayPtr + i);
		}
	}
	else if (minCellIndex < maxCellIndex) { // Если максимальный индекс левее, чем минимальный
		for (i = minCellIndex; i <= maxCellIndex; i++) {
			if (*(arrayPtr)+i) {
				sum += *(arrayPtr + i);
			}
			prod *= *(arrayPtr + i);
		}
	}

	free(arrayPtr);

	printf("Максимальный элемент массива по модулю находится под индексом %d и равен %f.\n", maxCellIndex, maxCellValue);
	printf("Минимальный элемент массива по модулю находится под индексом %d и равен %f.\n", minCellIndex, minCellValue);

	printf("Сумма положительных элементов, находящихся между минимальным и максимальным по модулю значениями массива (включительно): %f\n", sum);
	printf("Произведение элементов, находящихся между минимальным и максимальным по модулю значениями массива (включительно): %f\n", prod);

	return 0;
}