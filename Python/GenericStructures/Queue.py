from typing import TypeVar, Generic

T = TypeVar("T")


class Node(Generic[T]):
    next: Node[T] = None

    def __init__(self, data: T) -> None:
        self.data = data


class Queue(Generic[T]):
    size: int = 0
    front: Node[T] = None
    back: Node[T] = None

    def enqueue(self, data: int) -> None:
        node = Node[T](data)

        if self.is_empty():
            self.front = node
            self.front = node
        else:
            ptr = self.front
            while ptr.next != None:
                ptr = ptr.next
            ptr.next = node
            self.back = node

        self.size += 1

    def dequeue(self) -> None:
        if self.front == None:
            raise Exception("Error: Queue is already empty.")
        self.front = self.front.next
        self.size -= 1

    def display(self) -> None:
        ptr = self.front
        while ptr.next != None:
            print(ptr.data)
            ptr = ptr.next

    def is_empty(self) -> bool:
        return self.front == None and self.size == 0


if __name__ == "__main__":
    q = Queue()
    for i in range(0, 9):
        q.enqueue(i)

    # q.dequeue()
    q.display()
