#include "ConcreteArray.h"
#include <array>
#include <iostream>

inline void test_operators(Array &array) {
  std::cout << "test index operator: \n\t first_element:" << array[0] << '\n';
  std::cout << "\t last_element: " << array[array.size()] << '\n';

  std::cout << "test loop in forward iteration: \n";
}

inline void test_move(Array &&array) {
  std::cout << "move constructor is successfully invoked. \n";
  std::cout << array;
}

inline void test_copy(const Array &array) {
  std::cout << "copy constructor is successfully invoked. \n";
  std::cout << array;
}

int main() {}