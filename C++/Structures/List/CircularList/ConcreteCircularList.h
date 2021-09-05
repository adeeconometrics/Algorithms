/**
 * @file ConcreteCircularList.h
 * @author ddamiana
 * @brief Concrete implementtion of CircularList
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "IteratorConcreteCircularList.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class CircularList {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef CircularList_Iterator iterator;
  typedef cCircularList_Iterator const_iterator;
  typedef rCircularList_Iterator reverse_iterator;
  typedef crCircularList_Iterator const_reverse;

private:
  struct Node {
    Node *next{nullptr}, *prev{nullptr};
    value_type data;
    Node(int i_data) : data(i_data) {}
  };

  Node *m_front{nullptr}, *m_back{nullptr};
  size_type m_size{0};

public:
  CircularList() = default;
  CircularList(const std::initializer_list<int> &i_list);
  CircularList(const CircularList &rhs);
  CircularList(CircularList &&rhs) noexcept;

  ~CircularList();

  CircularList &operator=(const CircularList &&rhs);
  CircularList &operator=(CircularList &&rhs) noexcept;

  void remove(int data); // default front
  void remove_front(int data);
  void remove_back(int data);
  void add_front(int data);
  void add_back(int data);
  void add(int data); // default front
  void clear();

  size_type size() const;
  value_type front() const;
  value_type& front();
  value_type back() const;
  value_type& back();

  bool is_empty() const;

  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse crbegin ();
  const_reverse crend ();
  const_iterator cbegin();
  const_iterator cbegin();
  iterator begin();
  iterator end();

  friend std::ostream &operator<<(std::ostream &ss, const CircularList &list);

private:
  void swap(CircularList &other) noexcept;
};