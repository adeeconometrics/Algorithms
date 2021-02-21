// Dynstack test

#include <iostream>
#include <stack>
//# include "dynamicStack.h"

template <class T> 
class Stack {
	private:
	  struct stackNode {
	    T value;
	    stackNode *next;
	  };
	
	  stackNode *top_;
	  int size;
	
	public:
	  Stack() {
	    top_ = NULL;
	    size = 0;
	  }
	
	  void push(T &data) {
	    stackNode *newNode;
	    // create new node and initialize value
	    newNode = new stackNode();
	    newNode->value = data;
	
	    if (isEmpty()) {
	      top_ = newNode;
	      size++;
	    } else {
	      top_ = newNode;
	      newNode = top_->next;
	      size++;
	    }
	  }
	
	  void pop() {

	    if (isEmpty()){std::cout << "the stack is empty";}
	    else {
	      stackNode *temp = top_;
	      top_ = top_->next;
		  size--;
	      delete (temp);
	      
	    }
	  }
	
	  bool isEmpty() {
	    if (top_ == NULL)
	      return true;
	    else
	      return false;
	  };
	
	  T top() { return top_->value; }
	  stackNode* top_reference(){
	  	return top_;
	  }
	
	  int stackSize() { return size; }
};

int main() {
  Stack<int> s;
//  int catchVar;
  std::stack<int> stk;

  for (int i = 0; i < 10; i++){
  	s.push(i);
  	std::cout<<s.top()<<" ";
  	stk.push(i);
  }

std::cout<<std::endl;
//  for (int i = 0; i < s.stackSize(); i++) {
////    std::cout<<s.top()<<" ";
////    s.pop();
//    std::cout<<s.top()<<" ";
//    s.pop();
//  }
//  std::cout<<s.top_reference() <<" ";
//  std::cout<<s.top_reference()->value;
std::cout<<s.top()<<" ";
s.pop();
std::cout<<s.top()<<" ";
s.pop();
std::cout<<s.top()<<" ";
}
