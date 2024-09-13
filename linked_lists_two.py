
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def __str__(self):
        temp_node = self.head
        result = ''
        while temp_node is not None:
            result += str(temp_node.value)
            if temp_node.next is not None:
                result += ' -> '
            temp_node = temp_node.next
        return result

    def append(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1

    def reverse(self):
        if self.length <= 1:
            return
        
        prev = None
        current = self.head
        self.tail = current

        while current:
            next_node = current.next
            current.next = prev 
            prev = current 
            current = next_node 

        self.head = prev


ll = LinkedList()
ll.append(10)
ll.append(20)
ll.append(30)
ll.append(40)

print(ll)
print(ll.length)

ll.reverse()
print(ll)
