using System;

class BST{
    class Node{
        public int data;
        public Node left = null;
        public Node right = null;
        public Node(int data){
            this.data = data;
        }
    }

    Node m_root = null;
    int m_size = 0;

    public BST(){}

    
    public void insert_node(Node node){
        if(this.isEmpty()){
            this.m_root = node;
        } else{
            Node ptr = m_root;
            while (ptr != null) {
                if (node.data < ptr.data)
                    ptr = ptr.left;
                else if (node.data > ptr.data)
                    ptr = ptr.right;
                else
                    return;
            }
            if (node.data < ptr.data)
                ptr.left = node;
            if (node.data > ptr.data)
                ptr.right = node;          
        }
        ++ this.m_size;
    }
    
    public void insert_element(int data){
        Node node = new Node(data);
        this.insert_node(node);
    }
    
    public void remove_node(Node node){
        this.delete_element(node, node.data);
        -- this.m_size;
    }
    
    public void remove_element(int data){
        Node node = new Node(data);
        this.delete_element(node, data);
        -- this.m_size;
    }
    
    public void traverse_inorder(Node node){
        if(node != null){
            this.traverse_inorder(node.left);
            Console.WriteLine(node.data + " ");
            this.traverse_inorder(node.right);
        }
    }
    
    public void traverse_preorder(Node node){
        if(node != null){
            Console.WriteLine(node.data + " ");
            this.traverse_preorder(node.left);
            this.traverse_preorder(node.right);
        }
    }
    
    public void traverse_postorder(Node node){
        if(node != null){
            this.traverse_postorder(node.left);
            this.traverse_postorder(node.right);
            Console.WriteLine(node.data + " ");
        }
    }
    
    public Node root(){return this.m_root; }

    public Node find_min(Node node){
        Node ptr = node;
        while(ptr != null)
            ptr = ptr.left;
        return ptr;
    }
    
    public int size(){return this.m_size; }

    public bool is_element(int data){}

    private bool isEmpty(){ return this.m_root == null; }

    private Node delete_element(Node ptr, int data){
        if(ptr == null)
            return ptr;
        else if(data < ptr.data)
            ptr.left = this.delete_element(ptr.left, data)
        else if(data > ptr.data)
            ptr.right = this.delete_element(ptr.right, data)
        else{
            // case 1
            if(ptr.left == null && ptr.right == null)
                ptr = null
            // case 2
            else if(ptr.left == null){
                Node temp = ptr;
                ptr = ptr.right;
                temp = null;
            }
            else if(ptr.right == null){
                Node temp = ptr;
                ptr = ptr.left;
                temp = null;
            }
            // case 3
            else{
                Node temp = this.find_min(ptr.right);
                ptr.data = temp.data;
                ptr.right = delete_element(ptr.right, temp.data);
            }

            return ptr;
        }
    }

}