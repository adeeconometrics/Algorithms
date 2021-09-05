/**
 * @file ConcreteListDeque.h
 * @author ddamiana
 * @brief Concrete implementation of ListDeque
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "IteratorConcreteListDeque.h"
#include <initializer_list>
#include <stdexcept>
#include <iostream>

class ListDeque {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef ListDeque_Iterator iterator;
  typedef cListDeque_Iterator const_iterator;
  typedef rListDeque_Iterator reverse_iterator;
  typedef crListDeque_Iterator const_reverse;

private:
  pointer_type m_ptr{nullptr};
  size_type m_size{0}, m_idx{0};

public:
  explicit ListDeque() = default;
  explicit ListDeque(const std::initializer_list<int> &i_list);
  explicit ListDeque(const ListDeque &rhs);
  explicit ListDeque(ListDeque &&rhs) noexcept;

  ~ListDeque();

  ListDeque &operator=(const ListDeque &rhs);
  ListDeque &operator=(ListDeque &&rhs);
  value_type operator[](size_t idx) const;

  void push_first(int element);
  void push_last(int element);
  void pop_first();
  void pop_last();

  void enqueue(int element);
  void push(int element);
  void deque();
  void pop();
  void clear();

  bool is_empty() const;
  bool is_full() const;

  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();

  friend std::ostream &operator<<(std::ostream &ss, const ListDeque &array);

private:
  void swap(ListDeque &other) noexcept;
};