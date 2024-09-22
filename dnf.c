#include <stdio.h>


void sortColors(int* nums, int numSize) {
    int count[3] = {0};

    for (int i=0; i < numSize; i++) {
        count[nums[i]]++;
    }

    int i = 0;
    for (int color = 0; color < 3; color++) {
        for (int j = 0; j < count[color]; j++) {
            nums[i++] = color;
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
