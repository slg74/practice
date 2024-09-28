#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) {
        return numsSize;
    }

    int uniq = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[uniq]) {
            uniq++;
            nums[uniq] = nums[i];
        }
    }
    return uniq + 1;
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