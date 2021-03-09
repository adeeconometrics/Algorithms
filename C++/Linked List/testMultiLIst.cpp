// creates a multi-level linked list
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Todo:
 *    - function that automatically loads everything from the struct
 */
template <typename T> class List {
private:
  struct SubNode {
    std::string n_string; // string representation for implicit type conversion
    T subnode_value;
    SubNode *next;

    SubNode(T _subnode_value, SubNode *ptr = NULL)
        : subnode_value(_subnode_value), ptr(next) {}
    operator const char *() {
      std::ostringstream n_str;
      // load components of the node in the string
      // connversion
      // return converted n_string
    }
  };

  struct Node {
    T node_value;
    Node *next;
    struct SubNode *head_subnode;

    Node(T _node_value, SubNode *_head_subnode = NULL, Node *_next = NULL) {
      node_value = _node_value;
      next = _next;
      head_subnode = _head_subnode;
    }
  };

  Node *head;
  int counter;

public:
  explicit List() { head = NULL; }
  ~List() { clear(); }

  void addNode(T &node) {
    Node *node_ptr = new Node(node);
    if (isEmpty())
      head = node_ptr;
    else {
      Node *ptr;
      while (ptr->next != NULL)
        ptr = ptr->next;
      ptr->next = node_ptr;
    }
  }

  void addSubNode(T &n, T &value) {
    Node *node_ptr = head; // case where there is no n in the node, add n
    if (node_ptr->head_subnode == NULL)
      node_ptr->head_subnode = new SubNode(value);
    else {
      SubNode *subnode_ptr = node_ptr->head_subnode;

      while (subnode_ptr->next != NULL)
        subnode_ptr = subnode_ptr->next;
      subnode_ptr->next = new SubNode(value);
    }
  }

  void removeNode(T &value) {
    if (isEmpty()) {
      std::cout << "list is empty" << std::endl;
      return;
    }
    Node *node_ptr, *node_ptr_prev;
    SubNode *subnode_ptr, *s_temp;

    node_ptr = head;
    // find the value
    bool found = false;
    while (node_ptr->next != NULL) {
      if (node_ptr->value == value)
        found = true;
      node_ptr = node_ptr->next;
    }

    if (found) {
      while (node_ptr->next != NULL && node_ptr->value != value) {
        node_ptr_prev = node_ptr;
        node_ptr = node_ptr->next;
      }
      Node *temp = node_ptr;
      node_ptr = node_ptr->next;
      // clear subnodes first
      subnode_ptr = temp->head_subnode;
      while (subnode_ptr->next != NULL) {
        s_temp = subnode_ptr;
        subnode_ptr = subnode_ptr->next;
        delete s_temp;
      }
      delete subnode_ptr;
      delete node_ptr;
    } else {
      std::cout << "value is not found" << std::endl;
      return;
    }
  }

  void removeSubNode();
  void clear();
  void clearSubNode();

  bool isEmpty() {
    if (head == NULL)
      return true;
    return false;
  }
};