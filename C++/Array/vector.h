// vector class
# pragma once

template <class T>
class Vector{
    private:
        int size;
        T *typeof;
        int index = -1;

    public:
        Vector(int length){
            size = length;
            index = 0;
            typeof = new T[size];
        }

        void add(T &data){
            typeof[index] = data;
            ++index;
        }
        
        bool isEmpty(){
            if(index == -1) return true;
            else return false;
        }
}