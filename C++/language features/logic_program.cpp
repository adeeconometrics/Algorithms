// logical
#include <fstream>
#include <iostream>

// template <typename T>
struct Logical {
  bool p;

public:
  Logical(bool _p) { p = _p; }

  bool implication(const bool &q) const { return !p || q; }
  bool conjunction(const bool &q) const { return p && q; }
  bool negation(const bool &q) const { return !q; }
  bool iff(const bool &q) const { return (!p || q) && (!q || p); }
  bool disjunction(const bool &q) { return p || q; }
  bool XOR(const bool &q) const { return (p || q) && negation(p && q); }
  bool XNOR(const bool &q) const { return !XOR(q); }
  bool NAND(const bool &q) const { return !(p && q); }

  bool operator&(const bool &q) const { return p && q; }
  bool operator|(const bool &q) const { return p || q; }
  bool operator>(const bool &q) const { return !p || q; }
  bool operator==(const bool &q) const { return (!p || q) && (!q || p); }
  bool operatornot(const bool &q) const { return !q; }
};

std::ostream &operator<<(std::ostream &stream, const struct Logical &obj) {
  if (obj.p)
    stream << "true.";
  else
    stream << "false.";
  return stream;
}

int main() {
  Logical p(true), q(false);
  std::cout << p == q;
}
