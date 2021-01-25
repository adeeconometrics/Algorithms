// linked list
# include <iostream>


class FloatList{
	private:
		struct Node{
			float val;
			struct Node *next;
		} *head;
		
	public:
		FloatList(){head = NULL;}
		~FloatList();
		void appendNode(float val);
		void insertNode(float val);
		void deleteNode(float val);
		void display(float val);
};

void FloatList::appendNode(float val){
	Node *newNode, *nodePtr;
	// allocate a new node & store val 
	newNode = new Node;
	newNode->val = val;
	newNode->next = NULL;
	
	if(!head) head = newNode;
	else{
		nodePtr = head;
		// find the last node in the list
		while(nodePtr->next)
			nodePtr = nodePtr->next;
		// insert newNode as the last node 
		nodePtr->next = newNode;
	}
}
