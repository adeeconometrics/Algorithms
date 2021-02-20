//Dynstack test

# include <iostream>
//# include "dynamicStack.h"


template<class T>
class Stack{
	private:
		struct stackNode{
			T value;
			stackNode *next;
		};
		
		stackNode *top_;
		int size;
		
	public:
		Stack(){
			top_ = NULL;
			size = 0;
		}
		
		void push(T &data){
			stackNode *newNode;
			// create new node and initialize value
			newNode = new stackNode;
			newNode->value = data;
			
			if(isEmpty()){
				top_ = newNode;
				size++;
			}	
			else{
				top_ = newNode;
				newNode = top_->next;
				size++;
			}
		}
		
		void pop(){
			stackNode *temp;
			
			if(isEmpty())
				std::cout<<"the stack is empty";
			else{
//				data = top_->value;
				temp = top_->next;
				delete top_;
				top_ = temp;
				--size;
			}	
		}
		
		
		bool isEmpty(){
			if(top_ == NULL)
				return true;
			else
				return false;
		};
		
		// will this return a reference of the top_?
		void top(){
			return &top_;
		}
		
		int stackSize(){
			return size;
		}
};

int main(){
	Stack<int> s;
	
	for(int i = 0; i<10; i++)
		s.push(i);
	
z	for(int i = 0; i<s.size(); i++){
//		std::cout<< s._top() << std::endl;
//	}	
}
