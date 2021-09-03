/**
 * @file ConcreteOrderedList.h
 * @author ddamiana
 * @brief Concrete implementation of OrderedList
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "IteratorConcreteOrderedList.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class OrderedList{
public:
    typedef int value_type;
    typedef int *pointer_type;
    typedef int &reference_type;
    typedef size_t size_type;

    typedef OrderedList_Iterator iterator;
    typedef cOrderedList_Iterator const_iterator;
    typedef rOrderedList_Iterator reverse_iterator;
    typedef crOrderedList_Iterator const_reverse;

private:
  struct Node{
      Node* next{nullptr};
      value_type data;
      Node(int i_data):data(i_data){}
  };

  Node *m_front{nullptr}, *m_back{nullptr};
  size_type m_size{0};

public:
    OrderedList() = default;
    OrderedList(const std::initializer_list<int>& i_list);
    OrderedList(const OrderedList& rhs);
    OrderedList(OrderedList&& rhs) noexcept;
    ~OrderedList();

    OrderedList& operator=(const OrderedList& rhs);
    OrderedList& operator=(OrderedList&& rhs)noexcept;

    void remove();
    void clear();
    void add();

    size_type size() const;
    bool is_empty() const;
    
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse crbegin ();
    const_reverse crend ();
    const_iterator cbegin();
    const_iterator cend();
    iterator begin();
    iterator end();

    std::ostream& operator<<(std::ostream& ss, const OrderedList& other);

private:
    void swap(OrderedList& other) noexcept;
    void remove_front(Node* node) noexcept;
    void remove_back(Node* node) noexcept;
    void add_back(Node* node) noexcept;
    void add_front(Node* node) noexcept;
};