using System;

class ForwardList{
    public class Node{
        public int data;
        public Node next;
        public Node(int data){
            this.data  = data;
            this.next = null;
        }
    }

    Node head;
    int m_size;

    public ForwardList(){
        head = null;
        m_size = 0;
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

        ++ this.m_size;
    }

    public void add_front(int data){
        Node node = new Node(data);
        node.next = this.front;
        this.front = node;

        ++this.m_size;
    }

    public void add_back(int data){
        Node node = new Node(data);
        node.next = this.back;
        this.back = node;

        ++this.m_size;
    }

    public void remove(int data){
        try{
            if(is_empty()) throw System.Exception;

            if(data == this.front.data) remove_front();

            Node ptr = this.front;
            Node prev = ptr;
            
            while(ptr.next != null){
                if(ptr.data == data){
                    if(ptr.data == this.back.data) {
                        remove_back(prev);
                        return;
                    }

                    prev.next = ptr.next;
                    return;
                }
                prev = ptr;
                ptr = ptr.next;
            }
            -- this.m_size;

        }catch (System.Exception){
            throw; // handle exception
        }
    }

    private void remove_front(){
        Node temp = this.front;
        this.front = this.front.next; 
        temp = null;
        -- this.m_size;
    }

    private void remove_back(Node prev){
        Node temp = this.back;
        this.back = prev;
        temp = null;

        -- this.m_size;
    }
    
    public void display(){
        Node ptr = this.head;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }
    }
    
    bool is_empty(){return this.head == null;}

    public int size(){return this.m_size;}
}

class MainList{
    public static void Main(string [] args){
        ForwardList list = new ForwardList();

        for(int i = 0; i<10; ++i)
            list.add(i);
            
        list.remove(2);
        list.display();
    }
}