#include "..\GenericStructures\ArrayList.h"

int main() {
  ArrayList<int> list;
  for (size_t i = 0; i < 10; ++i)
    list.add(i);
  list.display();
  std::cout << "\n";

  list.capture();
  for (size_t i = 0; i < 10; ++i) {
    if (list[i] % 2 == 0)
      list[i] = 0;
  }
  //  for (ArrayList<int>::iterator it = list.begin(); it != list.end(); ++it) {
  //     std::cout << *it << " ";
  //  }
  std::cout << "begin: " << &list[0] << '\n';
  std::cout << *list.begin() << '\n';
  std::cout << "end: " << &list[list.size() - 1] << '\n';
  std::cout << *list.end() << '\n';
  list.release();
}