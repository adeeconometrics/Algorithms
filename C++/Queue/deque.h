// implemmented as dobuly linked list

# pragma once
// # define _DEQUE_H
// # ifndefine _DEQUEUE_H

template <typename T>
class deque{
    private:
        struct Node{
            T value;
            struct Node *prev, *next;
        };
        Node *front, *back;
        int counter;

    public:
        dequeue(){}
        ~dequeue(){}
        // standard operations
        void add(const T data);
        void remove(const T data);
        void clear();
        void sort();
        void display();
        // specialized operations
        void display_ascending();
        void display_descending();
        void enqueue();
        void dequeue();
        void pop_back();
        void push_back();
        void pop_front();
        void push_front();
        
        T front();
        T back();
};