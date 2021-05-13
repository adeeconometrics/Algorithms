using System;

class Stack{
    public class Node{
        public int data;
        public Node next;
        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    Node top;
    int _size;

    public Stack(){
        this.top = null;
        this._size = 0;
    }

    public void push(int data){
        Node node = new Node(data);
        node.next = this.top;
        this.top = node;
        ++ this._size;
    }

    public void pop(){
        if(is_empty()){
            //error
        }
        else
            this.top = this.top.next;
        -- this._size;
    }

    public void display(){
        Node ptr = this.top;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }

    }
    public int top_value(){
        return this.top.data;
    }

    public bool is_empty(){
        return this.top == null && this._size == 0;
    }

    public int size(){return this._size;}
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