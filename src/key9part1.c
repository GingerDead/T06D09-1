/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() 
{
    int length, buffer[NMAX], numbers[NMAX];
	if (input(buffer, &length)) {
		int number = sum_numbers(buffer, length);
		if (number != 0) {
			int finder = find_numbers(buffer, length, number, numbers);
			printf("%d\n", number);
			output(numbers, finder);
		} else printf("n/a");
	} else printf("n/a");

	return 0; 
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		if ((buffer[i] % 2) == 0)
			sum += buffer[i];
	}
	
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers)
{
	int finder = 0;
	for (int i = 0; i < length; i++) {
		if (buffer[i] == 0) {
			continue;
		} else {
			if (number % buffer[i] == 0) {
			numbers[finder] = buffer[i];
			finder++;
			}
		}
	}

	return finder;
}

int input (int *buffer, int *length) {
	int flag = 1;
	if ((scanf("%d", length) == 1) && (*length > 0) && (*length <= NMAX) && (getc(stdin) == '\n')) {
		for (int i = 0; i < *length; i++) {
			if (scanf("%d", &buffer[i]) != 1) {
				flag = 0;
				break;
			}
		}
		if (getc(stdin) != '\n') flag = 0;
	} else flag = 0;

	return flag;
}

void output (int *buffer, int length) {
	for (int i = 0; i < length; i++) {
		(i != length - 1) ? printf("%d ", buffer[i]) : printf("%d", buffer[i]);
	}
}