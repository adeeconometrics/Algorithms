from typing import Generic, TypeVar

T = TypeVar("T")


class Node(Generic[T]):
    next: Node = None

    def __init__(self, data: T = None) -> None:
        self.data = data


class SinglyList(Generic[T]):
    size: int = 0

    def __init__(self) -> None:
        self.front = None
        self.back = None

    def add_front(self, obj: int) -> None:
        node = Node(obj)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            node.next = self.front
            self.front = node

        self.size += 1

    def add_back(self, obj: int) -> None:
        node = Node(obj)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            self.back.next = node
            self.back = node

        self.size += 1

    def display(self) -> None:
        ptr = self.front
        while ptr.next is not None:
            print(ptr.data)
            ptr = ptr.next

    def remove(self, data: int) -> None:
        node = Node(data)
        ptr: Node = self.front
        prev: Node = ptr

        while ptr.next is not None:
            if ptr.data == data:
                prev.next = ptr.next
                self.size -= 1
                break
            prev = ptr
            ptr = ptr.next
        raise Exception("{0} is not an element found in the list.".format(data))

    def remove_back(self) -> None:
        if self.is_empty():
            return
        else:
            ptr: Node = self.front
            while ptr.next is not self.back:
                ptr = ptr.next

            self.back = ptr
            self.size -= 1

    def remove_front(self) -> None:
        if self.is_empty():
            return
        else:
            self.front = self.front.next
            self.size -= 1

    def is_empty(self) -> bool:
        return self.front == None

    def is_element(self) -> bool:
        pass


if __name__ == "__main__":
    s = SinglyList()
    for i in range(0, 9):
        s.add(i)
    s.remove(11)
    s.display()
