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
	cout << "Выберите вариант: "; cin >> variant;
	cout << "Выберите задание: "; cin >> exercise;

	switch (variant) {
	case 12: {
		if (exercise == 1)
			var12_ex1();
		else if (exercise == 2)
			var12_ex2();
		else
			cerr << "Ошибка!" << endl;
		break;
	}
	case 14: {
		if (exercise == 1)
			var14_ex1();
		else if (exercise == 2)
			var14_ex2();
		else
			cerr << "Ошибка!" << endl;
		break;
	}
	case 16: {
		if (exercise == 1)
			var16_ex1();
		else if (exercise == 2)
			var16_ex2();
		else
			cerr << "Ошибка!" << endl;
		break;
	}
	default:
		cerr << "Ошибка!" << endl;
		break;
	}
	return 0;
}

// Задача - Задан массив A из n элементов. Подсчитать, сколько раз встречается в нем максимальное число.

void var12_ex1() {

	int* arrayPtr = nullptr;
	int i, n;
	printf("Введите размер массива (меньше 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (int*)malloc(n * sizeof(int))))
	{
		puts("Ошибка! Недостаточно памяти!");
	}
	for (i = 0; i < n; i++)
	{
		printf("Введите элемент [%d]\n", i + 1);
		scanf_s("%d", arrayPtr + i);
	}


	printf("\nВведенный массив: \n");
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
	printf("\nКоличество маскимальных элементов: %d", count);
}

// Задача - Проверить, есть ли в матрице хотя бы одна строка, содержащая положительный элемент, и найти ее номер. 
// Знаки элементов предыдущей строки изменить на противоположные.
void var12_ex2() {
	system("chcp 1251");


	int n, m;
	cout << "Введите количество строк: "; cin >> n;
	cout << "Введите количество столбцов: "; cin >> m;


	// Объявление строк
	int** cells{ new int* [n] {} };
	// Объявление столбцов для каждой строки
	for (int i{}; i < n; i++) {
		cells[i] = new int[m] {};
	}


	// Ввод
	cout << "Введите элементы массива: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cin >> cells[i][j];
		}
		cout << endl;
	}
	cout << "Исходная матрица: " << endl;
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

	cout << "Строка с хотя бы одним положительным элементом: " << positiveRow + 1 << endl;
	
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

// Задача - В массиве, состоящем из вещественных элементов, вычислить количество элементов массива, больших некоторого заданного числа С, и произведение элементов 
// массива, расположенных после максимального по модулю элемента.
void var14_ex1() {

	float* arrayPtr;
	int i, n;
	printf("Введите размер массива (меньше 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (float*)malloc(n * sizeof(float))))
	{
		puts("Ошибка! Недостаточно памяти!");
		return;
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


	float C;
	cout << "Введите C: "; cin >> C;
	
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

	printf("Количество элементов больших чем, число C: %i\n", count);
	printf("Произведение элементов после большего по модулю числа %f: %f\n", maxAbsoluteElement, prod);

	free(arrayPtr);

}

// Задача - Проверить, есть ли в матрице хотя бы одна строка, содержащая элемент, равный нулю, и найти ее номер. 
// Уменьшить все элементы матрицы на значение первого элемента найденной строки.
void var14_ex2() {

	int n, m;
	cout << "Введите количество строк: "; cin >> n;
	cout << "Введите количество столбцов: "; cin >> m;


	// Объявление строк
	int** cells{ new int* [n] {} };
	// Объявление столбцов для каждой строки
	for (int i{}; i < n; i++) {
		cells[i] = new int[m] {};
	}


	// Ввод
	cout << "Введите элементы массива: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cin >> cells[i][j];
		}
		cout << endl;
	}
	cout << "Исходная матрица: " << endl;
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

	// Вывод
	cout << "Хотя бы одна строка, которая имеет хотя бы один нуль: " << nullIndex + 1 << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < m; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}
}

// Задача - В одномерном массиве, состоящем из вещественных элементов, вычислить номер минимального по модулю элемента массива и сумму модулей элементов массива, 
// расположенных после первого отрицательного элемента.
void var16_ex1() {
	float* arrayPtr;
	int i, n;
	printf("Введите размер массива (меньше 30) \n");
	scanf_s("%d", &n);


	if (!(arrayPtr = (float*)malloc(n * sizeof(float))))
	{
		puts("Ошибка! Недостаточно памяти!");
		return;
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

	printf("Сумма элементов после первого отрицательного %f: %f", *(arrayPtr + firstNegativeIndex), summ);
	printf("Минимальный по модулю элемент: %f", minAbsoluteElement);

	free(arrayPtr);
}

// Задача - Дана целочисленная квадратная матрица. Определить произведение элементов в тех строках, которые не содер-жат отрицательных элементов и 
// максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы.
void var16_ex2() {

	int n;
	cout << "Введите порядок матрицы: "; cin >> n;


	// Объявление строк
	int** cells{ new int* [n] {} };
	// Объявление столбцов для каждой строки
	for (int i{}; i < n; i++) {
		cells[i] = new int[n] {};
	}


	// Ввод
	cout << "Введите элементы массива: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cin >> cells[i][j];
		}
		cout << endl;
	}
	cout << "Исходная матрица: " << endl;
	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cout << cells[i][j] << '\t';
		}
		cout << endl;
	}

	// Логика для отрицательных чисел
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
			cout << "Строка " << i + 1 << " не имеет отрицательных элементов, произведение ее элементов: " << prod << endl;
		}
	}

	// Логика для диагоналей
	int  maxDiagSum = 0;
	for (int i{}; i < n; i++) {
		int sumOfDiag = 0;
		for (int d = -(n - 2); d < n - 2; d++) {
			sumOfDiag += cells[i][i + d];
		}
		maxDiagSum = sumOfDiag > maxDiagSum ? sumOfDiag : maxDiagSum;
	}
	
	cout << "Максимум среди сумм элементов, параллельных главной диагонали: " << maxDiagSum << endl;
} 