using System;

class List<T>{
    class Node{
        public T data;
        public Node prev = null 
        public Node next = null;
        public Node(T data){
            this.data = data;
        }
    }

    Node head = null;
    Node back = null;

    int m_size;
    public List(){
        m_size = 0;
    }

    public void add(T data){
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
        ++ this.m_size;
    }

    public void add_front(T data){
        Node node = new Node(data);
        node.next = this.front;
        this.front.prev = node;
        this.front = node;
        
        ++this.m_size;
    }

    public void add_back(T data){
        Node node = new Node(data);
        node.prev = this.back;
        this.back.next = node;
        this.back = node;
        
        ++this.m_size;
    }

    public void remove(T data){
        if(is_empty()){
            // error
        }else{
            Node ptr = this.head;

            while(ptr.next != null){
                if(ptr.data == data){
                    ptr.prev = ptr.prev.prev;
                    ptr.next = ptr.next.next;
                    -- this.m_size;
                    return;
                }
                ptr = ptr.next;
            }
        }
    }

    private void remove_front(){
        try{
            if(is_empty()) throw System.Exception;
            Node temp = this.front; 
            this.front = front.next;
            temp = null;
        }
        catch (System.Exception){
            throw; // handle exception
        }
    }

    private void remove_back(){
        try{
            if(is_empty()) throw System.Exception;
            Node temp = this.back; 
            this.back = front.prev;
            temp = null;
        }
        catch (System.Exception){
            throw; // handle exception
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
        return this.head == null && this.m_size == 0;
    }
}

class MainDoubly{
    public static void Main(string[] args){
        List dl = new List();
        for(int i = 0; i<10; ++i)
            dl.add(i);
        
        dl.display();
        Console.WriteLine("\nprints backwards");
        dl.display_reverse();
        
    }
}