from typing import TypeVar, Generic

T = TypeVar("T")


class Node(Generic[T]):
    next: Node[T] = None

    def __init__(self, data: T) -> None:
        self.data = data


class Stack(Generic[T]):
    top: Node[T] = None
    size: int = 0

    def push(self, data: int) -> None:
        node = Node[T](data)
        node.next = self.top
        self.top = node
        self.size += 1

    def pop(self) -> None:
        if self.is_empty():
            raise Exception("Stack is already")
        self.top = self.top.next
        self.size -= 1

    def display(self) -> None:
        ptr = self.top
        while ptr.next != None:
            print(ptr.data)
            ptr = ptr.next

    def is_empty(self) -> bool:
        return self.size == 0


if __name__ == "__main__":
    s = Stack()
    for i in range(0, 9):
        s.push(i)

    s.pop()
    s.display()
