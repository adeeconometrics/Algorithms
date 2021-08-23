#include "..\GenericStructures\CircularList.h"

int main() {
  CircularList<int> cl;
  for (size_t i = 0; i < 10; ++i)
    cl.add(i);
  std::cout << "\nsize: " << cl.size();
  std::cout << "\nfront: " << cl.top() << "\nback: " << cl.bottom();
  //	size_t a = 0;
  //	std::cout << a;
}