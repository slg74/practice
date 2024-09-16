class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

a = Node('A')
b = Node('B')
c = Node('C')
d = Node('D')
e = Node('E')

a.next = b
b.next = c
c.next = d
d.next = e

def print_linked_list(head):
    cur = head
    while cur != None:
        print(cur.val)
        cur = cur.next

print_linked_list(a)
print('\n')


#    None  ->  A  ->   B   ->   C  ->   D  ->  E   ->   None
#    prev     cur      next
#
#    None  <-  A  ->   B   ->   C  ->   D  ->  E   ->   None
#             prev     cur      next
#           
#    None  <-  A  <-   B   ->  C  ->   D  ->  E   ->   None
#                      prev    cur     next
#
#    None  <-  A  <-   B   <-  C  ->   D  ->  E   ->   None
#                              prev    cur    next
#
#    None  <-  A  <-   B   <-  C  <-   D  ->  E   ->   None
#                                      prev   cur      next
#
#    None  <-  A  <-   B   <-  C  <-   D  <-  E   <-   None
#                                             prev     cur    next... cur == None, return prev (E-D-C-B-A)
#

def rev(head):
    cur = head
    prev = None
    while cur != None:
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    return prev


def reverse_linked_list(head):       
    cur = head
    prev = None
    while cur != None:
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    return prev

print_linked_list(reverse_linked_list(a))





