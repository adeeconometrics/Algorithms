# include <string>
# include <iostream>
// singly linked list

template <class T>
class List{
    private:
        struct linkedList{
            T value;
            struct linkedList *next;
        };

        linkedList *head;

    public:
        List(){head = NULL;}
        ~List(){
            clear();
        }

        void append(T &data){
            linkedList *newList;
            newList = new linkedList;
            newList->value = data;

            if(isEmpty()){
                head = newList;
            }
            else{
                linkedList *ptr;
                ptr = head;

                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next = newList;
            }
        }

        void remove(T &data){
            
            if(isEmpty()){
                std::cout<<"list is empty."<<std::endl;
                return;
            }
            else{
                //traverse
                linkedList *ptr1, *ptr2;
                ptr1 = head;

                while(ptr1->next!=NULL){
                    ptr2 = ptr1;
                    if(data == ptr1->value){
                        // delete node
                        ptr2 = ptr1->next; //ptr2->next = next of ptr1
                        delete ptr1;
                        ptr1 = ptr2;
                    }
                    ptr1 = ptr1->next;
                }
            }
        }

        bool isEmpty(){
            if(head == NULL) return true;
            return false;
        }

        void display(){
            linkedList *ptr;
            ptr = head;

            if(isEmpty()){
                std::cout<<"list is empty."<<std::endl;
                return;
            }

            while(ptr->next != NULL){
                std::cout<<ptr->value<<" ";
                ptr = ptr->next;
            }
            std::cout<<"\n";

        }
        void clear(){
            linkedList *ptr1, *ptr2;
            ptr1 = head;

            while(ptr1->next != NULL){
                ptr2 = ptr1->next;
                delete ptr1;
                ptr1 = ptr2;
            }
            head = NULL;
        }
};

int main(){
	List<int> list;
	//test append
	for(int i=0; i<=20; i++){
		// insert even numbers to the list
		if(i%2 == 0) list.append(i);
	}
	
	list.display();
	
	//add duplicate
	for(int i=0; i<=20; i++){
		// insert even numbers to the list
		if(i%2 == 0) list.append(i);
	}
	list.display();
	//test remove
	int x = 2;
	list.remove(x);
	list.display();
	//test clear
	list.clear();
	//test display
	list.display();
}