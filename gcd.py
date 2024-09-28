import math

def gcdOfStrings(str1: str, str2: str) -> str:
    if str1 + str2 != str2 + str1:
        return ""
    
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    
    gcd_length = gcd(len(str1), len(str2))
    return str1[:gcd_length]

def gcdOfStrings2(str1: str, str2: str) -> str:
    if not str1 or not str2:
        return "one or both strings are empty"
    
    if (str1 + str2) == (str2 + str1):
        length_of_common_str = math.gcd(len(str1), len(str2))
        return str1[0:length_of_common_str]

    return ""

# Test the function
print(gcdOfStrings("ABCABC", "ABC"))  # Output: "ABC"
print(gcdOfStrings("ABABAB", "ABAB"))  # Output: "AB"
print(gcdOfStrings("LEETLEET", "LEET"))  # Output: "LEET"

print(gcdOfStrings2("ABCABC", "ABC"))  # Output: "ABC"
print(gcdOfStrings2("ABABAB", "ABAB"))  # Output: "AB"
print(gcdOfStrings2("LEETLEET", "LEET"))  # Output: "LEET"