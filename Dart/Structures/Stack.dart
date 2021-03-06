class Node {
  Node? next = null;
  late int data;
  Node(int data) {
    this.data = data;
  }
}

class Stack {
  Node? head = null;
  int size = 0;

  Stack() {}

  void push(int data) {
    Node node = new Node(data);
    if (isEmpty())
      this.head = node;
    else {
      node.next = this.head;
      this.head = node;
    }
    ++this.size;
  }

  void pop() {
    this.head = this.head?.next;
    --this.size;
  }

  void display() {
    Node? ptr = this.head;
    while (ptr?.next != null) {
      print("${ptr?.data} ");
      ptr = ptr?.next;
    }
  }

  int stackSize() {
    return this.size;
  }

  bool isEmpty() {
    return this.head == null;
  }
}

void main() {
  var s = new Stack();
  for (int i = 0; i < 10; ++i) {
    s.push(i);
  }
  s.display();
  s.pop();
  print("popped");
  s.display();
}
