def merge_lists(list1, list2):
    merged = []
    i = 0
    j = 0

    while i < len(list1) and j < len(list2):
        if list1[i] < list2[j]:
            merged.append(list1[i])
            i += 1
        else:
            merged.append(list2[j])
            j += 1

    while i < len(list1):
        merged.append(list1[i])
        i += 1
    while j < len(list2):
        merged.append(list2[j])
        j += 1

    return merged

l1 = [1, 3, 5]
l2 = [2, 4, 6]

print(merge_lists(l1, l2))