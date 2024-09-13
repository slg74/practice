class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        # initialize list with dummy node
        self.head = ListNode(-1)
        self.tail = self.head

    def insert_end(self, value):
        self.tail.next = ListNode(value)
        self.tail = self.tail.next

    def remove(self, index):
        i = 0
        current = self.head
        while i < index and current:
            i += 1
            current = current.next

        if current and current.next:
            if current.next == self.tail:
                self.tail = current
            current.next = current.next.next

    def print(self):
        current = self.head.next
        while current:
            print(current.value, "-> ", end="")
            current = current.next
        print()

    def reverse(self):
        prev = None
        curr = self.head.next
        self.tail = curr
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        self.head.next = prev

    def reverse_with_new_head(self):
        prev = None 
        curr = self.head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev


node1 = ListNode("red")
node2 = ListNode("green")
node3 = ListNode("blue")


linked_list = LinkedList()

linked_list.insert_end(node1.value)
linked_list.insert_end(node2.value)
linked_list.insert_end(node3.value)
linked_list.insert_end("purple")
linked_list.print()
linked_list.remove(2)
linked_list.print()
linked_list.reverse()
linked_list.print()
linked_list.print()

new_linked_list = LinkedList()
new_linked_list.insert_end(node1.value)
new_linked_list.insert_end(node2.value)
new_linked_list.insert_end(node3.value)
new_linked_list.insert_end("purple")


new_linked_list.print()
new_head = new_linked_list.reverse_with_new_head()
new_linked_list.head = new_head
new_linked_list.print()