# Data Structure variations to be implemented

- Binary Tree
- Binary Search Tree
- AVL
- General Tree 
- B-Tree
- Treap


---

Tree iterator implementation techniques:
1. **Navigation** - add parent pointer to each node and use three pointers to navigate around the tree
2. **Threading** - use the `n+1` null pointers in a tree to store "next node" or "previous node" information when it cannot be computed by descending in the tree
3. **ADT Control** - use Stack or Queue to keep track of where an iterator in a tree
4. **Graph Algorithms** - Use a standard Graph Depth-First Iterator or Breadth-First Iterator, applied specifically to the tree considered as a directed graph.

Notes:
- tree iterators are significantly more complex than list iterators. 
- `begin, next, end` are basic iterator actions and essentially define a linear progression from begining to end. 

---
Interfaces: 
- Navigator interface - a tree navigation that follows tree seamntics `up, down-left, down-right` as opposed to list semantics `prev, next`. Navigators also have a test methods `has_parent(), hast_child()` that enable navigation through a tree.