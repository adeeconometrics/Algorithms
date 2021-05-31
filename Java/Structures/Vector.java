package Structures;

public class Vector {
    private int [] ptr_arr;
    private int _size;
    private int _counter;

    public Vector() {
        _size = 1;
        _counter = 0;
        ptr_arr = new int[_size];
    }

    public void add(int data){
        _counter += 1;
        if(_counter == _size) this.grow(); 
        ptr_arr[_counter] = data;
    }

    private void grow(){
        int [] temp = null;
        int size = _size * 2;
        temp = new int[size];

        for(int i : ptr_arr)
            temp[i] = ptr_arr[i];
        
        ptr_arr = temp;
        _size = size;
    }

    public void display(){
        for (int i : ptr_arr) 
            System.out.print(String.valueOf(ptr_arr[i]) + " ");
    }
}

class MainVector{
    public static void main(String [] args){

    }
}