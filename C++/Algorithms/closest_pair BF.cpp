// closes pair points BF
#include <cmath>
#include <iostream>
#include <vector>

template <typename P1, typename P2> struct Pair {
  P1 p1;
  P2 p2;

  Pair(P1 i_p1, P2 i_p2) : p1(i_p1), p2(i_p2) {}

  friend std::ostream &operator<<(std::ostream &ss, const Pair<P1, P2> &obj);
};

struct Points {
  int x{0}, y{0};
  Points(int i_x, int i_y) : x(i_x), y(i_y) {}
  friend std::ostream &operator<<(std::ostream &ss, const Points &point);
};

Pair<Points, size_t> closest_pair(const std::vector<int> &v) {}

int main() {}
