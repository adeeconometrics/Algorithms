package Structures;

public class LinkedList{
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            next = null;
        }

        Node(){next = null;}
    }

    Node head;

    public LinkedList(){}

    public void add(int data){
        Node node = new Node();
        node.data = data;

        if(this.head == null)
            this.head = node;
        else{
            Node ptr = this.head; // this works!
            while(ptr.next != null)
                ptr = ptr.next;
            
            ptr.next = node;
        }
    }

    public void remove(int data){
        Node node = new Node();
        node.data = data;

        try {
            boolean is_element = false;
            Node ptr = this.head;
            Node prev = ptr;
            while(ptr.next != null){
                if(ptr.data == data){
                    is_element = true;
                    prev.next = ptr.next;
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
        Node node = this.head;
        this.head = node.next;
        node = null; // released
    }
    public void remove_last(){
        Node ptr = this.head;
        while(ptr.next != null)
            ptr = ptr.next;

        ptr = null;
    }

    public void display(){
        Node ptr = this.head;
        
        while(ptr.next != null){
            System.out.print(String.valueOf(ptr.data) + " ");
            ptr = ptr.next;
        }
    }

}

class Main{
    public static void main(String [] args){
        LinkedList list = new LinkedList();
        for(int i = 0; i<5; ++i)
            list.add(i);
        
        list.display();
    }
}