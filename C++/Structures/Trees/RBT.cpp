/**
 * @file RBT.cpp
 * @author ddamiana
 * @brief concrete implementation of Red-BlackTree in CPP.
 * @version 0.1
 * @date 2021-07-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <stdexcept>
/**
 * @brief When the tree is modified, new tree is re-arranged to obtain the
 * self-balancing property. Summary of worst-case operational complexity:
 * search := O(log n)
 * insert := O(log n)
 * remove := O(log n)
 * space := O(log n)
 *
 * Note that data should be comparable.
 */
class RedBlackTree {
  static const bool red = true;
  static const bool black = false;

  struct Node {
    Node *parent{nullptr};
    Node *left{nullptr};
    Node *right{nullptr};
    bool color = red;
    int value;

    Node(int i_value, Node *i_parent) : value(i_value), parent(i_parent) {}
    Node(bool i_color, int i_value) : color(i_color), value(i_value) {}
    Node(int i_value, bool i_color, Node *i_parent, Node *i_left, Node *i_right)
        : value(i_value), color(i_color) {
      if (parent == nullptr && left == nullptr && right == nullptr) {
        parent = this; // see if this is correct
        left = this;
        right = this;
      }

      parent = i_parent;
      left = i_left;
      right = i_right;
    }

    // helper function -- do you really need the getters?
    bool get_color() const { return color; }
    int get_value() const { return value; }
    Node *get_left() const { return left; }
    Node *get_right() const { return right; }
    Node *get_parent() const { return parent; }

    void set_value(int i_value) { value = i_value; }
    void set_color(bool i_color) { color = i_color; }
    void set_left(Node *i_left) { left = i_left; }
    void set_right(Node *i_right) { right = i_right; }
    void set_parent(Node *i_parent) { parent = i_parent; }
  };

  Node *m_root = nullptr;
  int node_count = 0;
  Node *NIL{nullptr};

public:
  RedBlackTree() {
    NIL = new Node(black, 0);
    // 0 temporarily represents a null value in nullable types
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NIL;

    m_root = NIL;
  }

  int size() const { return node_count; }

  bool is_empty() const { return node_count == 0; }

  bool is_element(int value) const {
    Node *node = m_root;

    if (node == nullptr || value == 0)
      return false;
    while (node != nullptr) {
      if (node->value > value)
        node = node->left;
      else if (node->value < value)
        node = node->right;
      else
        return true;
    }
    return false;
  }

  bool insert(int value = 0) {
    try {
      if (value == 0)
        throw std::exception();

      Node *x = m_root;
      Node *y = NIL;

      while (x != NIL) {
        y = x;

        if (x->value > value)
          x = x->left;
        else if (x->value < value)
          x = x->right;
        else
          return false;
      }

      Node *z = new Node(value, red, y, NIL, NIL);
      if (y == NIL)
        m_root = z;
      else if (z->value > y->value)
        y->left = z;
      else
        y->right = z;

      fix_insertion_at(z);
      node_count += 1;
      return true;

    } catch (std::exception &ia) {
      std::cerr << "invalid argument: RBT does not allow null values.";
      exit(1);
    }
  }

  bool remove(int value) {
    Node *z = nullptr;
    Node *y = nullptr;
    Node *x = nullptr;
    if (value == 0 || (z = (search(value, m_root))) == NIL)
      return false;

    bool y_original_color = y->color;
    if (z->get_left() == NIL) {
      x = z->get_right();
      transplant(z, z->get_right());
    } else if (z->get_right() == NIL) {
      x = z->get_left();
      transplant(z, z->get_left());
    } else {
      y = successor(z->get_right());
      y_original_color = y->get_color();
      x = y->get_right();

      if (y->get_parent() == z)
        x->set_parent(y);
      else {
        transplant(y, y->get_right());
        y->set_right(z->get_right());
        y->get_right()->set_parent(y);
      }
      transplant(z, y);

      y->set_left(z->get_left());
      y->get_right()->set_parent(y);
      y->set_color(z->get_color());
    }

    if (y_original_color == black)
      fix_delete(x);
    node_count -= 1;
    return true;
  }

  size_t height() { return height(m_root); }

private:
  // helper functions
  void fix_insertion_at(Node *node) {
    Node *y{nullptr};

    while (node->parent->color == red) {
      if (node->parent == node->parent->parent->left) {
        y = node->parent->parent->right;
        if (y->color == red) {
          node->parent->color = black;
          y->color = black;
          node->parent->parent->color = red;
          node = node->parent->parent;
        } else {
          if (node == node->parent->right) {
            node = node->parent;
            left_rotate(node); // define this later
          }
          node->parent->color = black;
          node->parent->color = red;
          right_rotate(node->parent->parent); // define this later
        }
      } else {
        y = node->parent->parent->left;
        if (y->color == red) {
          node->parent->color = black;
          y->color = black;
          node->parent->parent->color = red;
          node = node->parent->parent;
        } else {
          if (node == node->parent->left) {
            node = node->parent;
            right_rotate(node); // define
          }
          node->parent->color = black;
          node->parent->parent->color = red;
          left_rotate(node->parent->parent);
        }
      }
    }
    m_root->set_color(black);
    NIL->set_parent(nullptr);
  }

  void left_rotate(Node *node) {
    Node *y = node->right;
    node->set_right(y->get_left());

    if (y->get_left() != NIL)
      y->get_left()->set_parent(node);

    y->set_parent(node->get_parent());

    if (node->get_parent() == NIL)
      m_root = y;

    if (node == node->get_parent()->get_left())
      node->get_parent()->set_left(y);
    else
      node->get_parent()->set_right(y);

    y->set_left(node);
    node->set_parent(y);
  }

  void right_rotate(Node *node) {
    Node *x = node;
    node->left = x->right;

    if (x->right != NIL)
      x->right->parent = node;
    x->parent = node->parent;

    if (node->parent == NIL)
      m_root = x;
    if (node == node->parent->left)
      node->parent->left = x;
    else
      node->parent->right = x;
    x->right = node;
    node->parent = x;
  }

  void fix_delete(Node *x) {
    while (x != m_root && x->color == black) {
      if (x == x->parent->left) {
        Node *w = x->parent->right;
        if (w->color == red) {
          w->color = black;
          x->parent->color = red;
          left_rotate(x->parent);
          w = x->parent->right;
        }

        if (w->left->color == black && w->right->color == black) {
          w->color = red;
          x = x->parent;
          continue;
        } else if (w->right->color == black) {
          w->left->color = red;
          w->color = red;
          right_rotate(w);
          w = x->parent->right;
        }

        if (w->right->color == red) {
          w->color = x->parent->color;
          x->parent->color = black;
          w->right->color = black;
          left_rotate(x->parent);

          x = m_root;
        }
      } else {
        Node *w = x->parent->left;
        if (w->color == red) {
          w->color = black;
          x->parent->color = red;
          right_rotate(x->parent);
          w = x->parent->left;
        }

        if (w->right->color == black && w->left->color == black) {
          w->color = red;
          x = x->parent;
          continue;
        } else if (w->left->color == black) {
          w->right->color = black;
          w->color = red;
          left_rotate(w);
          w = x->parent->left;
        }

        if (w->left->color == red) {
          w->color = x->parent->color;
          x->parent->color = black;
          w->left->color = black;
          right_rotate(x->parent);
          x = m_root;
        }
      }
    }
    x->color = black;
  }

  Node *successor(Node *node) {
    if (node == NIL || node->left == NIL)
      return node;
    return successor(node->left);
  }

  void transplant(Node *u, Node *v) {
    if (u->parent == NIL)
      m_root = v;
    else if (u == u->parent->left)
      u->parent->left = v;
    else
      u->parent->right = v;

    v->parent = u->parent;
  }

  Node *search(int value, Node *node) {
    if (node == NIL)
      return NIL;
    else if (node->value == value)
      return node;
    else if (node->value < value)
      return search(value, node->right); // review this one.

    return search(value, node->left);
  }

  size_t height(Node *node) {
    if (node == NIL)
      return 0;

    if (node->left == NIL && node->right == NIL)
      return 1;

    return 1 + (height(node->left) > height(node->right)) ? height(node->left)
                                                          : height(node->right);
  }

  void swap_color(Node *a, Node *b) { std::swap(a->color, b->color); }

  void update_parent_child_link(Node *parent, Node *old_child,
                                Node *new_child) {
    if (parent != NIL) {
      if (parent->left == old_child)
        parent->left = new_child;
      else
        parent->right = new_child;
    }
  }

  Node *find_min(Node *node) const {
    while (node->left != NIL)
      node = node->left;
    return node;
  }

  Node *find_max(Node *node) const {
    while (node->right != NIL)
      node = node->right;
    return node;
  }
};