using System;

class Vector<T>{
    T [] ptr = null;
    int m_size = 1; 
    int counter = 0;

    public Vector(int size){
        this.ptr = new T[size];
    }

    public Vector(){
        this.ptr  = new T[1];
    }
    
    public void add(T data){
        if(this.counter == this.m_size) grow();
        this.ptr[counter] = data;
        ++ this.counter;
    }

    public void display(){
        foreach(int i in this.ptr[])
            Console.Write(this.ptr[i] + " ");
    }
    
    private void grow(){
        int newm_size = this.m_size * 2;
        T [] temp = new T[newm_size];

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