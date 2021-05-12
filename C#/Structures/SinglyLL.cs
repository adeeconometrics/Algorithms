using System;

class LinkedList{
    public class Node{
        public int data;
        public Node next;
        public Node(int data){
            this.data  = data;
            this.next = null;
        }
    }

    Node head;
    int size;

    public LinkedList(){
        head = null;
        size = 0;
    }

    public void add(int data){
        Node node  = new Node(data);
        if(is_empty()){
            this.head = node;
        }
        else{
            Node ptr = this.head;
            while(ptr.next != null)
                ptr = ptr.next;
            
            ptr.next = node;
        }

        ++ this.size;
    }

    public void remove(int data){
        Node ptr = this.head;
        Node prev = ptr;
        
        while(ptr.next != null){
            if(ptr.data == data){
                prev.next = ptr.next;
                return;
            }
            prev = ptr;
            ptr = ptr.next;
        }
        -- this.size;
    }

    public void display(){
        Node ptr = this.head;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }
    }
    
    bool is_empty(){return this.head == null;}

    public int _size(){return this.size;}
}

class MainList{
    public static void Main(string [] args){
        LinkedList list = new LinkedList();

        for(int i = 0; i<10; ++i)
            list.add(i);
            
        list.remove(2);
        list.display();
    }
}