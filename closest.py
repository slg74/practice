
def findClosestNumber(nums, n):
    num = nums[0]
    for i in nums:
        if abs(i) < abs(num):
            num = i
    if abs(num) in nums:
        return abs(num)
    return num

nums = [-4, -2, 3, 2, 7]

print(findClosestNumber(nums, 0))