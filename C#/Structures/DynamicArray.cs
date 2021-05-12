using System;

class Array{
    int [] ptr = null;
    int _size; 
    int counter;

    public Array(int size){
        this._size  = size;
        this.ptr = new int[size];
        this.counter = 0;
    }

    public Array(){
        this._size = 1;
        this.ptr  = new int[1];
        this.counter = 0;
    }
    
    public void add(int data){
        if(this.counter == this._size) grow();
        this.ptr[counter] = data;
        ++ this.counter;
    }

    public void display(){
        foreach(int i in this.ptr)
            Console.Write(ptr[i] + " ");
    }
    
    private void grow(){
        int new_size = this._size * 2;
        int [] temp = new int[new_size];

        for(int i = 0; i < this._size; ++i)
            temp[i] = this.ptr[i];
        
        this.ptr = temp;
        this._size = new_size;
    }
}

class MainArray{
    public static void Main(string [] args){
        Array a = new Array();
        for(int i = 0; i<10; ++i)
            a.add(i);
        a.display();
    }
}