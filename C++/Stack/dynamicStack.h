// dynamic stack ADT -- build on a linked list
// the dynamic stack will never be full(theoretically), but it is limted by your memory
# pragma once
# include <iostream>

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
			this.size = 0;
		}
		
		void push(T &data){
			stackNode *newNode;
			// create new node and initialize value
			newNode = new stackNode;
			newNode->value = data;
			
			if(isEmpty()){
				top_ = &newNode;
				this.size++;
			}	
			else{
				top_ = &newNode;
				newNode = top_->next;
				this.size++;
			}
		}
		
		void pop(){
			stackNode *temp;
			
			if(isEmpty())
				std::cout<<"the stack is empty";
			else{
				data = top_->value;
				temp = top_->next;
				delete top_;
				top_ = temp;
				--this.size;
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
		
		int size(){
			return this.size;
		}
};
