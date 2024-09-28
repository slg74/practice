#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxNonAdjacentSum(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int include = nums[0];
    int exclude = 0;

    for (int i = 1; i < numsSize; i++) {
        int temp = include;
        include = exclude + nums[i];
        exclude = max(temp, exclude);
    }

    return max(include, exclude);
}

int main() {
    int nums[] = {5, 1, 1, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxNonAdjacentSum(nums, numsSize);
    printf("Maximum sum of non-adjacent elements: %d\n", result);

    return 0;
}
