
import numpy as np

two_dimensional_array = np.array([[11, 15, 10, 6], [10, 14, 11, 5], [12, 17, 12, 8], [15, 18, 14, 9]])

print(two_dimensional_array)

#new_two_dimensional_array = np.insert(two_dimensional_array, 0, [[1, 2, 3, 4]], axis=1)

#print(new_two_dimensional_array)

#new_two_dimensional_array = np.insert(two_dimensional_array, 1, [[100, 200, 300, 400]], axis=0)
#


print(two_dimensional_array[2, 3])
print(two_dimensional_array[3, 3])
print(two_dimensional_array[0, 0])
print(two_dimensional_array[0, 3])

def traverse_2d_array(array):
    for row in array:
        for element in row:
            print(element)


traverse_2d_array(two_dimensional_array)


def search_2d_array(array, value):
    for row in array:
        for element in row:
            if element == value:
                return True
    return False

print(search_2d_array(two_dimensional_array, 100))
print(search_2d_array(two_dimensional_array, 18))



def search_2d_array_index(array, value):
    for i in range(len(array)):
        for j in range(len(array[i])):
            if array[i][j] == value:
                return i, j
    return -1, -1


print(search_2d_array_index(two_dimensional_array, 100))
print(search_2d_array_index(two_dimensional_array, 18))


print(two_dimensional_array)
print()

new_2d_array = np.delete(two_dimensional_array, 3, axis=1)

print(new_2d_array)