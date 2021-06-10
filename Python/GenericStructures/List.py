from typing import TypeVar, Generic

T = TypeVar("T")


class Node(Generic[T]):
    next: Node[T] = None
    prev: Node[T] = None

    def __init__(self, data: T = None) -> None:
        self.data = data


class List(Generic[T]):
    front: Node[T] = None
    back: Node[T] = None
    size: int = 0

    def add_back(self, data: int) -> None:
        node = Node[T](data)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            self.back.next = node
            node.prev = self.back
            self.back = node

        self.size += 1

    def add_front(self, data: int) -> Node:
        node = Node[T](data)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            self.front.prev = node
            node.next = self.node
            self.front = node

        self.size += 1

    def remove(self, data: int) -> None:
        if self.is_empty():
            raise Exception("Error: element not found in the list.")

        elif self.front.data == data:
            self._remove_front()
        elif self.back.data == data:
            self._remove_back()
        else:
            ptr: Node[T] = self.front
            prev: Node[T] = ptr

            while ptr.next is not None:
                if ptr.data == data:
                    ptr.next = ptr.next
                    ptr.prev = prev

                    ptr = None
                    size -= 1
                    return
                prev = ptr
                ptr = ptr.next

    def display(self) -> None:
        ptr: Node[T] = self.front
        while ptr.next is not None:
            print(ptr.data)
            ptr = ptr.next

    def _remove_front(self) -> None:
        temp: Node[T] = self.front
        self.front = self.front.next
        temp = None
        size -= 1

    def _remove_back(self) -> None:
        temp: Node[T] = self.back
        self.back = self.back.prev
        temp = None
        size -= 1

    def is_empty(self) -> bool:
        return self.front is None and self.back is None

    def display_reverse(self) -> None:
        pass
