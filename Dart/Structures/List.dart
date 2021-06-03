class Node {
  Node? next = null;
  Node? prev = null;
  late int data;
  Node(int data) {
    this.data = data;
  }
}

class DoublyList {
  Node? front = null;
  Node? back = null;
  int size = 0;

  DoublyList() {}

  void add(int data) {
    Node node = new Node(data);

    if (isEmpty()) {
      this.front = node;
      this.back = node;
    } else {
      Node? ptr = this.front;
      while (ptr?.next != null) ptr = ptr?.next;

      ptr?.next = node;
      node.prev = ptr;
    }
    ++this.size;
  }

  void remove(int data) {
    Node? ptr = this.front;
    Node? prev = ptr;
    while (ptr?.next != null) {
      if (ptr?.data == data) {
        prev?.next = ptr?.next;
        ptr?.prev = prev;
        --this.size;
        return;
      }
      prev = ptr;
      ptr = ptr?.next;
    }
    print("${data} is not found in the list.");
  }

  void display() {
    Node? ptr = this.front;
    while (ptr?.next != null) {
      print("${ptr?.data}");
      ptr = ptr?.next;
    }
  }

  void displayReverse() {
    // has problems
    Node? ptr = this.back;
    while (ptr?.next != null) {
      print("${ptr?.data}");
      ptr = ptr?.prev;
    }
  }

  bool isEmpty() {
    return this.front == null && this.size == 0;
  }

  int sizeList() {
    return this.size;
  }

  int top() {
    // has problem
    return this.front!.data;
  }

  int bottom() {
    // has problem
    return this.back!.data;
  }
}

void main() {
  var dl = new DoublyList();
  for (int i = 0; i < 10; ++i) dl.add(i);

  print("font: ${dl.top()}, back: ${dl.bottom()}");
  dl.display();
  dl.remove(3);
  print("removed 3");
  dl.display();
  print("font: ${dl.top()}, back: ${dl.bottom()}");
  dl.displayReverse();
  print("executed");
}
