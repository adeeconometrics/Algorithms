package GenericStructures;

public class Vector <T>{
    private T [] ptr_arr;
    private int _size;
    private int _counter;

    public Vector() {
        _size = 1;
        _counter = 0;
        ptr_arr = (T[]) new Object[this._size];
    }

    public void add(T data){
        _counter += 1;
        if(_counter == _size) this.grow(); 
        ptr_arr[_counter] = data;
    }

    private void grow(){
        T [] temp = null;
        int size = _size * 2;
        temp = (T[]) new Object[this._size];

        for(int i = 0; i < this._size; ++i)
            temp[i] = ptr_arr[i];
        
        ptr_arr = temp;
        _size = size;
    }

    public void display(){
        for(int i = 0; i < this._size; ++i)
            System.out.print(String.valueOf(ptr_arr[i]) + " ");
    }
}

class MainVector{
    public static void main(String [] args){

    }
}