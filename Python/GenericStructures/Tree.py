from typing import TypeVar, Generic

T = TypeVar("T")


class Node(Generic[T]):
    left: Node[T] = None
    right: Node[T] = None

    def __init__(self, data: T = None):
        self.data = data


class Tree(Generic[T]):
    m_size: int = 0
    m_root: Node[T] = None

    def insert_node(self, node: Node[T]) -> None:
        if self.is_empty():
            self.m_root = node
        else:
            ptr = self.m_root
            while ptr != None:
                if node.data < ptr.data:
                    ptr = ptr.left
                elif node.data > ptr.data:
                    ptr = ptr.right
                else:
                    return

            if node.data < ptr.data:
                ptr.left = node
            if node.data > ptr.data:
                ptr.right = node

        self.m_size += 1

    def insert_element(self, data: int) -> None:
        node = Node[T](data)
        if self.is_empty():
            self.m_root = node
        else:
            ptr = self.m_root
            while ptr.left is not None or ptr.right is not None:
                if node.data < ptr.data:
                    ptr = ptr.left
                elif node.data > ptr.data:
                    ptr = ptr.right
                else:
                    return

            if node.data < ptr.data:
                ptr.left = node
            if node.data > ptr.data:
                ptr.right = node

        self.m_size += 1

    def traverse_inorder(self, node: Node[T]) -> None:
        if node is not None:
            self.traverse_inorder(node.left)
            print(node.data)
            self.traverse_inorder(node.right)

    def traverse_preorder(self, node: Node[T]) -> None:
        if node is not None:
            print(node.data)
            self.traverse_preorder(node.left)
            self.traverse_preorder(node.right)

    def traverse_postorder(self, node: Node[T]) -> None:
        if node is not None:
            self.traverse_postorder(node.left)
            self.traverse_postorder(node.right)
            print(node.data)

    def delete_element(self, node: Node[T], data: int) -> None:
        if node is not None:
            return node
        elif data < node.data:
            node.left = self.delete_element(node.left, data)
        elif data > node.data:
            node.right = self.delete_element(node.right, data)
        else:
            # case 1:
            if node.left is None and node.right is None:
                ptr = None
            # case 2:
            elif node.left is None:
                ptr = node
                node = node.right
                ptr = None

            elif node.right is None:
                ptr = node
                node = node.left
                ptr = None
            # case 3:
            else:
                ptr = self.find_min(node)
                node.data = ptr.data
                ptr.right = self.delete_element(node.right, ptr.data)

    def find_min(self, node: Node[T]) -> Node[T]:
        while node.left is not None:
            node = node.left
        return node

    def is_empty(self) -> bool:
        return self.m_root == None


if __name__ == "__main__":
    t: Tree = Tree()
    ptr: Node[T] = t.m_root

    for i in range(0, 10):
        t.insert_element(i)

    t.traverse_postorder(t.m_root)
    print("done")
