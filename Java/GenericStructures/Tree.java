package GenericStructures;

public class Tree<T extends Comparable<T>>{
    class Node{
        T data;
        Node left = null;
        Node right = null;
        public Node(T data){
            this.data = data;
        }
        public Node(){}
    }

    public Node root = null;
    public Tree(){}
    
    public void displayInorder(Node ptr){
        if(ptr!=null){
            displayInorder(ptr.left);
            System.out.println(ptr.data);
            displayInorder(ptr.right);
        }
    }

    public void displayPreorder(Node ptr){
        if(ptr!=null){
            System.out.println(ptr.data);
            displayPreorder(ptr.left);
            displayPreorder(ptr.right);
        }
    }

    public void displayPostorder(Node ptr){
        if(ptr!=null){
            displayPostorder(ptr.left);
            displayPostorder(ptr.right);
            System.out.println(ptr.data);
        }
    }

    public void insertNode(Node node){
        insertNodeElement(node.data);
    }

    public void insertNodeElement(T data){
        Node node = new Node(data);
        if(is_empty()){
            root = node;
        }else{
            Node ptr = root;
            while(ptr.left != null || ptr.right != null){
                if((node.data).compareTo(ptr.data) == -1)
                    ptr = ptr.left;
                if((node.data).compareTo(ptr.data) == 1)
                    ptr = ptr.right;
                if((node.data).compareTo(ptr.data) == 0)
                    return; // no duplicate
            }

            if((node.data).compareTo(ptr.data) == 1)
                ptr.right = node;
            else
                ptr.left = node;
        }
    }

    public Node deleteNode(Node ptr, T data){
        if(ptr==null)
            return ptr;
        else if((data).compareTo(ptr.data) == -1)
            ptr.left = deleteNode(ptr.left, data);
        else if(data.compareTo(ptr.data) == 1)
            ptr.right = deleteNode(ptr.right, data);
        else{
            // case 1: leaf node
            if(ptr.left == null && ptr.right == null){
                ptr = null;
            }
            // case 2: one child
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
            // case 3: 2 children
            else{
                Node temp  = findMin(ptr.right);
                ptr.data = temp.data;
                ptr.right = deleteNode(ptr.right, temp.data);
            }

            return ptr;
        }

    }

    public Node findMin(Node ptr){
        while(ptr.left != null)
            ptr = ptr.left;
        return ptr;
    }

    public Node findMax(Node ptr){
        while(ptr.right != null)
            ptr = ptr.right;
        return ptr;
    }

    public boolean is_element(T data){
        Node ptr = root;
        while(ptr.left != null || ptr.right != null){
            if((data).compareTo(ptr.data) == -1)
                ptr = ptr.left;
            if(data.compareTo(ptr.data) == 1)
                ptr = ptr.right;
            if(data.compareTo(ptr.data) == 0)
                return true; 
        }
        return false;
    }

    private boolean is_empty(){
        return root == null;
    }
}

class MainClass{
    public static void main(String[] args){
        Tree<Integer> tree = new Tree<>();

        for(int i = 0; i < 10; ++i){
            tree.insertNodeElement(i);
        }
        tree.displayInorder(tree.root);
    }
}
