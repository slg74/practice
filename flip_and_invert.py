def flip_and_invert(image):
    n = len(image)
    for row in range(n):
        # Flip horizontally and invert simultaneously
        for col in range((n + 1) // 2):
            # Swap and invert elements
            image[row][col], image[row][n - 1 - col] = 1 - image[row][n - 1 - col], 1 - image[row][col]
    return image


image = [[1,1,0],[1,0,1],[0,0,0]]
result = flip_and_invert(image)
print(result)