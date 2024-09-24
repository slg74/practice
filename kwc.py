def kidsWithCandies(candies, extraCandies):
    max_candies = max(candies)
    result = []
    for candy in candies:
        if candy + extraCandies >= max_candies:
            result.append(True)
        else:
            result.append(False)
    return result

# Example usage
candies = [2, 3, 5, 1, 3]
extraCandies = 3
output = kidsWithCandies(candies, extraCandies)
print(output)
