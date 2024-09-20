#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int left = 0;
    int right = arrSize - k;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid + k < arrSize && x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    *returnSize = k;
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[left + i];
    }
    
    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int x = 3;
    int returnSize;
    
    int* result = findClosestElements(arr, arrSize, k, x, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    free(result);
    return 0;
}
