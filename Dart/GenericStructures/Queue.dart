class Node<T> {
  Node? next;
  late T data;
  Node(T data) {
    this.data = data;
    this.next = null;
  }
}

class Queue<T> {
  Node? front = null;
  Node? back = null;
  int size = 0;

  Queue() {}

  void enqueue(T data) {
    Node node = new Node<T>(data);
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
  var q = new Queue<int>();
  for (int i = 0; i < 10; ++i) q.enqueue(i);
  q.display();
  print("dequeued");
  for (int i = 0; i < 5; ++i) q.dequeue();
  q.display();
}
