class Node {
  int data = 0;
  Node? next = null;

  Node(int data) {
    this.data = data;
  }
}

class SinglyList {
  Node? front = null;
  Node? back = null;
  int size = 0;

  SinglyList() {}

  void add(int data) {
    Node node = new Node(data);
    if (isEmpty()) {
      this.front = node;
      this.back = node;
    } else {
      this.back?.next = node;
      this.back = node;
    }
    ++this.size;
  }

  void remove(int data) {
    Node? ptr = this.front;
    Node? prev = ptr;

    while (ptr?.next != null) {
      if (ptr?.data == data) {
        prev?.next = ptr?.next;
        --this.size;
        return;
      }
      prev = ptr;
      ptr = ptr?.next;
    }
  }

  void display() {
    Node? ptr = this.front;
    while (ptr?.next != null) {
      print("${ptr?.data} ");
      ptr = ptr?.next;
    }
  }

  bool isEmpty() {
    return this.front == null;
  }
}

void main() {
  var l = new SinglyList();
  for (int i = 0; i < 10; ++i) l.add(i);

  l.display();
  l.remove(5);
  print("5 is removed.");
  l.display();
}
