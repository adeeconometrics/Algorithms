/**
 * @file ConcreteVector.h
 * @author ddamiana
 * @brief Concrete Implementation of a Vector.
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "IteratorConcreteVector.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class Vector {

public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef Vector_Iterator iterator;
  typedef cVector_Iterator const_iterator;

private:
  pointer_type m_ptr = nullptr;
  size_type m_size{0}, m_idx{0};

public:
    Vector() = default;
    Vector(const std::initializer_list<int>& i_list);
    Vector(const Vector& rhs);
    Vector(Vector&& rhs) noexcept;

    ~Vector();

    Vector& operator=(const Vector& rhs);
    Vector& operator=(Vector&& rhs) noexcept;
    
    value_type& operator[](size_t idx);
    value_type operator[](size_t idx) const;

    void clear();
    void set_factor(size_t factor);
    size_type size() const;

private:
    void swap(Vector& other)noexcept;
    void grow();

};