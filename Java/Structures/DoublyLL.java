package Structures;

public class DoublyLL{
    class Node{
        int data;
        Node prev, next;

        Node(int data){
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    Node head;

    public DoublyLL(){
        this.head = null;
    }

    public void add(int data){
        Node node = new Node(data);
        if(is_empty()) 
            this.head = node;
        else{
            Node ptr = this.head;
            while(ptr.next != null)
                ptr = ptr.next;
            
            ptr.next = node;
            node.prev = ptr;
        }
    }

    public void remove(int data){
        Node ptr = this.head;

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
        Node ptr = this.head;
        
        while(ptr.next != null){
            System.out.print(String.valueOf(ptr.data) + " ");
            ptr = ptr.next;
        }
    }

    public boolean is_empty(){
        if(this.head ==  null) return true;
        return false;
    }

}

class MainDoubly{
    public void main(String [] args){

    }
}