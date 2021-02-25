# pragma once
# ifndef _DYNAMICQUEUE_H
# define _DYNAMICQUEUE_H
template <typename T>
class Queue{
    private:
        struct Node{
            T value;
            Node *rear;
        }

        Node *front;
        int size;
        
    public:
        Queue(){
            front = NULL;
            rear = NULL;
            size = 0;
        }
        ~Queue();

        void enqueue(T &data);
        void dequeue();
        void top();
        void clear();
        void display();
        bool isEmpty();
        bool isElement(T data);
        int currentSize();
};

template <typename T>
bool Queue<T>::isEmpty(){
	if(size == 0) return true; 
	else return false;
}

template <typename T>
void Queue<T>::enqueue(T &data){
	Node *newNode;
	newNode = new Node;
	newNode->data = data;
	
	if(isEmpty()){
		front = newNode; 
		rear = newNode; 
	}
	else{
		rear->next = newNode;
		rear = rear->next; // or rear = newNode;
	}
	
	size+=1;
}

template <typename T>
void Queue<T>::dequeue(){
	if(isEmpty()){
		std::cout<<"the queue is already empty";
	}
	else{
		Node *temp;
		temp = front;
		front = front->next;
		delete temp; 
	}
	
	size-=1;
}

template <typename T>
int Queue<T>::currentSize(){
	return size;
}

template <typename T>
void Queue<T>::clear(){
	int _size = size;
	while(_size>0){
		dequeue();
		_size -= 1;
	}
}

template <typename T>
void Queue<T>::display(){
	Node *temp = front;
	int _size = size;
	
	while(_size>0){
		cout<<temp->data<<" ";
		temp = temp->next;
		_size -= 1;
	}
}

template <typename T>
bool Queue<T>::isElement(T data){
	int _size = size;
	Node *temp = front;
	
	while(_size>0){
		if(temp->data == data) return true;
		temp = temp->next;
		_size -= 1;
	}
	return false;
}

template<typename T>
T Queue<T>::top(){
    return front->data;
}
# endif