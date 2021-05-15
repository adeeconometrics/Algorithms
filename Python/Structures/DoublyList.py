class Node:
    def __init__(self, data=None) -> None:
        self.data = data
        self.next = None
        self.prev = None


class DoublyList:
    def __init__(self) -> None:
        self.head = None
        self.back = None
        self.size = 0

    def add(self, data: int) -> None:
        node = Node(data)
        if self.is_empty():
            self.head = node
            self.back = node
        else:
            self.back.next = node
            node.prev = self.back
            self.back = node

        self.size += 1

    def remove(self, data: int) -> None:
        if self.is_empty():
            raise Exception("Error: list is aleady empty.")
        else:
            ptr = self.head
            while ptr.next is not None:
                if (ptr.data == data):
                    ptr.prev = ptr.prev.prev
                    ptr.next = ptr.next.next
                    self.size -= 1
                    return
                ptr = ptr.next
            raise Exception("Error: element is not found on the list")

    def display(self) -> None:
        ptr = self.head
        while ptr.next is not None:
            print(ptr.data)
            ptr = ptr.next

    def is_empty(self) -> bool:
        return self.head is None and self.back is None

    def display_reverse(self) -> None:
        pass
