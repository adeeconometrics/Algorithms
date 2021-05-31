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

    Node front, back;
    int size = 0;

    public List(){
        this.front = null;
        this.back = null;
    }

    public void add(T data){
        Node node = new Node(data);
        if(is_empty()){ 
            this.front = node;
            this.back = node;
        }
        else{
            Node ptr = this.front;
            while(ptr.next != null)
                ptr = ptr.next;
            
            ptr.next = node;
            node.prev = ptr;
        }
        this.size += 1;
    }

    public void remove(T data){
        Node ptr = this.front;

        try {
            boolean is_element = false;

            while(ptr.next != null){
                if(ptr.data == data){
                    ptr.prev = ptr.prev.prev;
                    ptr.next = ptr.next.next;
                    is_element = true;
                    this.size -=1;

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

    public void add_front(T data){
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

    public void add_back(T data){
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
        this.size += 1;
    }    

    public void remove_front(){
        if(is_empty()) return;
        this.front = this.front.next;
        this.size -=1;
    }

    public void remove_back(){
        if(is_empty()) return;
        this.back = this.back.prev;
        this.size -=1;
    }

    public void display(){
        Node ptr = this.front;
        
        while(ptr.next != null){
            System.out.print(String.valueOf(ptr.data) + " ");
            ptr = ptr.next;
        }
    }

    public T top(){
        if(is_empty()) return null;
        return this.front.data;
    }

    public T bottom(){
        if(is_empty()) return null;
        return this.back.data;
    }

    public int size(){return this.size;}

    public boolean is_empty(){
        return this.front == null;
    }

}

class MainList{
    public void main(String [] args){

    }
}