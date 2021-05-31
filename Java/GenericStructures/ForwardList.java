package GenericStructures;

public class ForwardList<T> {
        class Node{
        T data;
        Node next;
        Node(T data){
            this.data = data;
            next = null;
        }

        Node(){next = null;}
    }

    Node head;

    public ForwardList(){
        this.head = null;
    }

    public void add(T data){
        Node node = new Node();
        node.data = data;

        if(is_empty())
            this.head = node;
        else{
            Node ptr = this.head; // this works!
            while(ptr.next != null)
                ptr = ptr.next;
            
            ptr.next = node;
        }
    }

    public void remove(T data){
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
    public T head(){
        if(is_empty()) return null;
        return head.data;
    }

    public void display(){
        Node ptr = this.head;
        
        while(ptr.next != null){
            System.out.print(String.valueOf(ptr.data) + " ");
            ptr = ptr.next;
        }
    }

    boolean is_empty(){
        return this.head == null;
    }
}

class Main{
    public static void main(String [] args){
        ForwardList<Integer> list = new ForwardList<>();
        for(int i = 0; i<5; ++i)
            list.add(i);
        
        list.display();
    }
}