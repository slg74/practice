
def length_of_longest_substr(s):

    str_list = []
    max_length = 0

    for x in s: 
        if x in str_list:
            str_list = str_list[str_list.index(x) + 1:]
            print(str_list)

        str_list.append(x)
        max_length = max(max_length, len(str_list))

    return max_length



str = "pwwkew"

print(length_of_longest_substr(str))


tuple1 = [(1, 2), (2, 3, 4), (5, 7)]
print(tuple1)


