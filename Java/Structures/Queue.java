package Structures;

public class Queue {
    private class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    private Node front, rear;
    private int size;

    Queue(){
        this.size = 0;
        this.front = null;
        this.rear = null;
    }

    public void enqueue(int data){
        Node node = new Node(data);

        if(is_empty()){
            this.front = node;
            this.rear = node;
        } else{
            node.next = this.rear;
            this.rear = node;
        }
        ++ this.size;
    }

    public void dequeue(){
        try {
            if(is_empty()) throw new Exception();
            Node temp_node = this.front;
            this.front = this.front.next;
            temp_node = null;
            
            -- this.size;
        } catch (Exception e) {
            System.out.print("Error. Queue is already empty.");
            return;
        }
    }

    public boolean is_empty(){
        if(size == 0 && this.front == null) return true;
        return false;
    }

    public int front(){
        return this.front.data;
    }
    
    public int rear(){
        return this.rear.data;
    }

    public int size(){return this.size;}
}

class MainQueue{
    public static void main(String[] args){

    }
}