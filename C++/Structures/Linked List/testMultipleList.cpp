#pragma once
#include <iostream>
#include <string>

class List {
private:
  struct Node {
    int number;
    int year;
    std::string title;
    Node *next, *str_ptr, *number_ptr, *year_ptr;
  };
  Node *head, *front, *back;
  int counter;

public:
  List() {
    head = NULL;
    counter = 0;
    front = head;
    back = head;
  }
  ~List() { clear(); }

  void clear();
  void append(std::string title, int year) {
    Node *newNode = new Node();
    counter += 1;
    newNode->title = title;
    newNode->year = year;
    newNode->number = counter;

    if (isEmpty()) {
      head = newNode;
      newNode->next = NULL;
      newNode->number_ptr = NULL;
      newNode->year_ptr = NULL;
      newNode->str_ptr = NULL;
    } else {
      Node *ptr = head;
      while (ptr->next != NULL) {
        ptr = ptr->next;
      }
      ptr->next = newNode;
      back = newNode;
    }
  }

  void removeTitle(std::string &title) {
    if (isEmpty())
      std::cout << "list is aready empty." << std::endl;
    else {
      Node *ptr, *temp;
      ptr = head;

      while (ptr->next != NULL) {
        if (ptr->title == title) {
          // delete all items where it matches the title
          temp = ptr;
          ptr = ptr->next;
          delete temp;

          counter -= 1;
        }
        ptr = ptr->next;
      }
    }
  };

  void removeYear(int year) {
    if (isEmpty())
      std::cout << "list is aready empty." << std::endl;
    else {
      Node *ptr, *temp;
      ptr = head;

      while (ptr->next != NULL) {
        if (ptr->year == year) {
          // delete all items where it matches the year
          temp = ptr;
          ptr = ptr->next;
          delete temp;

          counter -= 1;
        }
        ptr = ptr->next;
      }
    }
  };

  void removeFront() {
    if (isEmpty())
      std::cout << "list is already empty." << std::endl;
    else {
      Node *ptr;
      ptr = head;
      head = head->next;
      delete ptr;

      counter -= 1;
    }
  }
  // void removeBack(){
  //     if(isEmpty())
  //         std::cout<<"list is already empty."<<std::endl;
  //     else{
  //         Node *ptr;
  //         ptr = back;
  //         back = back;
  //         delete ptr;

  //         counter -= 1;
  //     }

  // }

  void sortID() {
    // Node *ptr;
    // ptr = head;

    // int size = counter;
    // int minID, idx;
    // for(int i = 0;i < size-1; i++){
    //     idx = i;
    //     for(int j = i+1; j < size; j++){
    //         if()
    //     }
    // }
  }

  void sortYear() {}

  void sortTitle() {}

  void display() {
    Node *ptr = head;

    while (ptr->next != NULL) {
      std::cout << "ID number: " << ptr->number << std::endl;
      std::cout << "Title: " << ptr->title << std::endl;
      std::cout << "Year: " << ptr->year << std::endl;

      ptr = ptr->next;
    }
  }

  void displayByTitle();

  void clear() {
    Node *ptr, *temp;
    ptr = head;

    while (ptr->next != NULL) {
      temp = ptr;
      ptr = ptr->next;
      delete temp;
    }
  }

  bool isEmpty() {
    if (head == NULL && counter == 0)
      return true;
    else
      return false;
  }

private:
  void swap(Node *ptr1, Node *ptr2) {
    Node *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = ptr1;
  }
};