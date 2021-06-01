using System;

class Vector{
    int [] ptr = null;
    int m_size; 
    int counter;

    public Vector(int size){
        this.m_size  = size;
        this.ptr = new int[size];
        this.counter = 0;
    }

    public Vector(){
        this.m_size = 1;
        this.ptr  = new int[1];
        this.counter = 0;
    }
    
    public void add(int data){
        if(this.counter == this.m_size) grow();
        this.ptr[counter] = data;
        ++ this.counter;
    }

    public void display(){
        foreach(int i in this.ptr)
            Console.Write(ptr[i] + " ");
    }
    
    private void grow(){
        int newm_size = this.m_size * 2;
        int [] temp = new int[newm_size];

        for(int i = 0; i < this.m_size; ++i)
            temp[i] = this.ptr[i];
        
        this.ptr = temp;
        this.m_size = newm_size;
    }
}

class MainVector{
    public static void Main(string [] args){
        Vector a = new Vector();
        for(int i = 0; i<10; ++i)
            a.add(i);
        a.display();
    }
}