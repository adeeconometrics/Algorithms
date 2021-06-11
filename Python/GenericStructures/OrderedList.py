from typing import TypeVar, Generic

T = TypeVar("T")


class Node(Generic[T]):
    next: Node[T] = None
    prev: Node[T] = None
    data: int

    def __init__(self, data=0) -> None:
        self.data = data


class OrderedList(Generic[T]):
    front: Node[T] = None
    back: Node[T] = None
    size: int = 0

    def add(self, data: int) -> None:
        node: Node[T] = None(data)
        if self.is_empty():
            self.front = node
            self.back = node
        elif data > self.front.data:
            self._add_front(node)
        elif data > self.back.data:
            self._add_back(node)
        else:
            ptr: Node[T] = self.front
            while ptr.next is not None:
                if ptr.data > data:
                    break
                ptr = ptr.next

            if ptr.next is not None:
                ptr.next.prev = node
                node.next = ptr.next
                node.prev = ptr
                ptr.next = ptr

        size += 1

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
                    prev.next = ptr.next
                    ptr.prev = prev

                    ptr = None
                    self.size -= 1
                    return
                prev = ptr
                ptr = ptr.next

    def display(self) -> None:
        ptr: Node[T] = self.front
        while ptr.next is not None:
            print(ptr.data)
            ptr = ptr.next

    def _add_front(self, node: Node) -> None:
        self.front.prev = node
        node.next = self.front
        self.front = node

    def _add_back(self, node: Node) -> None:
        self.back.next = node
        node.prev = self.back
        back = node

    def _remove_front(self) -> None:
        temp: Node[T] = self.front
        self.front = self.front.next
        temp = None
        self.size -= 1

    def _remove_back(self) -> None:
        temp: Node[T] = self.back
        self.back = self.back.prev
        temp = None
        self.size -= 1

    def is_empty(self) -> bool:
        return self.front is None and self.back is None
