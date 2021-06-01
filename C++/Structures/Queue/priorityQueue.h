#pragma once
template <typename T>
class priority_queue{
    private:
        struct Node{
            T data;
            int label;
            Node *next;
        }*front, *rear;
        
        struct Couple{
            explicit Couple(const Node &_node, const int &_label):node(_node), label(_label){}
            Couple *next;

            private:
                Node node;
                int label;
        };

        int size = 0;
        int counter = 0;

    public:
        explicit priority_queue(){}
        ~priority_queue();
        void push(const T& _element, const int& label);
        void pop();

        T& Top()

        bool is_empty();

    private:
        void sort_by_label();
        void enqueue();
};