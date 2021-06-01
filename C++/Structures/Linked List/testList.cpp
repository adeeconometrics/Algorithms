// test singly sorting

#include <iostream>
# include<string>

template <typename T> class List {
private:
  struct Node {
    T value;
    struct Node *next;
  };
  Node *head, *front, *back;
  int current_size;

public:
  List() {
    head = NULL;
    front = head;
    back = front;
    current_size = 0;
  }

  ~List() { clear(); }

		void append(T &data){
			Node *newNode = new Node();
			newNode->value = data;
			
			if(isEmpty()){
				head = newNode;
			}else{
				Node *ptr;
				ptr = head;
				
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = newNode;
				current_size += 1;
			}
		}

  void remove(T &data) {
    if (isEmpty())
      std::cout << "list is already empty." << std::endl;

    if (isElement(data)) {
      Node *ptr, *temp, *prev;
      ptr = head;

      if (ptr->next->value == data) {
        removeFront();
      } else {
        while (ptr->next != NULL && ptr->value != data) {
          prev = ptr;
          ptr = ptr->next;
        }
        temp = ptr;
        ptr = ptr->next;
        delete temp;
        prev->next = ptr;
        current_size -= 1;
      }

    } else
      std::cout << data << " is not an element of the list." << std::endl;
  }

  void removeFront() {
    Node *ptr;
    ptr = head;
    front = ptr->next;
    head = ptr->next;
    delete ptr;
  }

  // insertion sort
  // impose restriction

  void sort() {
    try {
      if (std::is_same<T, std::string>::value || std::is_integral<T>::value ||std::is_floating_point<T>::value){
      	if (isEmpty()) {
	        std::cout << "list is empty" << std::endl;
	        return;
	      }
	      Node *i = head;
	      Node *j = head;

	      while (i->next != NULL) {
	        j = i->next;
	        while (j->next != NULL) {
	          if (i->value > j->value) {
	            // swap
	            swap(i, j);
	          }
	          j = j->next;
	        }
	        i = i->next;
	      }
		}
		else{
			const char* str = "type is not sortable";
			throw str;
		}
    } catch (const char* &str) {
      std::cout << str << std::endl;
    }
}

		void display(){
			
			if(isEmpty()) std::cout<<"list is empty."<<std::endl;
			else{
				Node *ptr;
				ptr = head;
				while(ptr->next != NULL){
				std::cout<<ptr->value<<" ";
				ptr = ptr->next;
				}
			}

		}

  void clear() {
    Node *ptr, *temp;
    ptr = head;

    while (ptr->next != NULL) {

      temp = ptr;
      ptr = ptr->next;
      delete temp;
      temp = ptr;
    }
    head = NULL;
    current_size = 0;
  }

  int size() { return current_size; }

  bool isElement(int &data) {
    Node *ptr;
    ptr = head;

    while (ptr->next != NULL) {
      if (ptr->value == data)
        return true;
      ptr = ptr->next;
    }
    return false;
  }

  bool isEmpty() {
    if (head == NULL && current_size == 0)
      return true;
    return false;
  }

  void swap(Node *&ref1, Node *&ref2) {
    T temp = ref1->value;
    ref1->value = ref2->value;
    ref2->value = temp;
  }
};

struct Node{
	int a;
};
int main() {
  List<std::string> list;
  // test append
  std::string str = "Renefe";
  list.append(str);
  str = "Dave";
  list.append(str);
  str = "Rose";
  list.append(str);
  str = "Ocao";
  list.append(str);
  std::string str2 = "last bit"; // apparently, it's not printing the last item
  list.append(str2);
  


  list.display();
  std::cout<<"\n";
  list.sort();
  list.display();

}
