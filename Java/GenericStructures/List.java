package GenericStructures;


public class List<T>{
    class Node{
        T data;
        Node prev, next;

        Node(T data){
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    Node head;

    public List(){
        this.head = null;
    }

    public void add(T data){
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

    public void remove(T data){
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
        return this.head == null;
    }

}

class MainList{
    public void main(String [] args){

    }
}