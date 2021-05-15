class Node {
  Node? next;
  late int data;
  Node(int data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  Node? front;
  Node? back;
  late int size;

  Queue() {
    this.front = null;
    this.back = null;
    this.size = 0;
  }

  void enqueue(int data) {
    Node node = new Node(data);
    if (isEmpty()) {
      this.front = node;
      this.back = node;
    } else {
      this.back?.next = node;
      this.back = this.back?.next;
    }
    ++this.size;
  }

  void dequeue() {
    // handle error
    this.front = this.front?.next;
    --this.size;
  }

  void display() {
    Node? ptr = this.front;
    while (ptr?.next != null) {
      print("${ptr?.data} ");
      ptr = ptr?.next;
    }
  }

  bool isEmpty() {
    return this.front == null && this.size == 0;
  }

  int queueSize() {
    return this.size;
  }
}

void main() {
  var q = new Queue();
  for (int i = 0; i < 10; ++i) q.enqueue(i);
  q.display();
  print("dequeued");
  for (int i = 0; i < 5; ++i) q.dequeue();
  q.display();
}
