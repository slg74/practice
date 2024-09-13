
s1 = 'abbbcdef'
s2 = 'pkewbbbb'
s3 = 'aaaaaaaa'


def get_longest_substring(s):
    longest = []
    for i in range(len(s)):
        if s[i + 1].get() and s[i] != s[i + 1]:
            longest.append(s[i])

    return longest


print(get_longest_substring(s1))
print(get_longest_substring(s2))
print(get_longest_substring(s3))