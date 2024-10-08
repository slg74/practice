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
