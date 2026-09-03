#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int* Shift(int* count) {
	int* array = calloc(100, sizeof(int));
	printf("Введите длину массива: ");
	
	scanf_s("%d", count);

	printf("Введите сдвиг: ");
	int k;
	scanf_s("%d", &k);

	printf("Введите массив: ");
	for (int i = 0; i < *count; i++)
	{
		scanf_s("%d", &array[i]);
	}

	int* temp = malloc(*count * sizeof(int));

	// Сдвигаем влево на k
	for (int i = 0; i < *count; i++) {

		int new_pos = (i + k) % *count;
		temp[i] = array[new_pos];
	}

	return temp;
}


int main() {
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("chcp 1251");*/
	
	system("chcp 65001");

	int count = 0; 
	int* array = Shift(&count);
	printf("Результат: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", array[i]);
		
	}
}

// Сдвиг массива в лево на k
