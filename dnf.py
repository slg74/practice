def sort_colors(nums):

    colors = {
        0: 0,
        1: 0, 
        2: 0
    }

    for num in nums:
        colors[num] += 1

    print(colors)

    index = 0
    for color in range(3):
        print(f"DEBUG color: {color}")
        for _ in range(colors[color]):
            nums[index] = color
            print(f"DEBUG nums[index] {nums[index]} = color {color}")
            index += 1

    return nums

# Example usage
arr = [2, 0, 2, 1, 0, 1, 1, 0, 2, 1, 0, 2]
print("Original array:", arr)
sorted_arr = sort_colors(arr)
print("Sorted array:", sorted_arr)
