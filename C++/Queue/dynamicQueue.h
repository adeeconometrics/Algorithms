# pragma once
# ifndef _DYNAMICQUEUE_H
# define _DYNAMICQUEUE_H
template <class T>
class Queue{
    private:
        struct Node{
            T value;
            Node *rear;
        }

        Node *front;
        
    public:
        Queue(){
            top = NULL;
            rear = NULL;
        }
        ~Queue();

        void enqueue(T &data);
        void dequeue();
        void push(T &data);
        void pop();
        void top();
        void clear();

        bool isEmpty();
};

# endif