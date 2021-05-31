#include <iostream>

int function(const int &a) {
  const_cast<int &>(a) = 3; // breaking constness to and setting a := 3
  return a;
}

int main() {
  int a{5};
  std::cout << function(a);
}