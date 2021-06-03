class Node<T> {
  Node? next;
  Node? prev;
  late T data;
  Node(T data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }
}

class Deque<T> {
  Node? front;
  Node? back;
  int size = 0;
  Deque() {
    this.front = null;
    this.back = null;
  }

  void pushBack(T data) {
    Node node = new Node<T>(data);
    if (isEmpty()) {
      this.front = node;
      this.back = node;
    } else {
      this.back?.next = node;
      node.prev = this.back;
      this.back = node;
    }
    ++this.size;
  }

  void pushFront(T data) {
    Node node = new Node<T>(data);
    if (isEmpty()) {
      this.front = node;
      this.back = node;
    } else {
      this.front?.next = node;
      node.prev = this.front;
      this.front = node;
    }
    ++this.size;
  }

  void popBack() {
    // insert error handler if empty
    this.back = this.back?.prev;
    --this.size;
  }

  void popFront() {
    // insert error handler if empty
    this.front = this.front?.prev;
    --this.size;
  }

  void display() {
    Node? ptr = this.front;
    while (ptr?.next != null) {
      print("${ptr?.data}");
      ptr = ptr?.next;
    }
  }

  void displayReverse() {}

  bool isEmpty() {
    return this.front == null && this.size == 0;
  }

  int sizeList() {
    return this.size;
  }
}
