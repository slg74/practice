def maxArea(height):
    left = 0
    right = len(height) - 1
    max_water = 0

    while left < right:
        width = right - left
        container_height = min(height[left], height[right])
        water = width * container_height
        max_water = max(max_water, water)

        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_water

# Test the function
heights = [1,8,6,2,5,4,8,3,7]
result = maxArea(heights)
print(f"The maximum amount of water that can be contained is: {result}")
