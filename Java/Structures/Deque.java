package Structures;

public class Deque {
    private class Node{
        int data;
        Node next = null;
        Node prev = null;
        Node(int data){
            this.data = data;
        }
    }

    private Node front = null;
    private Node rear = null;
    private int size;

    public Deque(){
        this.size = 0;
    }

    public void enqueue(int data){
        Node node = new Node(data);

        if(is_empty()){
            this.front = node;
            this.rear = node;
        } else{
            Node temp_node = this.rear;
            this.rear.next = node;
            this.rear = this.rear.next;
            this.rear.prev = temp_node;
        }
        this.size += 1;
    }
    
    public void dequeue(){
        try {
            if(is_empty()) throw new Exception();

            Node temp_node = this.front;
            this.front = this.front.next;
            temp_node = null;

            this.size -= 1;
        } catch (Exception e) {
            System.out.println("Error: Deque is already empty.");
            return;
        }
    }

    public void push_back(int data){
        Node node = new Node(data);

        if(is_empty()){
            this.front = node;
            this.rear = node;
        } else{
            this.rear.next = node;
            this.rear = this.rear.next;
        }
        this.size += 1;
    }

    public void push_front(int data){
        Node node = new Node(data);

        if(is_empty()){
            this.front = node;
            this.rear = node;
        } else{
            node.next = this.front;
            node.prev = this.front.prev;
            this.front = node;
        }
        this.size += 1;
    }

    public void pop_back(){
        try {
            if(is_empty()) throw new Exception();

            Node temp_node = this.front;
            this.front = this.front.next;
            temp_node = null;

            this.size -= 1;
        } catch (Exception e) {
            System.out.println("Error: Deque is already empty.");
            return;
        }
    }

    public void pop_front(){
        try {
            if(is_empty()) throw new Exception();

            this.front = this.front.next;
            this.size -= 1;

        } catch (Exception e) {
            System.out.println("Error: Deque is empty.");
            return;
        }
    }

    public int front(){
        return this.front.data;
    }

    public int rear(){
        return this.rear.data;
    }
    
    public int size(){
        return this.size;
    }

    public boolean is_empty(){
        return this.front == null && this.size == 0;
    }
}

class MainDeque{
    public static void main(String [] args){

    }
}