class Node:
    def __init__(self, data=None) -> None:
        self.data = data
        self.next = None
        self.prev = None


class DoublyList:
    def __init__(self) -> None:
        self.front = None
        self.back = None
        self.size = 0

    def add_back(self, data: int) -> None:
        node = Node(data)
        if self.is_empty():
            self.front = node
            self.back = node
        else:
            self.back.next = node
            node.prev = self.back
            self.back = node

        self.size += 1
    
    def add_front(self, data: int) -> None:
        node = Node(data) 
        if self.is_empty():
            self.front = node
            self.back = node 
        else:
            node.next = self.front 
            self.front.prev = node 
            self.front = node
        
        self.size += 1

    def remove(self, data: int) -> None:
        if self.is_empty():
            raise Exception("Error: list is aleady empty.")
        else:
            ptr = self.front
            while ptr.next is not None:
                if (ptr.data == data):
                    ptr.prev = ptr.prev.prev
                    ptr.next = ptr.next.next
                    self.size -= 1
                    return
                ptr = ptr.next
            raise Exception("Error: element is not found on the list")

    def remove_front(self)->None:
        if self.is_empty():
            return
        else:
            self.front = self.front.next
            self.size -= 1

    def remove_back(self)->None:
        if self.is_empty():
            return
        else:
            self.back = self.back.prev
            self.size -= 1

    def display(self) -> None:
        ptr = self.front
        while ptr.next is not None:
            print(ptr.data)
            ptr = ptr.next

    def is_empty(self) -> bool:
        return self.front is None and self.back is None

    def display_reverse(self) -> None:
        pass
