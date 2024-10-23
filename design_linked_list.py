class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None
        self.prev = None

class MyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
        
    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        
        curr = self.head
        for _ in range(index):
            curr = curr.next
        return curr.val
    
    def addAtHead(self, val: int) -> None:
        new_node = ListNode(val)
        self.size += 1
        
        if not self.head:
            self.head = new_node
            self.tail = new_node
            return
        
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
        
    def addAtTail(self, val: int) -> None:
        new_node = ListNode(val)
        self.size += 1
        
        if not self.tail:
            self.head = new_node
            self.tail = new_node
            return
        
        new_node.prev = self.tail
        self.tail.next = new_node
        self.tail = new_node
        
    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        
        if index == 0:
            self.addAtHead(val)
            return
        
        if index == self.size:
            self.addAtTail(val)
            return
        
        curr = self.head
        for _ in range(index):
            curr = curr.next
            
        new_node = ListNode(val)
        new_node.prev = curr.prev
        new_node.next = curr
        curr.prev.next = new_node
        curr.prev = new_node
        self.size += 1
        
    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        
        self.size -= 1
        
        if self.size == 0:
            self.head = None
            self.tail = None
            return
        
        if index == 0:
            self.head = self.head.next
            self.head.prev = None
            return
        
        if index == self.size:
            self.tail = self.tail.prev
            self.tail.next = None
            return
        
        curr = self.head
        for _ in range(index):
            curr = curr.next
            
        curr.prev.next = curr.next
        if curr.next:
            curr.next.prev = curr.prev


# Test the implementation
linked_list = MyLinkedList()
linked_list.addAtHead(1)
linked_list.addAtTail(3)
linked_list.addAtIndex(1, 2)    # linked list becomes 1->2->3
print(linked_list.get(1))       # returns 2
linked_list.deleteAtIndex(1)    # now the linked list is 1->3
print(linked_list.get(1))       # returns 3
