#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int findClosestNumber(int* nums, int numSize) {
    int closest = nums[0];
    for (int i = 1; i<numSize; i++) {
        if (abs(nums[i]) < abs(closest)) {
            closest = nums[i]; 
        } else if (abs(nums[i]) == abs(closest) && nums[i] > closest) {
            closest = nums[i]; 
        }
    }
    return closest;
}

int main() {
    int ar[] = { -4, -2, 3, 4, 8 };
    int ret = findClosestNumber(ar, sizeof(ar) / sizeof(ar[0])); 
    int ret2 = find_closest(ar, sizeof(ar) / sizeof(ar[0])); 
    printf("%d\n", ret);
    printf("%d\n", ret2);
    return 0;
}