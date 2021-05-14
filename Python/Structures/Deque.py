class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next: Node = None
        self.prev: Node = None


class Deque:
    def __init__(self) -> None:
        self.size: int = 0
        self.front: Node = None
        self.back: Node = None

    def push_back(self, data: int) -> None:
        node = Node(data)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            self.back.next = node
            node.prev = self.back
            self.back = node

        self.size += 1

    def push_front(self, data: int) -> None:
        node = Node(data)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            self.front.next = node
            node.prev = self.front
            self.front = node

        self.size += 1

    def pop_back(self) -> None:
        ptr = self.back.prev
        self.back = ptr
        self.size -= 1

    def pop_front(self) -> None:
        ptr = self.front.prev
        self.front = ptr
        self.size -= 1

    def display(self) -> None:
        ptr = self.front
        # print(self.front.next is None)
        while ptr.prev != None:
            print(ptr.data)
            ptr = ptr.prev

    def display_reverse(self) -> None:
        ptr = self.back
        # print(self.back.next is None)
        while ptr.next != None:
            print(ptr.data)
            ptr = ptr.next

    def is_empty(self) -> bool:
        return self.front == None and self.size == 0


if __name__ == '__main__':
    dq = Deque()
    for i in range(0, 9):
        dq.push_front(i)
    # dq.push_back(25) problematic
    dq.pop_front()
    # dq.pop_back()

    dq.display()
    # dq.display_reverse() problematic