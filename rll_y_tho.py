class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

    def __str__(self):
        return str(self.val)

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0
    
    def __str__(self):
        temp_node = self.head
        result = ''
        while temp_node is not None:
            result += str(temp_node.val)
            if temp_node.next is not None:
                result += ' -> '
            temp_node = temp_node.next
        return result
    
    def append(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1

    def print(self):
        cur = self.head
        while cur != None:
            print(cur.val)
            cur = cur.next
        
    def reverse(self):
        cur = self.head
        prev = None
        while cur != None:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        self.head, self.tail = self.tail, self.head


if __name__ == "__main__":

    a, b, c, d, e = Node('A'), Node('B'), Node('C'), Node('D'), Node('E')

    list = LinkedList()

    list.append(a)
    list.append(b)
    list.append(c)
    list.append(d)
    list.append(e)

    print("Original list:")
    list.print()
    print(list)

    print("Reversed list:")
    list.reverse()
    list.print()
    print(list)