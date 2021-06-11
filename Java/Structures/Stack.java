package Structures;

public class Stack {
    private class Node{
        int data; 
        Node next = null;
        Node(int data){
            this.data = data;
        }
    }
    
    private int size;
    private Node top = null;
    // private Node bottom = null; -- implement this 

    public Stack(){
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

    public int top(){
        return this.top.data;
    }
}

class MainStack{
    public static void main(String[] args){

    }
}