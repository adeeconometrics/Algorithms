using System;

class Deque{
    class Node{
        public int data;
        public Node next;
        public Node prev;
        public Node(int data){
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    Node front, back;
    int _size;

    public Deque(){
        this.front = null;
        this.back = null;
        this._size = 0;
    }

    public void push_back(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            this.back.next = node;
            node.prev = this.back;
            this.back = node;
        }
        ++ this._size;
    }

    public void push_front(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            node.next = this.front;
            node.prev = this.front.prev;
            this.front = node;
        }
        ++ this._size;
    }
    
    public void pop_back(){
        Node ptr = this.back;
        this.back = this.back.prev;
        Console.Write(ptr);
        ptr = null;
        -- this._size;
    }
    
    public void pop_front(){
        Node ptr = this.front;
        this.front = this.front.next;
        
        ptr = null;
        
        -- this._size;
    }
    
    public void display(){
        Node ptr = this.front;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }
    }
    
    public void display_reverse(){
        Node ptr = this.back;
        while(ptr.prev != null){
            ptr = ptr.prev;
            Console.Write(ptr.data + " ");
        }
    }
    
    public int size(){return this._size;}

    public bool is_empty(){
        return this.front == null && this._size == 0;
    }
}

class MainDeque{
    public static void Main(string [] args){
        Deque dq = new Deque();
        
        dq.push_back(1);
        dq.push_back(2);
        dq.push_back(3);
        dq.push_front(4); // findout the subtle priblem on this.
        
        for(int i = 0; i < 10; ++i)
                dq.push_back(i);
        
        dq.display();
        Console.WriteLine("\nreversed: ");
        dq.display_reverse();
    }
}