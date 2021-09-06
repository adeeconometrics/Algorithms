/**
 * @file ReferenceSemantics.cpp
 * @author ddamiana
 * @brief illustration of passing object types to functions.
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>

class Type {
  const char *content{"content."};

public:
  Type() = default;
  Type(const Type &) = default;
  Type(Type &&) = default;
  ~Type() = default;

  Type &operator=(const Type &) = default;
  Type &operator=(Type &&) = default;

  const char *get_content() const { return content; }
};

void f(Type type) {
  std::cout << type.get_content();
  return;
}

void f(const Type &type) {
  std::cout << type.get_content();
  return;
}

void f(Type &type) {
  std::cout << type.get_content();
  return;
}

void f(Type &&type) {
  std::cout << type.get_content();
  return;
}

void f(Type *type) {
  std::cout << type->get_content();
  return;
}

void f(const Type *type) {
  std::cout << type->get_content();
  return;
}

void f(Type const *type) {
  std::cout << type->get_content();
  return;
}

/**
 * Conclusion:
 * f(T) accepts {T, T& ,T&&}
 * f(const T&) accepts {T, T&, T&&}
 * f(T&) accepts {T&}
 * f(T&&) accepts {T&&}
 * f(const T*) or f(T const *) accepts {const T*}
 * f(T*) accepts {T*}
 */

int main() {
  Type t;
  const Type *ptr_t = new Type();

  // f(std::move(t));
  // f(t);
  // f(ptr_t);
}