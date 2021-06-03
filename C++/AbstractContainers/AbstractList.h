#pragma once

template<typename T> class Node final{
    public:
    
    T data;
    Node <T> *next{nullptr};
    Node <T> *prev{nullptr}; 
    
    Node(const T& _data):data(_data){}
    Node() = default;
    ~Node() = default;
};

template<typename T, typename Node = Node<T>> class List{

    public:
        List() = default;
        List(const T& obj) = delete;
        List(T&& obj) = delate;
        virtual ~List() = default;

        T& operator=(const T& rhs) = delete;
        T& operator=(T&& rhs) = delete;

        virtual void add(const T& data) = 0;
        virtual void remove(const T& data) = 0;
        virtual void display() const = 0;

        virtual bool is_element(const T& data) const = 0;
        virtual bool is_empty() const = 0;
};