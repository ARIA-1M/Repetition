#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// Сдвиг массива в лево на k
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
	getchar();
	return temp;
}

void reverse_substring(char* start, char* end) {
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

// Обратный порядок слов в предложении
void  ReverseOrder() {
	char* str = calloc(100, sizeof(char));
	
	printf("\nВведите предложение: ");
	fgets(str, 256, stdin);

	int len = strlen(str);
	if (str[len - 1] == '\n') {
		str[len - 1] = '\0';
		len--;
	}

	//  Разворачиваем всю строку
	reverse_substring(str, str + len - 1);

	char* word_start = str;
	char* current = str;
	while (*current != '\0') {
		if (*current == ' ') {
			// Нашли конец слова
			reverse_substring(word_start, current - 1);
			word_start = current + 1;
		}
		current++;
	}
	// Разворачиваем последнее слово
	reverse_substring(word_start, current - 1);

	printf("\nРезультат: %s", str);

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

	ReverseOrder();
}


