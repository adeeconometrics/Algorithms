#include <iostream>

template <typename T>
class GenericTree{
    struct Node{
        T data;
        Node *breadth;
    };

    public:
        explicit GenericTree();
        ~GenericTree();

        void add(const T& _element);
        void remove(const T& _element);
        void traversal_preorder();
        void traversal_postorder();
        void traversal_onroder();

        bool is_element(const T& _element);
        bool is_empty();
        T& child_of(const T& _element);
        T& parent_of(const T& _element);

        int height(const Node &node)
};