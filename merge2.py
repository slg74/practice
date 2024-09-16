class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_two_lists(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode(0)
    current = dummy
    
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    
    if l1:
        current.next = l1
    if l2:
        current.next = l2
    
    return dummy.next

# Helper function to create a linked list from a list of values
def create_linked_list(values):
    dummy = ListNode(0)
    current = dummy
    for val in values:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

# Helper function to print a linked list
def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Test the merge function
list1 = create_linked_list([1, 3, 5])
list2 = create_linked_list([2, 4, 6])

print("List 1:")
print_linked_list(list1)
print("List 2:")
print_linked_list(list2)

merged = merge_two_lists(list1, list2)
print("Merged list:")
print_linked_list(merged)
