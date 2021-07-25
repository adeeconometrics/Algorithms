from typing import Final


class Node:
    def __init__(self, parent: Node = None, left: Node = None, right: Node = None, value: int = 0, color: bool = True):
        if parent is not None:
            self.parent = parent
        if left is not None:
            self.left = left
        if right is not None:
            self.right = right
        if value != 0:
            self.value = value
        if color != True:
            self.color = color


class RBT:
    red: Final[bool] = True
    black: Final[bool] = False

    NIL: Node = None
    size: int = 0

    def __init__(self):
        self.NIL = Node(color=black, value=0)
        self.NIL.left = NIL
        self.NIL.right = NIL
        self.NIL.parent = NIL
        self.root = NIL

    def is_empty(self) -> bool:
        return self.size == 0

    def is_element(self, value: int):
        node = self.root

        if node is None or value == 0:
            return False
        while node is not None:
            if node.value > value:
                node = node.left
            if node.value < value:
                node = node.right
            else:
                return True

        return False

    def insert(self, value: int) -> bool:
        if value == 0:
            raise ValueError("invalid argument error")

        x: Node = self.root
        y: Node = self.NIL

        while x != NIL:
            y = x

            if x.value > value:
                x = x.left
            elif x.value < value:
                x = x.right
            else:
                return False

        z: Node = Node(value=value, color=red, parent=y,
                       left=self.NIL, right=self.NIL)

        if y == self.NIL:
            self.root = z
        elif z.value > y.value:
            y.left = z
        else:
            y.right = z

        self.fix_insertion_at(z)
        self.size += 1
        return True

    def remove(self, value: int) -> bool:
        z: Node = None
        # if value == 0 or (z := (self.search(value, self.root) == self.NIL):
        #     return False

        y_original_color: bool = (y := Node()).color
        # if a
