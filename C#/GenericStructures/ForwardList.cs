using System;

class ForwardList <T> where T : IComparable<T>{
    public class Node{
        public T data;
        public Node next = null;
        public Node(T data){
            this.data  = data;
        }
    }

    Node front = null;
    Node back = null;

    int m_size;

    public ForwardList(){
        this.m_size = 0;
    }

    public void add(T data){
        Node node  = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            this.back.next = node;
            this.back = node;
        }

        ++ this.m_size;
    }

    public void add_front(T data){
        Node node = new Node(data);
        if (is_empty()){
            this.front = node;
            this.back = node;
        }else{
            node.next = this.front;
            this.front = node;            
        }


        this.m_size += 1;
    }

    public void add_back(T data){
        Node node = new Node(data);
        if (is_empty()){
            this.front = node;
            this.back = node;
        }else{
            node.next = this.back;
            this.back = node;
        }

        this.m_size += 1;
    }

    public void remove(T data){
        try{
            // if(is_empty()) throw System.Exception;

            if(data.CompareTo(this.front.data) == 0) remove_front();

            Node ptr = this.front;
            Node prev = ptr;
            
            while(ptr.next != null){
                if(ptr.data.CompareTo(data) == 0){
                    if(ptr.data.CompareTo(this.back.data) == 0) {
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
        if(is_empty()) return; // improve with exception handling
        Node temp = this.front;
        this.front = this.front.next; 
        temp = null;
        -- this.m_size;
    }

    private void remove_back(Node prev){
        if(is_empty()) return; // improve with exception handling
        Node temp = this.back;
        this.back = prev;
        temp = null;

        -- this.m_size;
    }
    
    public void display(){
        Node ptr = this.front;
        while(ptr.next != null){
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        }
    }
    
    public bool is_empty(){return this.front == null;}

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