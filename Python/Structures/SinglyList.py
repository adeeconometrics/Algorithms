class Node:
    def __init__(self, data=None) -> None:
        self.data = data
        self.next = None


class SinglyList:
    def __init__(self) -> None:
        self.head = None

    def add(self, obj: int) -> None:
        node = Node(obj)
        node.next = self.head
        self.head = node

    def display(self) -> None:
        ptr = self.head
        while ptr.next != None:
            print(ptr.data)
            ptr = ptr.next

    def is_empty(self) -> bool:
        pass

    def remove(self, obj: int) -> None:
        pass


if __name__ == '__main__':
    s = SinglyList()
    for i in range(0, 9):
        s.add(i)
    s.display()
