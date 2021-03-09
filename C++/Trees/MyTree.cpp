// modified treee

# include <iostream>

class Tree{
	private:
		struct Node{
			int value;
			Node *left;
			Node *right;
		};
		
		Node *root;
		
	public:
		explicit Tree(){
			root = NULL;
		}
		
		void insert_node(Node *node);
		void insert_element(int element)
		void delete_element(int element); // can be recursive
		void traverse_inorder(Node *node);
		void traverse_inverse(Node *node);
		void traverse_postorder(Node *node);
		void traverse_preorder(Node *node);
		
		bool find_node(int element);
};

void Tree::insert_element(int element){
	Node *node = new Node;
	node->value = element;
	node->left = node->right = NULL;
	
	if(root == NULL) root = node;
	else{
		Node *ptr = root;
		while(ptr != NULL){
			if(ptr->value < node->value) ptr = ptr->right;
			if(ptr->value > node->value) ptr = ptr->left;
			if(ptr->value == node->value){
				std::cout<<"there exist a duplicate."<<std::endl;
				return;
			}
		}
		
		if(ptr->value < node->value) ptr->right = node;
		if(ptr->value > node->value) ptr->left = node;	
	}
}

void Tree::insert_node(Node *node){
	if(root == NULL) root = node;
	else{
		Node *ptr = root;
		while(ptr != NULL){
			if(ptr->value < node->value) ptr = ptr->right;
			if(ptr->value > node->value) ptr = ptr->left;
			if(ptr->value == node->value){ //duplicate values are tolerable -- this can be improved
				std::cout<<"there exist a duplicate."<<std::endl;
				return;
			}
		}
		
		if(ptr->value < node->value) ptr->right = node;
		if(ptr->value > node->value) ptr->left = node;	
	}
}

void Tree::traverse_inorder(Node *node){
	if(node){
		traverse_inorder(node->left);
		std::cout<<node->value<<std::endl;
		traverse_inorder(node->right);
	}
}

void Tree::traverse_inverse(Node *node){
	if(node){
		traverse_inverse(node->right);
		std::cout<<node->value<<std::endl;
		traverse_inverse(node->left);
	}
}

void Tree::traverse_preorder(Node *node){
	if(node){
		std::cout<<node->value<<std::endl;
		traverse_preorder(node->right);
		traverse_preorder(node->left);
	}
}

void Tree::traverse_postorder(Node *node){
	if(node){
		traverse_postorder(node->right);
		traverse_postorder(node->left);
		std::cout<<node->value<<std::endl;
	}
}

bool Tree::find_node(int element){
	bool flag = false;
	
	if(root == NULL){
//		std::cout<<"the tree is empty."<<std::endl; 
		return flag;
	}
	else{
		Node *ptr = root;
		while(ptr!= NULL){
			if(element < ptr->value) ptr = ptr->left;
			if(element > ptr->value) ptr = ptr->right;
			if(element == ptr->value){
				flag = true;
				return flag;
			} 
		}
		return flag;
	}
}

void Tree::delete_element(int element){
	if(find_node(element)){
		Node *ptr = root;
		
		while(ptr != NULL){
			if(element < ptr->value) ptr = ptr-left;
			if(element > ptr->value) ptr = ptr->right;
			if(element == ptr->value) break;
		}
		
		// case when left and right is null
		if(ptr->left == NULL && ptr->right == NULL) delete ptr;
		// case when left or right is null
		if(ptr->left == NULL || ptr->right == NULL){
			Node *temp = ptr;
			// right, root, left
			//swap nodes
		}
		
		std::cout<<element<<" is successfully deleted."<<std::endl;
		return;
	}
	std::cout<<"element is not found, there is nothing to be performed."<<std::endl;
	return;
}
