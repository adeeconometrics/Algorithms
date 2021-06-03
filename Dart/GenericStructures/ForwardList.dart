class Node<T> {
  late T data;
  Node? next = null;

  Node(T data) {
    this.data = data;
  }
}

class SinglyList<T> {
  Node? head = null;
  late int size = 0;

  SinglyList() {}

  void add(T data) {
    Node node = new Node<T>(data);
    if (isEmpty()) {
      this.head = node;
      ++this.size;
    } else {
      Node? ptr = this.head;
      while (ptr?.next != null) ptr = ptr?.next;

      ptr?.next = node;
      ++this.size;
    }
  }

  void remove(T data) {
    Node? ptr = this.head;
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
    Node? ptr = this.head;
    while (ptr?.next != null) {
      print("${ptr?.data} ");
      ptr = ptr?.next;
    }
  }

  bool isEmpty() {
    return this.head == null;
  }
}

void main() {
  var l = new SinglyList<int>();
  for (int i = 0; i < 10; ++i) l.add(i);

  l.display();
  l.remove(5);
  print("5 is removed.");
  l.display();
}
