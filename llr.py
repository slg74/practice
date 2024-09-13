class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

a = Node('A')
b = Node('B')
c = Node('C')
d = Node('D')

a.next = b
b.next = c
c.next = d


def print_list(head):
    cur = head
    while cur != None:
        print(cur.val)
        cur = cur.next

print_list(a)
print('\n')

def reverse_list(head):
    cur = head
    prev = None
    while cur != None:
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    return prev

print_list(reverse_list(a))

