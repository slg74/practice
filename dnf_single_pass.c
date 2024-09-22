#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;
    
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                swap(&nums[low++], &nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&nums[mid], &nums[high--]);
                break;
        }
    }
}

void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 0, 1, 1, 0, 2, 1, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    sortColors(arr, size);
    
    printf("Sorted array: ");
    printArray(arr, size);
    
    return 0;
}
