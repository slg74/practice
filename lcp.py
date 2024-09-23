def longestCommonPrefix(strs):
    if not strs:
        return ""
    
    # Take the first string as a reference
    prefix = strs[0]
    
    for i in range(1, len(strs)):
        # Keep reducing the prefix until it matches the current string
        while strs[i].find(prefix) != 0:
            prefix = prefix[:-1]
            if not prefix:
                return ""
    
    return prefix

# Test the function
strs = ["flower", "flow", "flight"]
print(longestCommonPrefix(strs))  # Output: "fl"

# Additional test cases
print(longestCommonPrefix(["dog", "racecar", "car"]))  # Output: ""
print(longestCommonPrefix(["interspecies", "interstellar", "interstate"]))  # Output: "inters"
print(longestCommonPrefix(["throne", "throne"]))  # Output: "throne"
print(longestCommonPrefix(["", "b"]))  # Output: ""
print(longestCommonPrefix([]))  # Output: ""
