def max_non_adjacent_sum(nums):
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    include = nums[0]
    exclude = 0

    for num in nums[1:]:
        temp = include
        include = exclude + num
        exclude = max(temp, exclude)

    return max(include, exclude)

# Example usage
nums = [5, 1, 1, 5]
result = max_non_adjacent_sum(nums)
print(f"Maximum sum of non-adjacent elements: {result}")
