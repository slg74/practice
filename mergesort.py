def merge_sort(arr):
    # Return if the array has 1 or no elements
    if len(arr) < 2:
        return

    # Finding the middle of the array
    mid = len(arr) // 2

    # Dividing the array elements into 2 halves
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Sorting the first half
    merge_sort(left_half)

    # Sorting the second half
    merge_sort(right_half)

    # Merging the two halves
    i = j = k = 0

    # Copy data to temp arrays L[] and R[]
    while i < len(left_half) and j < len(right_half):
        if left_half[i] < right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
        k += 1

    # Checking if any element was left
    while i < len(left_half):
        arr[k] = left_half[i]
        i += 1
        k += 1

    while j < len(right_half):
        arr[k] = right_half[j]
        j += 1
        k += 1

# Example usage
arr = [38, 27, 43, 3, 9, 82, 10]
print("Original array:", arr)
merge_sort(arr)
print("Sorted array:", arr)