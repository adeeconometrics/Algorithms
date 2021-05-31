package GenericStructures;

public class Queue<T> {
    private class Node{
        T data;
        Node next;
        Node(T data){
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

    public void enqueue(T data){
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
            // Node temp_node = this.front; // you can not use this?
            this.front = this.front.next;
            // temp_node = null; // you can not use this?
            
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

    public T front(){
        return this.front.data;
    }
    
    public T rear(){
        return this.rear.data;
    }

    public int size(){return this.size;}
}

class MainQueue{
    public static void main(String[] args){

    }
}