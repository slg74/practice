from collections import Counter

def top_k_frequent(nums, k):
    frequency = Counter(nums)
    return [item for item, count in frequency.most_common(k)]

# Example usage
if __name__ == "__main__":
    nums = [1, 1, 1, 2, 2, 3]
    k = 2
    result = top_k_frequent(nums, k)
    print(f"The {k} most frequent elements are: {result}")