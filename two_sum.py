def two_sum(nums, target):
    num_dict = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_dict:
            return [num_dict[complement], i]
        num_dict[num] = i
    return []

# Driver code
if __name__ == "__main__":
    test_cases = [
        ([2, 7, 11, 15], 9),
        ([3, 2, 4], 6),
        ([3, 3], 6),
        ([1, 2, 3, 4, 5], 9),
        ([1, 1, 1, 1, 1], 2),
        ([-1, -2, -3, -4, -5], -8),
        ([0, 0], 0),
    ]

    for i, (nums, target) in enumerate(test_cases):
        result = two_sum(nums, target)
        print(f"Test case {i + 1}:")
        print(f"Input: nums = {nums}, target = {target}")
        print(f"Output: {result}")
        print()
