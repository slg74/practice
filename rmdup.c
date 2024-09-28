#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_ELEMENTS 1000

int removeDuplicates(int* nums, int numsSize) {
    bool seen[MAX_ELEMENTS] = {false}; // initialize the hashmap to all false values
    int unique_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (!seen[nums[i]]) {
            seen[nums[i]] = true;
            nums[unique_count++] = nums[i];
        }
    }
    return unique_count;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newSize = removeDuplicates(nums, numsSize);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
