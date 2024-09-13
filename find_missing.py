
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]

def find_missing(arr):
    n = len(arr)
    #sum1 = (n + 1) * (n + 2) / 2
    sum1 = (n+1) * (n+2) / 2
    sum2 = sum(arr)
    return sum1 - sum2




print(find_missing(arr))


def max_product(arr):
    sorted_array = sorted(arr)
    print(sorted_array)
    m1, m2 = sorted_array[:-3:-1]
    print(m1, m2)
    return m1*m2

arr = [1, 7, 3, 4, 9, 5]

print(max_product(arr)) 

def middle(lst):
    return lst[1:-1]

myList = [1, 2, 3, 4]
print(middle(myList))  # [2,3]


def diagonal_sum(arr):
    sum = 0
    for i in range(len(arr)):
        print(i, arr[i][i])
        sum += arr[i][i]
    return sum

myList2D= [[1,2,3],[4,5,6],[7,8,9]] 
 
print(diagonal_sum(myList2D)) # 15



def traverse_dict(dict):
    for key in dict:
        print(key, dict[key])


my_dict = {'a': 1, 'b': 2, 'c': 3}

traverse_dict(my_dict)


def find_value(dict, value):
    for key in dict:
        if dict[key] == value:
            return key
        return None
    
print(find_value(my_dict, 2))  # b


big_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
             33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 
             63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92,
             93, 94, 95, 96, 97, 98, 99, 100]

import numpy as np

def create_big_array(size):
    return np.arange(1, size + 1)

big_array = create_big_array(100000000)

def binary_search1(arr, value):
    low = 0
    high = len(arr) - 1
    steps = 0
    while low <= high:
        mid = (low + high) // 2
        print(mid, low, high, steps)
        if arr[mid] == value:
            return mid
        elif arr[mid] < value:
            low = mid + 1
            steps += 1
        else:
            high = mid - 1
            steps += 1
    return -1


def binary_search(arr, value):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == value:
            return mid
        if arr[mid] < value:
            low = mid + 1
        if arr[mid] > value:
            high = mid - 1
    return -1

    
print(binary_search1(big_array, 87654321)) 
print(binary_search(big_array, 87654321)) 
print()
print(binary_search1(big_array, 50000000))
print(binary_search(big_array, 50000000))
print()
print("one : ", binary_search1(big_array, 25000000))
print("two : ", binary_search(big_array, 25000000))
print()
print("one : ", binary_search1(big_array, 12500000))
print("two : ", binary_search(big_array, 12500000))


dict = {'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5}

def remove_item(dict, value):
    del dict[value]
    return dict

print(remove_item(dict, 'three'))