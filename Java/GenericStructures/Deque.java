package GenericStructures;

public class Deque<T> {
  private class Node {
    T data;
    Node next, prev;
    Node(T data) {
      this.data = data;
      this.next = null;
      this.prev = null;
    }
  }

  Node front, rear;
  int size;

  public Deque() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  public void enqueue(T data) {
    Node node = new Node(data);

    if (is_empty()) {
      this.front = node;
      this.rear = node;
    } else {
      Node temp_node = this.rear;
      this.rear.next = node;
      this.rear = this.rear.next;
      this.rear.prev = temp_node;
    }
    ++this.size;
  }

  public void dequeue() {
    try {
      if (is_empty()) throw new Exception();

      this.front = this.front.next;
      --this.size;
    } catch (Exception e) {
      System.out.println("Error: Deque is already empty.");
      return;
    }
  }

  public void push_back(T data) {
    Node node = new Node(data);

    if (is_empty()) {
      this.front = node;
      this.rear = node;
    } else {
      this.rear.next = node;
      this.rear = this.rear.next;
    }
    ++this.size;
  }

  public void push_front(T data) {
    Node node = new Node(data);

    if (is_empty()) {
      this.front = node;
      this.rear = node;
    } else {
      node.next = this.front;
      node.prev = this.front.prev;
      this.front = node;
    }
    ++this.size;
  }

  public void pop_back() {
    try {
      if (is_empty()) throw new Exception();

      this.front = this.front.next;
      --this.size;
    } catch (Exception e) {
      System.out.println("Error: Deque is already empty.");
      return;
    }
  }

  public void pop_front() {
    try {
      if (is_empty())
        throw new Exception();

      this.front = this.front.next;
      --this.size;

    } catch (Exception e) {
      System.out.println("Error: Deque is empty.");
      return;
    }
  }

  public T front() { 
    if(is_empty()) return null;
    return this.front.data; 
  }

  public T rear() { 
    if(is_empty()) return null;
    return this.rear.data; 
  }

  public int size() { return this.size; }

  public boolean is_empty() { return this.front == null && this.size == 0; }
}

class MainDeque {
  public static void main(String[] args) {}
}