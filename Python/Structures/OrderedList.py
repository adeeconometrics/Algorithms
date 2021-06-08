class Node:
    next: Node = None
    prev: Node = None
    data: int

    def __init__(self, data=0) -> None:
        self.data = data


class OrderedList:
    front: Node = None
    back: Node = None
    size: int = 0

    def add(self, data: int) -> None:
        node: Node = None(data)
        if self.is_empty():
            self.front = node
            self.back = node
        elif data > self.front.data:
            self._add_front(node)
        elif data > self.back.data:
            self._add_back(node)
        else:
            ptr: Node = self.front
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
            ptr: Node = self.front
            prev: Node = ptr

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
        ptr: Node = self.front
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
        temp: Node = self.front
        self.front = self.front.next
        temp = None
        size -= 1

    def _remove_back(self) -> None:
        temp: Node = self.back
        self.back = self.back.prev
        temp = None
        size -= 1

    def is_empty(self) -> bool:
        return self.front is None and self.back is None
