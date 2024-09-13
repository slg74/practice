# reverse a linked list

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def print(self):
        current = self
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")

    def reverse(self):
        prev = None
        current = self

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        return prev

    def add_next(self, val):
        current = self
        while current.next:
            current = current.next
        current.next = ListNode(val)


head = ListNode(1)
head.add_next(2)
head.add_next(3)
head.add_next(4)
head.add_next(5)

head.print()

new_head = head.reverse()

new_head.print()


