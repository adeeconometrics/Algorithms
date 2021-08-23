#include "..\GenericStructures\ArrayQueue.h"

int main() {
  ArrayQueue<int, 3> s;
  s.push(1);
  s.enqueue(2);
  s.push(3);
  s.pop();
  for (ArrayQueue<int, 3>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " ";

  std::cout << "\n";
  std::cout << "top : " << s.top() << '\n';
  std::cout << "bottom : " << s.bottom() << '\n';
}