def findClosestElements(arr, k, x):
    left = 0
    right = len(arr) - k
    
    while left < right:
        mid = left + (right - left) // 2
        if x - arr[mid] > arr[mid + k] - x:
            left = mid + 1
        else:
            right = mid
    
    return arr[left:left + k]

# Example usage
arr = [1, 2, 3, 4, 5]
k = 4
x = 3

result = findClosestElements(arr, k, x)
print(f"Output: {result}")

# Example 2
arr2 = [1, 2, 3, 4, 5]
k2 = 4
x2 = -1

result2 = findClosestElements(arr2, k2, x2)
print(f"Output: {result2}")
