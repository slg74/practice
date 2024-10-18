#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100000

typedef struct {
    int num;
    int freq;
} NumFreq;

int compare(const void* a, const void* b) {
    return ((NumFreq*)b)->freq - ((NumFreq*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int count[MAX_NUM * 2 + 1] = {0};
    NumFreq freq[numsSize];
    int unique = 0;

    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + MAX_NUM]++;
    }

    for (int i = 0; i < MAX_NUM * 2 + 1; i++) {
        if (count[i] > 0) {
            freq[unique].num = i - MAX_NUM;
            freq[unique].freq = count[i];
            unique++;
        }
    }

    qsort(freq, unique, sizeof(NumFreq), compare);

    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;

    for (int i = 0; i < k; i++) {
        result[i] = freq[i].num;
    }

    return result;
}

int main() {
    int nums[] = {1,1,1,2,2,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int returnSize;

    int* result = topKFrequent(nums, numsSize, k, &returnSize);

    printf("The %d most frequent elements are: ", k);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
