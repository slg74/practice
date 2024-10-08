
def is_palindrome(s):
    if s[:] == s[::-1]:
        print(f"{s} is a palindrome")
    else:
        print(f"{s} is not a palindrome")


s = "racecar"
j = "racecarracecar"
k = "kangaroo"

is_palindrome(s)
is_palindrome(j)
is_palindrome(k)

