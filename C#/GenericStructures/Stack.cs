using System;

class Stack <T>{
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

    public Stack(){
        this.m_size = 0;
    }

    public void push(T data){
        Node node = new Node(data);
        if(is_empty()){
            this.back = node;
        }
        
        node.next = this.front;
        this.front = node;

        ++ this.m_size;
    }

    public void pop(){
        if(is_empty()){
            //error
        }
        else
            this.front = this.front.next;
        -- this.m_size;
    }

    public void display(){
        Node ptr = this.front;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }

    }
    public T top(){
        return this.front.data;
    }

    public T bottom(){
        return this.back.data;
    }

    public bool is_empty(){
        return this.front == null && this.m_size == 0;
    }

    public int size(){return this.m_size;}
}

public class MainStack{
    public static void Main(string[] args){
        Stack s = new Stack();
        
        for(int i = 0; i<10; ++i)
            s.push(i);
        
        s.display();
        Console.WriteLine("popped one value");

        s.pop();
        s.display();
    }
}