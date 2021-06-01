# pragma once
# ifndef _LIST_H
# define _LIST_H
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

        // void sort(){

        // }
};

# endif