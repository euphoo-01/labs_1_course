#include <iostream>
#include <string>
using namespace std;

// Вариант 10

void deleteArray(int** arr, int n);
int findIndexHasK(int** arr, int n, int m, int k);

int countWords(string str);
void swapCentralWords(string* str, int words);
int main() {
	system("chcp 1251");

	int choice;
	cout << "Какое задание выполнить? "; cin >> choice;
	
	switch (choice) {
	case 1: {
		int n, m;

		cout << "Введите количество строк массива: "; cin >> n;
		cout << "Введите количество столбцов массива: "; cin >> m;

		// Инициализация массива
		int** matrix = new int* [n];
		for (int i{}; i < n; ++i) {
			matrix[i] = new int[m];
		}

		// Ввод массива
		cout << "Введите элементы матрицы: " << endl;
		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				cin >> matrix[i][j];
			}
			cout << endl;
		}

		int k;
		cout << "Введите число k: "; cin >> k;

		int kIndex = findIndexHasK(matrix, n, m, k);

		// Вывод
		if (kIndex)
			cout << "Столбец матрицы, в котором есть k: " << kIndex << endl;
		else
			cerr << "Числа k нет в матрице." << endl;

		deleteArray(matrix, n);

		break;
	}
	case 2: {
		string s{};

		cout << "Введите строку: "; 
		cin.ignore(); // Очищаем символ \n
		getline(cin, s);

		int wordCount = countWords(s);
		if (wordCount % 2 == 0) { // Если количество слов четное
			swapCentralWords(&s, wordCount);
			cout << "Результат: " << endl << s << endl;
		}
		else {
			cerr << "Количество слов в строке нечетное!" << endl;
		}

		break;
	}
	default: {
		cerr << "Такого варианта не существует!";
		break;
	}
	}
}

// Функции для массива
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


// Функции для строки
int countWords(string str) {
	int count = 0;
	for (int i{}; i < str.length(); i++) {
		if (i == 0 || str[i] == ' ')
			count++;
	}
	return count;
}

void swapCentralWords(string* str, int words) {
	string left, right;
	int currentWord = 0,
		leftStartIndex = 0, leftEndIndex = 0, rightStartIndex = 0, rightEndIndex = 0;
	for (int i{}; i < (*str).length(); i++) {
		if ((*str)[i] == ' ') {
			if (++currentWord == words / 2 - 1) { // Если следующее слово - левое от центра
				int j = i + 1, // Пропускаем пробел
					k = 0;

				leftStartIndex = j;

				while ((*str)[j++] != ' ') { // Определяем длину левого от центра слова
					k++;
				}
				left = (*str).substr(leftStartIndex, k);

				rightStartIndex = leftEndIndex = j;
				k = 0;


				while ((*str)[j++] != ' ') { // Определяем длину правого от центра слова
					k++;
				}
				right = (*str).substr(rightStartIndex, k);

				rightEndIndex = j;
				break;
			}
		}
	}
	string swapped = right + ' ' + left + ' '; // Левое и правое от центра слова, поменянные местами

	(*str).erase(rightStartIndex, rightEndIndex-rightStartIndex); // Очистка исходной строки от правого слова
	(*str).erase(leftStartIndex, leftEndIndex - leftStartIndex); // Очистка исходной строки от левого слова

	(*str).insert(leftStartIndex, swapped); // Вставляем слова в измененном порядке

	
}