package Structures;

public class List{
    class Node{
        int data;
        Node prev = null;
        Node next = null;

        Node(int data){ this.data = data;}
    }

    Node front = null;
    Node back = null;
    int size;

    public List(){
        this.size = 0;
    }

    public void add(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back  = node;
        }
        else{
            this.back.next = node;
            node.prev = this.back;
            back = node;
        }
        this.size += 1;
    }

    public void add_front(int data){
        Node node = new Node(data); 
        if(is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            node.next = this.front;
            this.front.prev = node;
            this.front = node;
        }
        this.size += 1;
    }

    public void add_back(int data){
        Node node = new Node(data);
        if(is_empty()){
            this.front = node;
            this.back  = node;
        }
        else{
            this.back.next = node;
            node.prev = this.back;
            back = node;
        }
        this.size += 1;
    }

    public void remove(int data){
        Node ptr = this.front;
        try {
            boolean is_element = false;

            while(ptr.next != null){
                if(ptr.data == data){
                    ptr.prev = ptr.prev.prev;
                    ptr.next = ptr.next.next;
                    is_element = true;
                    return;
                }
                ptr = ptr.next;
            }

            if(is_element == false) throw new Exception();

        } catch (Exception e) {
            System.out.println(String.valueOf(data) + " is not element of the list.");
            return;
        }
    }

    public void display(){
        Node ptr = this.front;
        
        while(ptr.next != null){
            System.out.print(String.valueOf(ptr.data) + " ");
            ptr = ptr.next;
        }
    }
    
    public int top(){return this.front.data; }
    
    public int bottom(){return this.back.data; }

    public boolean is_empty(){
        if(this.front ==  null) return true;
        return false;
    }

    public int size(){return this.size; }

}

class MainDoubly{
    public void main(String [] args){

    }
}