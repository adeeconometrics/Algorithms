package Structures;

public class ForwardList{
    class Node{
        int data;
        Node next = null;
        Node(int data){
            this.data = data;
        }

        Node(){}
    }

    private Node front = null;
    private Node back = null;
    private int size = 0;

    public ForwardList(){
        this.size = 0;
    }

    public void add(int data){
        Node node = new Node(data);

        if(this.is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            this.back.next = node;
            back = node;
        }
        this.size += 1;
    }

    public void add_front(int data){
        Node node = new Node(data);

        if(this.is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            node.next = this.front;
            this.front = node;
        }
        this.size += 1;
    }

    public void add_back(int data){
        Node node = new Node(data);

        if(this.is_empty()){
            this.front = node;
            this.back = node;
        }
        else{
            this.back.next = node;
            back = node;
        }
        this.size += 1;
    }

    public void remove(int data){
        Node node = new Node();
        node.data = data;

        try {
            boolean is_element = false;
            Node ptr = this.front;
            Node prev = ptr;
            while(ptr.next != null){
                if(ptr.data == data){
                    is_element = true;
                    prev.next = ptr.next;
                    this.size -= 1;
                    return;
                }
                prev = ptr;
                ptr = ptr.next;
            }

            if(is_element == false) throw new Exception();

        } catch (Exception e) {
            System.out.print(String.valueOf(data) + " is not an element of the list.");
        }
    }

    public void remove_first(){
        Node node = this.front;
        this.front = node.next;
        node = null;

        this.size -= 1;
    }
    public void remove_last(){
        Node ptr = this.front;
        while(ptr.next != null)
            ptr = ptr.next;

        ptr = null;

        this.size -= 1;
    }

    public void display(){
        Node ptr = this.front;
        
        while(ptr.next != null){
            System.out.print(String.valueOf(ptr.data) + " ");
            ptr = ptr.next;
        }
    }

    public int size(){return this.size; }

    public boolean is_empty(){return this.front == null && this.back == null; }

}

class Main{
    public static void main(String [] args){
        ForwardList list = new ForwardList();
        for(int i = 0; i<5; ++i)
            list.add(i);
        
        list.display();
    }
}