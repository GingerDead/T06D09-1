#include <stdio.h>
#define N 10

int input(int* data);
void output(int* data);
void bubbleSort(int* data);
void swap(int* a, int* b);

int main() {
    int data[N];
    if (input(data)) {
        bubbleSort(data);
        output(data);
    } else printf("n/a");

    return 0;
}

int input(int* data) {
    int flag = 1;
    for (int i = 0; i < N; i++)
        if (scanf("%d", &data[i]) != 1) {
            flag = 0;
            break;
        }
    if (getc(stdin) != '\n') flag = 0;

    return flag;
}

void output(int* data) {
    for (int i = 0; i < N; i++)
        printf("%d ", data[i]);
}

void bubbleSort(int* data) {
    for (int i = 0; i < N - 1; i++) 
        for (int j = 0; j < N - i - 1; j++) {
            if (data[j] > data[j+1])
                swap(&data[j], &data[j+1]);
        }
    
}

void swap(int* a, int* b) {
    int var = *a;
    *a = *b;
    *b = var;
}
