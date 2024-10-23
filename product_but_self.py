def productExceptSelf(nums):
    n = len(nums)
    output = [1] * n
    print(f'DEBUG: {output}')
    
    # Calculate left products
    left_product = 1
    for i in range(n):
        output[i] = left_product
        left_product *= nums[i]
    
    # Calculate right products and combine with left products
    right_product = 1
    for i in range(n - 1, -1, -1):
        output[i] *= right_product
        right_product *= nums[i]
    
    return output

# Example usage
nums = [1, 2, 3, 4]
result = productExceptSelf(nums)
print(result)  # Output: [24, 12, 8, 6]
