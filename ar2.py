import numpy as np

my_array = np.array([1,2,3,4,5,6,7,8,9,10])

my_list = [1,2,3,4,5,6,7,8,9,10]

print(my_array/2)
print(my_list)

new_list = [x/2 for x in my_array]
print(new_list)

print(my_array)
new = [x/2 for x in my_array if x % 2 == 0]
print(new)

a=[1,2,3,4,5]
print(a[3:0:-1])

fruit_list1 = ['Apple', 'Berry', 'Cherry', 'Papaya']
fruit_list2 = fruit_list1
fruit_list3 = fruit_list1[:]
 
fruit_list2[0] = 'Guava'
fruit_list3[1] = 'Kiwi'
 
sum = 0
for ls in (fruit_list1, fruit_list2, fruit_list3):
    if ls[0] == 'Guava':
        sum += 1
    if ls[1] == 'Kiwi':
        sum += 20
 
print(sum)

arr = [1, 2, 3, 4, 5, 6]
for i in range(1, 6):
    arr[i - 1] = arr[i]
for i in range(0, 6): 
    print(arr[i], end = " ")


arr = [[1, 2, 3, 4],
       [4, 5, 6, 7],
       [8, 9, 10, 11],
       [12, 13, 14, 15]]
for i in range(0, 4):
    print(arr[i].pop())


print()

print(a)


data = [[[1, 2], [3, 4]], [[5, 6], [7, 8]]]
def fun(m):
    v = m[0][0]
 
    for row in m:
        for element in row:
            if v < element: v = element
 
    return v
print(fun(data[0]))

def f(value, values):
    v = 1
    values[0] = 44
t = 3
v = [1, 2, 3]
f(t, v)
print(t, v[0])

n = 121
for i in str(n):
    print(i)

n_arr = [int(x) for x in str(n)]
print(n_arr)