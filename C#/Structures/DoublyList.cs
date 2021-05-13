using System;

class DoublyList{
    class Node{
        public int data;
        public Node prev, next;
        public Node(int data){
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    Node head;
    Node back;

    int _size;
    public DoublyList(){
        this.head = null;
        this.back = null;
        _size = 0;
    }

    public void add(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.head = node;
            this.back = node;
        }
        else{
            Node ptr = this.head;

            while(ptr.next != null)
                ptr = ptr.next;
            
            ptr.next = node; 
            node.prev = ptr;
            this.back = node;
        }
        ++ this._size;
    }

    public void remove(int data){
        if(is_empty()){
            // error
        }else{
            Node ptr = this.head;

            while(ptr.next != null){
                if(ptr.data == data){
                    ptr.prev = ptr.prev.prev;
                    ptr.next = ptr.next.next;
                    -- this._size;
                    return;
                }
                ptr = ptr.next;
            }
        }
    }

    public void display(){
        Node ptr = this.head;
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

    public bool is_empty(){
        return this.head == null && this._size == 0;
    }
}

class MainDoubly{
    public static void Main(string[] args){
        DoublyList dl = new DoublyList();
        for(int i = 0; i<10; ++i)
            dl.add(i);
        
        dl.display();
        Console.WriteLine("\nprints backwards");
        dl.display_reverse();
        
    }
}