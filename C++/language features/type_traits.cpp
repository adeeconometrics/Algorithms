#include <iostream>

int func(...) {
  return 0;
} // compiler would prefer anything before it considers the varargs

// enables the function if the following conditions are satisfied
template <typename T>
typename std::enable_if<std::is_integral<T>::value, int>::type func(T val) {
  return 1;
}

// compiler would always pervert exact match over a templated function
int func(float f) { return 2; }

int main() {
  //  std::cout << std::is_same<int, int>::value << ' ';
  std::cout << func(nullptr) << std::endl;
  std::cout << func(2) << std::endl;
  std::cout << func(2.f) << std::endl;
  std::cout << func(2.0) << std::endl;
  return 0;
}