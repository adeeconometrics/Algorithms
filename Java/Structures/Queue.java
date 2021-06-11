package Structures;

public class Queue {
    private class Node{
        int data;
        Node next = null;
        Node(int data){
            this.data = data;
        }
    }
    private Node front = null; 
    private Node rear = null;
    private int size;

    Queue(){
        this.size = 0;
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
        this.size += 1;
    }

    public void dequeue(){
        try {
            if(is_empty()) throw new Exception();
            Node temp_node = this.front; // you can not use this?
            this.front = this.front.next;
            temp_node = null; // you can not use this?
            
            this.size -= 1;
        } catch (Exception e) {
            System.out.print("Error. Queue is already empty.");
            return;
        }
    }

    public boolean is_empty(){ return this.size == 0 && this.front == null; }

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