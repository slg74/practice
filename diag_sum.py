def calculate_diagonal_sum(size):
    if size == 1:
        return 1
        
    # Initialize sum with 1 (center)
    total = 1
    
    # For each layer
    for layer in range(3, size + 1, 2):
        # Each corner value in current layer
        bottom_right = layer * layer
        bottom_left = bottom_right - (layer - 1)
        top_left = bottom_left - (layer - 1)
        top_right = top_left - (layer - 1)
        
        # Add all corners
        total += bottom_right + bottom_left + top_left + top_right

    return total

# Calculate for 1001x1001 spiral
result = calculate_diagonal_sum(1001)
print(f"Sum of diagonals: {result}")
