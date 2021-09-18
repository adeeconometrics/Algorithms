/**
 * @file GenericInitializer.cpp
 * @author ddamiana
 * @brief generic type for initializer list
 * @version 0.1
 * @date 2021-09-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <initializer_list>

template <typename T, size_t Dim> struct InitializerType {
  typedef std::initializer_list<typename InitializerType<T, Dim - 1>::list_type>
      list_type;

  InitializerType(list_type l_type, )
};

template <typename T> struct InitializerType<T, 1> {};