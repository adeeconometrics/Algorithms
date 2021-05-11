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
        this.rear = front;
    }

    public void enqueue(int data){
        
    }
    public void dequeue(){}

}

class MainQueue{
    public static void main(String[] args){

    }
}