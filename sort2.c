#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int ar[5] = { 90, 1, -123, 77, -273 };
    int n = 5;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (ar[j] > ar[j+1]) {
                swap(&ar[j], &ar[j+1]);
            }
        }
    }
    printf("Sorted: ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", ar[i]);
    }
    printf("\n");
    return 0;
}