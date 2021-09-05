/**
 * @file ConcreteListQueue.h
 * @author ddamiana
 * @brief Concrete Implementation of ListQueue
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "IteratorConcreteListQueue.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class ListQueue {
public:
  typedef size_t size_type;
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef const int &const_reference;
  typedef const int *const_pointer;

  typedef ListQueue_Iterator iterator;
  typedef cListQueue_Iterator const_iterator;

private:
  struct Node {
    Node *next{nullptr};
    value_type data;
    Node(value_type i_data) : data(i_data) {}
  };

  Node *m_font{nullptr}, *m_back{nullptr};
  size_type m_size;

public:
  ListQueue() = default;
  ListQueue(const std::initializer_list<int> &i_list);
  ListQueue(const ListQueue &rhs);
  ListQueue(ListQueue &&rhs) noexcept;
  ~ListQueue();

  ListQueue &operator=(const ListQueue &rhs) noexcept;
  ListQueue &operator=(ListQueue &&rhs);

  void enqueue(int element);
  void push(int element);
  void dequeue();
  void pop();
  void clear();

  value_type top() const;
  value_type bottom() const;
  size_type size() const;

  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();

  pivate : void swap(ListQueue &other) noexcept;
};