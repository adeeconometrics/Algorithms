#pragma once

template <typename T> class Node final{
    public:
        T data; 
        Node<T> *left{nullptr};
        Node<T> *right{nullptr};
        
        Node(const T& _data):data(_data){}
        Node() = default;
        ~Node() = default;
};

template<typename T, typename Node = Node<T>> class AbstractBinaryTree{
    public:
        AbstractBinaryTree() = default;
        AbstractBinaryTree(const T& obj) = delete;
        AbstractBinaryTree(T&& obj) = delete;
        virtual ~AbstractBinaryTree() = default;

        T& operator=(const T& rhs) = delete;
        T& operator=(T&& rhs) = delete;

        virtual void traverse_preorder(Node *ptr) = 0;
        virtual void traverse_inorder(Node* ptr) = 0;
        virtual void traverse_postorder(Node* ptr) = 0;
        virtual void insert_node(Node* ptr) = 0;
        virtual void insert_element(const T& data) = 0;

        virtual bool is_empty() const = 0;
        virtual bool is_element() const = 0;
};