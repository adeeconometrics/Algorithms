final class Node{
    var left:Node? = nil;
    var right:Node? = nil;
    lazy var data:Int;
    
    init(data:Int) {
        self.data = data;
    }
}


class BST{
    private var m_root:Node? =  nil;
    private var m_size:Int = 0;

    func insert(data:Int){
        let node:Node = Node(data);

        if self.is_empty(){
            self.m_root = node;
        }
        else{
            var ptr:Node? = self.m_root;

            while(ptr?.left != nil || ptr?.right != nil){
                if (ptr!.data > data){ ptr = ptr?.left;}
                else if (ptr!.data < data) { ptr = ptr?.right;}
                else{ return;}
            }

            if (ptr!.data > data){ ptr?.left = node;}
            else { ptr?.right = node; }
        }
    }

    func remove(data:Int, node:Node? = self.m_root) -> Node{
        if(node == nil){ return  node;}
        else if (data < node!.data) {
            node.left = self.remove(data, node?.left);
        }
        else if (data > node!.data) {
            node.right = self.remove(data, node?.right);
        }
        else{
            // case 1:
            if (node?.left == nil and node?.right == nil){node = nil}
            // case 2:
            else if (node?.left == nil) {
                var ptr:Node? = node;
                node = node?.right;
                ptr = nil; // will it work as expected?
            }
            else if (node?.right == nil) {
                var ptr:Node? = node;
                node = node?.left;
                ptr = nil; // will it work as expected?
            }
            // case 3:
            else{
                var ptr:Node? = self.find_min(node);
                node!.data = ptr!.data;
                ptr?.right = self.remove(ptr!.data, node?.right);
            }
        }

    }

    func traverse_preorder(root:Node = self.m_root){
        if(root != nil){
            print(" \(root!.data)");            
            traverse_preorder(root: self.m_root?.left);
            traverse_preorder(root: self.m_root?.right);
        }
    }

    func traverse_postorder(root:Node = self.m_root){
        if(root != nil){
            traverse_postorder(root: self.m_root?.left);
            traverse_postorder(root: self.m_root?.right);
            print(" \(root!.data)");            
        }
    }

    func traverse_inorder(root:Node = self.m_root){
        if(root != nil){
            traverse_inorder(root: self.m_root?.left);
            print(" \(root!.data)");            
            traverse_inorder(root: self.m_root?.right);
        }
    }

    func is_empty()->Bool{
        return self.m_root == nil;
    }

    func find_min(node:Node)->Node{
        while(node.left != nil){
            node = node.left;
        }
        return node;
    }

}