# pragma once

template <class T>
class List{
    private:
        struct Node{
            T value;
            Node *next;
        }

    public:
        List();
        ~List();

        void append(T &data);
        void remove();
        void sort();
        void filter(T &data);
        void clear();
        int match(T &data);

        bool isEmpty();
        bool isElement(T &data);
};