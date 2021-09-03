/**
 * @file ConcreteDoublyList.h
 * @author ddamiana
 * @brief Concrete implementtion of DoublyList
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "IteratorConcreteDoublyList.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class DoublyList {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef DoublyList_Iterator iterator;
  typedef cDoublyList_Iterator const_iterator;
  typedef rDoublyList_Iterator reverse_iterator;
  typedef crDoublyList_Iterator const_reverse;

private:
  struct Node {
    Node *next{nullptr}, *prev{nullptr};
    value_type data;
    Node(int i_data) : data(i_data) {}
  };

  Node *m_front{nullptr}, *m_back{nullptr};
  size_type m_size{0};

public:
  DoublyList() = default;
  DoublyList(const std::initializer_list<int> &i_list);
  DoublyList(const DoublyList &rhs);
  DoublyList(DoublyList &&rhs) noexcept;

  ~DoublyList();

  DoublyList &operator=(const DoublyList &&rhs);
  DoublyList &operator=(DoublyList &&rhs) noexcept;

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

  friend std::ostream &operator<<(std::ostream &ss, const DoublyList &list);

private:
  void swap(DoublyList &other) noexcept;
};