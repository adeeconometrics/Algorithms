using System;

class Queue<T>{
    public class Node{
        public T data;
        public Node next = null;
        public Node(T data){
            this.data = data;
        }
    }

    private Node front = null;
    private Node back = null;
    private int m_size;

    public Queue(){
        this.m_size = 0;
    }

    public void enqueue(T data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            node.next = this.back;
            this.back = node;
        }
        this.m_size += 1;
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
            this.m_size -= 1;
        }
    }

    public void display(){
        Node ptr = this.back;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }
    }

    public int size(){return this.m_size;}
    public T top(){return this.front.data; }
    public T bottom(){return this.back.data; }
    
    public bool is_empty(){
        if(this.front == null && this.m_size == 0)
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