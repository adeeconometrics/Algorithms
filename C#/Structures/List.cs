using System;

class List{
    class Node{
        public int data;
        public Node prev = null; 
        public Node next = null;
        public Node(int data){
            this.data = data;
        }
    }

    private Node front = null;
    private Node back = null;

    int m_size;
    public List(){
        m_size = 0;
    }

    public void add(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            node.prev = this.back;
            this.back.next = node;
            this.back = node;    
        }
        this.m_size += 1;
    }

    public void add_front(int data){
        Node node = new Node(data);

        if(is_empty()){
            this.front = node;
            this.back = node;
        }else{
            node.next = this.front;
            this.front.prev = node;
            this.front = node;            
        }
        this.m_size += 1;
    }

    public void add_back(int data){
        Node node = new Node(data);

        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            node.prev = this.back;
            this.back.next = node;
            this.back = node;            
        }
        this.m_size += 1;
    }

    public void remove(int data){
        if(is_empty()){
            // error
        }else{
            Node ptr = this.front;

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

    public bool is_empty(){
        return this.front == null && this.m_size == 0;
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