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

def searchInsert(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return left

# Example usage
nums = [1, 3, 5, 6]
target = 5
result = searchInsert(nums, target)
print(f"Target {target} found or should be inserted at index: {result}")

# Additional test cases
print(searchInsert(nums, 2))  # Should return 1
print(searchInsert(nums, 7))  # Should return 4


int main() {
    int ar[] = { -4, -2, 3, 4, 8 };
    int ret = findClosestNumber(ar, sizeof(ar) / sizeof(ar[0])); 
    int ret2 = find_closest(ar, sizeof(ar) / sizeof(ar[0])); 
    printf("%d\n", ret);
    printf("%d\n", ret2);
    return 0;
}