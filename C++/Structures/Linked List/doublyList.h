# pragma once
# ifndef _DOUBLYLIST_H
# define _DOUBLYLIST_H

template <class T>
class List{
    private:
        struct Node{
            T value;
            Node *next, *prev;
        }
        Node *head, *front, *back;
        int current_size;

    public:
        List(){
            head = NULL;
            front = head;
            back = front;
            current_size = 0;
        }
        ~List(){clear();}

        void append(T &data);
        void remove();
        void push_back(T &data);
        void pop_back();
        void push_front(T &data);
        void pop_front();
        void clear();
        void filter(T &data);
        int match(T &data);
        Node *font();
        Node *back();
        T show_front();
        T show_back();
        void sort();
        int size();
        bool isEmpty();
        bool isElement(T &data);
};

template <class T>
void List<T>::append(T &data){
    
}
# endif