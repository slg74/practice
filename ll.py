class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

    def __str__(self):
        return str(self.value)

    def set_next(self, value):
        self.next = Node(value)
        return self.next


class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def __str__(self):
        values = []
        current = self.head
        while current:
            values.append(str(current))
            current = current.next

        return " -> ".join(values)

    def reverse(self):
        previous = None
        current = self.head

        while current.next:
            tmp = current.next
            current.next = previous
            previous = current
            current = tmp

        current.next = previous

        self.head = current


def main():
    head = Node("a")
    head.set_next("b").set_next("c").set_next("d").set_next("e")

    ll = LinkedList(head)
    print(ll)
    ll.reverse()
    print(ll)


if __name__ == "__main__":
    main()
