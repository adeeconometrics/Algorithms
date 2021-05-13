using System;

class Queue{
    public class Node{
        public int data;
        public Node next;
        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    Node front;
    Node rear;
    int _size;

    public Queue(){
        this.front = null;
        this.rear = null;
        this._size = 0;
    }

    public void enqueue(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.rear = node;
        }
        else{
            node.next = this.rear;
            this.rear = node;
        }
        ++ this._size;
    }

    public void dequeue(){
        if(is_empty()){
            Console.Write("Hello. Error, sir. ");
            return;
        }
        else{
            Node temp = this.front;
            this.front = this.front.next;

            temp = null;
            -- this._size;
        }
    }

    public void display(){
        Node ptr = this.rear;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }
    }

    public int size(){return this._size;}
    public int top(){return this.front.data; }
    public int bottom(){return this.rear.data; }
    
    public bool is_empty(){
        if(this.front == null && this._size == 0)
            return true;
        return false;
    }

}

class MainQueue{
    public static void Main(string[] args){
        Queue q = new Queue();
        for(int i = 0; i<10; ++i)
            q.enqueue(i);
        q.display();
        
        for(int i = 0; i<5; ++i)
            q.dequeue(); // problematic function
            
        q.display();
    }
}