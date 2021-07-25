class Node:
    bf: int = 0
    height: int = 0  # to query in O(1), this has to be stored in every node

    def __init__(self, data=None):
        self.left = None
        self.right = None
        if data is not None:
            self.data = data


# core concepts:
#   - invariant
#   - rotations


class AVL:
    m_size: int = 0
    node_count: int = 0
    # height: int = 0
    lh: int = 0
    rh: int = 0

    def __init__(self):
        self.m_root = None

    def insert(self, node: Node) -> bool:
        if node is None:
            return False

        # only insert unique values
        if not self.contains(
            self.m_root, node.data
        ):  # edited to node.data, is this reasonable?
            self.m_root = self.insert(self.m_root, node)
            self.node_count += 1
            return True
        # value already exists in tree
        return False

    def insert(self, node: Node, value: int) -> Node:
        if node is None:
            return Node(value)

        cmp: int = self.compare(value, node.value)

        if cmp < 0:
            node.left = insert(node.left, value)
        else:
            node.right = insert(node.right, value)

        # update balance factor and height values.
        self.update(node)

        # rebalance tree
        return self.balance(node)

    def update(self, node: Node) -> None:
        self.lh = -1
        self.rh = -1
        if node.left is None:
            lh = node.left.height
        if node.right is None:
            rh = node.right.height

        # update this node's height
        node.height = 1 + max([lh, rh])
        # update bf
        node.bf = rh - lh

    def contains(self, node: Node, data: int) -> bool:
        if node is None:
            return False
        if node.data < data:  # cmp: value.compareTo(node.value)
            return self.contains(node.left, data)
        if node.data > data:
            return self.contains(node.right, data)

        return True

    def balance(self, node: Node) -> Node:
        # left heavy subtree
        if node.bf == -2:
            if node.left.bf <= 0:
                return self.left_left_case(node)
            else:
                return self.left_right_case(node)

        elif node.bf == 2:
            if node.right.bf >= 0:
                return self.right_right_case(node)
            else:
                return self.right_left_case(node)

        # node has bf of {-1,0,1} that is already balance so we return node
        return node

    def left_right_case(self, node: Node) -> Node:
        node.left = self.left_rotation(node.left)
        return self.left_left_case(node)

    def left_left_case(self, node: Node) -> Node:
        return self.right_rotation(node)

    def right_left_case(self, node: Node) -> Node:
        node.right = self.right_rotation(node)
        return self.right_right_case(node)

    def right_right_case(self, node: Node) -> Node:
        return self.left_rotation(node)

    def right_rotation(self, A: Node) -> Node:
        B: Node = A.left
        A.left = B.right
        B.right = A

        self.update(A)
        self.update(B)

        return B

    def left_rotation(self, A: Node) -> Node:
        B: Node = A.right
        A.left = B.right
        B.left = A

        self.update(A)
        self.update(B)

        return B

    def remove(self, node: Node, data: int) -> typing.Optional[Node]:
        """
        cases:
            1. node to remove is a leaf node
            2. node to remove has only a right subtree - successor is the immediate child.
            3. node to remove has only a left subtree - successor is the immediate child.
            4. node to remove has both right and left subtree
                a. either find the largest value of the left subtree
                b. or find the smallest value of the right subtree

                - now we copy this node to the m_root reference -> this always result to case 1-3.
        """
        if node is None:
            return None
        elif data < node.data:
            node.left = self.remove(node.left, data)
        elif data > node.data:
            node.right = self.remove(node.right, data)
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
                ptr.right = self.remove(node.right, ptr.data)

        self.update(node)
        return self.balance(node)

    def find_min(self, node: Node) -> Node:
        while node.left is not None:
            node = node.left
        return node

    def is_empty(self) -> bool:
        return self.m_root == None
