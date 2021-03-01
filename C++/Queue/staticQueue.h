# pragma once
# define _STATICQUEUE_H
# ifndef _STATICQUEUE_H
# include <iostream>

template<typename T>
class s_queue{
    private:
        int size;
        int* queueptr;
        int counter;
    
    public:
        s_queue();
        ~s_queue();
        // general operations
        void add(const T &data);
        void remove(T &data);
        void clear();
        void display();
        // specialized operations
        void enqueue(const T &data);
        void dequeue();
};

# endif