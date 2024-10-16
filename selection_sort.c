#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SWAP(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0)

void generic_selection_sort(void *arr, size_t n, size_t size, int (*compare)(const void *, const void *)) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++) {
            if (compare((char *)arr + j * size, (char *)arr + min_idx * size) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char temp[size];
            memcpy(temp, (char *)arr + i * size, size);
            memcpy((char *)arr + i * size, (char *)arr + min_idx * size, size);
            memcpy((char *)arr + min_idx * size, temp, size);
        }
    }
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void print_array(const void *arr, size_t n, size_t size, char type) {
    for (size_t i = 0; i < n; i++) {
        if (type == 'i') {
            printf("%d ", *((int*)arr + i));
        } else if (type == 'c') {
            printf("%c ", *((char*)arr + i));
        }
    }
    printf("\n");
}

int main(void) {
    int int_arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t int_n = sizeof(int_arr) / sizeof(int_arr[0]);

    char char_arr[] = { 'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E' };
    size_t char_n = sizeof(char_arr) / sizeof(char_arr[0]);

    // print, sort, then print int array
    printf("Original int array: ");
    print_array(int_arr, int_n, sizeof(int), 'i'); 
    generic_selection_sort(int_arr, int_n, sizeof(int), compare_int); 
    print_array(int_arr, int_n, sizeof(int), 'i'); 

    // print, sort, then print char array
    printf("Original char array: ");
    print_array(char_arr, char_n, sizeof(char), 'c'); 
    generic_selection_sort(char_arr, char_n, sizeof(char), compare_char); 
    print_array(char_arr, char_n, sizeof(char), 'c'); 

    return 0;
}
