def merge_sorted_lists(list1, list2):
    merged_list = []
    i = j = 0
    
    while i < len(list1) and j < len(list2):
        if list1[i] < list2[j]:
            merged_list.append(list1[i])
            i += 1
        else:
            merged_list.append(list2[j])
            j += 1
    
    # Append remaining elements
    merged_list.extend(list1[i:])
    merged_list.extend(list2[j:])
    
    return merged_list

# Test
list1 = [1, 3, 5]
list2 = [2, 4, 6]
print(merge_sorted_lists(list1, list2))