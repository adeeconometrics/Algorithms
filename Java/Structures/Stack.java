package Structures;

public class Stack {
    private int size;
    private class Node{
        int data; 
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    Node top;
    public Stack(){
        this.top = null;
        this.size = 0;
    }

    public void push(int data){
        Node node = new Node(data);
        node.next = this.top;
        this.top = node;
        ++ this.size;
    }

    public void pop(){
        try {
            if(this.size == 0) throw new Exception();
            this.top = top.next;
            -- this.size;

        } catch (Exception e) {
            System.out.println("Error: Stack is empty.");
            return;
        }
    }
    
    public int size(){
        return this.size;
    }
}

class MainStack{
    public static void main(String[] args){

    }
}