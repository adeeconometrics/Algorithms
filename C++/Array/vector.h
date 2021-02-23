// vector class
# pragma once
# ifndef _VECTOR_H
# define  _VECTOR_H
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

        void sort(){
            // if the type sortable?
            if(std::is_integral<T>::value || 
            std::is_floating_point<T>::value || 
            std::is_same<T, std::string>::value){
                // sort
            }
            else{
                std::cout<<"type is not sortable.";
            }
        }

        void fit();
        void push_front(T &data);
        void pop_front();
        void push_back(T &data);
        void pop_back();
             
        bool isFull();
        bool isEmpty(){
            if(index == -1) return true;
            else return false;
        }
};

# endif