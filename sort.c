#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int ar[6] = { 7, 2, -123, 78, 909, 0 };
    int n = 6;

    for (int i=0; i < n-1; i++) {
        for (int j=0; j < n-1; j++) {
            if (ar[j] > ar[j+1]) {
                swap(&ar[j], &ar[j+1]); 
            }
        }
    }

    // print the sorted array
    for (int i=0; i < n; i++) {
        printf(" %d ", ar[i]);
    }
    printf("\n");

    return 0;
}