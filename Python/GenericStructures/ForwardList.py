from typing import Generic, TypeVar

T = TypeVar("T")


class Node(Generic[T]):
    next: Node = None

    def __init__(self, data=None) -> None:
        self.data = data


class SinglyList(Generic[T]):
    head: Node = None

    def add(self, obj: int) -> None:
        node = Node(obj)
        if self.is_empty():
            node.next = self.head
            self.head = node
        else:
            ptr = self.head
            while ptr.next != None:
                ptr = ptr.next

            ptr.next = node

    def display(self) -> None:
        ptr = self.head
        while ptr.next != None:
            print(ptr.data)
            ptr = ptr.next

    def remove(self, data: int) -> None:
        node = Node(data)
        ptr = self.head
        prev = ptr
        while ptr.next != None:
            if ptr.data == data:
                prev.next = ptr.next
                break
            prev = ptr
            ptr = ptr.next
        raise Exception("{0} is not an element found in the list.".format(data))

    def is_empty(self) -> bool:
        return self.head == None

    def is_element(self) -> bool:
        pass


if __name__ == "__main__":
    s = SinglyList()
    for i in range(0, 9):
        s.add(i)
    s.remove(11)
    s.display()
