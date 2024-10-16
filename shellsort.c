#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void shellsort(int *arr, size_t n) {
    size_t gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }
    
    while (gap > 0) {
        for (size_t i = gap; i < n; i++) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 3;
    }
}

void print_array(const int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    shellsort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
