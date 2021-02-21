# pragma once
# include <iostream>

template<class T>

class Stack{
    private:
        int stackSize;
        int index = -1;
        T *stackArray;
        int _top;

    public:
        Stack(int size){
            index += 1;
            stackSize = size;
            stackArray = new T[size];
            _top = stackArray;
        }
        ~Stack(){
            delete []_top;
        }
        void push(T &data);
        void pop(int &num);
        T top();
        T* top_reference();
        bool isFull();
        bool isEmpty();
};

// implementation
template<class T>
void Stack::push<T>(T &data){
    if (isFull())
      std::cout << "stack is full";
    else {
      stackArray[_top] = data;

      std::cout << stackArray[_top];
      _top += 1;
    }
}

template<class T>
void Stack::pop<T>(int &num){
    if (isEmpty())
      std::cout << "stack is empty";
    else {
      T num = stackArray[_top];
      _top -= 1;
    }
}

template<class T>
T Stack::top<T>(){
   return stackArray[_top - 1];
}

template<class T>
T* Stack::top_reference<T>(){
    return stackArray + (_top - 1); 
}

template<class T>
bool Stack::isEmpty<T>(){
    if(index == -1) return true;
    else return false;
}

template<class T>
bool Stack::isFull<T>(){
    if(stackSize == index) return true;
    else return false;
}