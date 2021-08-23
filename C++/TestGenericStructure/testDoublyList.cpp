#include "..\GenericStructures\DoublyList.h"

int main() {
  DoublyList<int> v;
  int x{0};

  for (size_t i = 0; i < 5; i++) {
    v.add(i);
    std::cout << "added: " << i << '\n';
  }

  DoublyList<int> mv(v);
  mv.display();
  //   std::cout << mv.size();
  //   std::cout << v.is_empty();
  //   v.display();
}