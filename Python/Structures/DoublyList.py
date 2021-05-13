class Node:
    def __init__(self, data=None) -> None:
        self.data = data
        self.next = None
        self.prev = None


class DoublyList:
    def __init__(self) -> None:
        self.head = None

    def add(self, obj: int) -> None:
        node = Node(obj)
        head = node

    def display(self) -> None:
        pass

    def is_empty(self) -> bool:
        pass
    def display_reverse(self) -> None:
        pass
