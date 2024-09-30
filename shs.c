#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {

    int ar[5] = { 22, -1, 137, 138, -50 };
    int n = 5;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (ar[j] > ar[j+1]) {
                swap(&ar[j], &ar[j+1]);
            }
        }
    }

    for (int i=0; i < n; i++) {
        printf(" %d ", ar[i]);
    }
    printf("\n");

    return 0;
}