/**
 * @file ConcreteSinglyList.h
 * @author ddamiana
 * @brief Concrete implementtion of SinglyList
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "IteratorConcreteSinglyList.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class SinglyList {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef SinglyList_Iterator iterator;
  typedef cSinglyList_Iterator const_iterator;

private:
  struct Node {
    Node *next{nullptr};
    value_type data;
    Node(int i_data) : data(i_data) {}
  };

  Node *m_front{nullptr}, *m_back{nullptr};
  size_type m_size{0};

public:
  SinglyList() = default;
  SinglyList(const std::initializer_list<int> &i_list);
  SinglyList(const SinglyList &rhs);
  SinglyList(SinglyList &&rhs) noexcept;

  ~SinglyList();

  SinglyList &operator=(const SinglyList &&rhs);
  SinglyList &operator=(SinglyList &&rhs) noexcept;

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

  const_iterator cbegin();
  const_iterator cbegin();
  iterator begin();
  iterator end();

  friend std::ostream &operator<<(std::ostream &ss, const SinglyList &list);

private:
  void swap(SinglyList &other) noexcept;
};