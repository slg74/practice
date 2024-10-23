def longest_consecutive_sequence(nums):
    # Convert array to set for O(1) lookups
    num_set = set(nums)
    longest = 0
    
    for num in nums:
        # Check if this is the start of a sequence
        if num - 1 not in num_set:
            current_num = num
            current_streak = 1
            
            # Count consecutive numbers
            while current_num + 1 in num_set:
                current_num += 1
                current_streak += 1
            
            longest = max(longest, current_streak)
    
    return longest


# Test cases
nums1 = [100, 4, 200, 1, 3, 2]  # Returns 4 (sequence: 1,2,3,4)
nums2 = [0, 3, 7, 2, 5, 8, 4, 6, 1]  # Returns 9 (sequence: 0,1,2,3,4,5,6,7,8)
nums3 = [1, 2, 0, 1]  # Returns 3 (sequence: 0,1,2)

