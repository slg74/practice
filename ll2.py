class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


a = Node('A')
b = Node('B')
c = Node('C')
d = Node('D') # d.next = None ... A -> B -> C -> D -> None

a.next = b
b.next = c
c.next = d

# 1. 
#
#               cur.next
#  N    ->    a    ->    b    ->    c
# prev       cur        next
#
# 2. 
#
#               cur.next
#  N    ->    a    ->    b    ->    c
# prev       cur        next
#
# 3. 
#
#   cur.next = prev
#   prev = cur
#
#                cur.next
#  N    <-    a    <-    b    ->    c
#            cur        next
#            prev       cur        next
#
# 4.
#
#   cur.next = prev
#   prev = cur
#
#                           cur.next
#  N    <-    a    <-    b    <-    c    ->    NULL
#                       cur        next
#                       prev       cur         next
#
# 4. 
#
#   cur.next = prev
#   prev = cur
#
#                                      cur.next
#  N    <-    a    <-    b    <-    c    <-    NULL
#                                  cur         next = NULL
#                                  prev        cur = NULL
#
#               


def reverse_list(head):
    cur = head
    prev = None
    while cur != None:
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    return prev



def rev(head):
    current = head
    prev = None
    while current != None:
        next = current.next
        current.next = prev
        prev = current
        current = next
    return prev

def reverse_linked_list(head):
    current = head
    prev = None
    while current != None:
        next = current.next
        current.next = prev # setting former head to point to null, which whill be the new end of the reversed list.
        prev = current
        current = next
    return prev


def print_linked_list(head):
    current = head
    while current != None:
        print(current.val)
        current = current.next

print_linked_list(a)
print('\n\n')

def print_linked_list_recursive(head):
    if head == None:
        return
    print(head.val)
    print_linked_list_recursive(head.next)

    
print_linked_list_recursive(a)
print('\n\n')

print_linked_list(reverse_list(a))
