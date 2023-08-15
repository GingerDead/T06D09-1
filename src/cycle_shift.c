#include <stdio.h>

#define NMAX 10

int input(int *n, int* data, int *c);
void output(int n, int* data);
void cycle_shift(int n, int* data, int c);

int main() {
    int n, data[NMAX-1], c;
    if (input(&n, data, &c)) {
        cycle_shift(n, data, c);
        output(n, data);
    } else printf("n/a");
}

int input(int *n, int* data, int *c) {
    int flag = 1;
    if (scanf("%d", n) && (0 < *n) && (*n <= NMAX) && (getc(stdin) == '\n')) {
        for (int i = 0; i < *n; i++) 
            if (!scanf("%d", &data[i])) {
                flag = 0;
                break;
            }
        if (getc(stdin) == '\n') {
            if ((!scanf("%d", c)) && (getc(stdin) != '\n')) flag = 0;
        } else flag = 0;       
    } else flag = 0;

    return flag;
}

void cycle_shift(int n, int* data, int c) {
    int data_out[NMAX-1];
    for (int i = 0; i < n; i++) {
        int shift = (i + c) % n;
        if (shift < 0) 
            shift = shift + n;
        data_out[i] = data[shift];
    }
    for (int i = 0; i < n; i++)
        data[i] = data_out[i];
}

void output (int n, int* data) {
	for (int i = 0; i < n; i++) {
		(i != n - 1) ? printf("%d ", data[i]) : printf("%d", data[i]);
	}
}