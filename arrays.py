
from array import *

arr1 = array('i', [1, 2, 3, 4, 5])

def access_element(array, index):
    if index >= len(array):
        print("Index out of range")
    else:
        print(array[index])


access_element(arr1, 3)
access_element(arr1, 6)
access_element(arr1, 4)
access_element(arr1, 5)

arr2 = array('i', [9, 9, 9])

array.extend(arr1, arr2)

print(arr1)

temp_list = [20, 21, 22]

arr1.fromlist(temp_list)

print(arr1)

arr1.remove(9)

print(arr1)

name_array = array('u', ['s', 'c', 'o', 't', 't'])

print(name_array)

name_array.reverse()

print(name_array)

print(name_array.buffer_info())

print(arr1.count(9))

print(name_array.count('t'))

arr1.append(9999)

print(arr1)

s = name_array.tobytes()
print(s)
chars = array('u')
chars.frombytes(s)
print(chars)

print(arr1.tolist())
new_arr = arr1[2:5]

print(new_arr)

print(arr1[:4])
print(arr1[5:])