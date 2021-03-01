// logic

#include <iostream>
#include <type_traits>

template <typename Base, typename T> class Assert {
public:
  Assert() {}
  bool is_instance() { return std::is_base_of<Base, T>::value; }
  bool is_same() { return std::is_same<Base, T>::value; }
};

class Logic {
public:
  bool p;
  Logic(bool _p) : p(_p) {}
  Logic() {}
  // functions
  bool implication(const bool &q) const { return !p || q; }
  bool conjunction(const bool &q) const { return p && q; }
  bool negation(const bool &q) const { return !q; }
  bool iff(const bool &q) const { return (!p || q) && (!q || p); }
  bool disjunction(const bool &q) { return p || q; }
  bool XOR(const bool &q) const { return (p || q) && negation(p && q); }
  bool XNOR(const bool &q) const { return !XOR(q); }
  bool NAND(const bool &q) const { return !(p && q); }
  // operators
  Logic operator>(Logic &other) {
    Logic q;
    q.p = other.p;
    q.p = !p || q.p;
    return q;
  }
  Logic operator&(Logic &other) {
    Logic q;
    q.p = other.p;
    q.p = p && q.p;
    return q;
  }
  Logic operator|(Logic &other) {
    Logic q;
    q.p = other.p;
    q.p = p || q.p;
    return q;
  }
  Logic operator~() {
    Logic q;
    q.p = !p;
    return q.p;
  }
  Logic operator==(Logic &other) {
    Logic q;
    q.p = other.p;
    q.p = (!p || q.p) && (!q.p || p);
    return q;
  }
  Logic operator()(Logic &other) {
    Logic q;
    q.p = p;
    return q;
  }
};

class Deduction : public Logic {
public:
  void conjunction_intro();
  void conjunction_elim();
  void disjunction_intro();
  void disjunction_elim();
  void negation_intro();
  void negation_elim();
  void implication_intro();
  void implication_elim();
  void equivalence_intro();
  void equivalence_elim();
};

class Quantification : public Deduction {
public:
  void universal_intro();
  void universal_elim();
  void existential_intro();
  void existential_elim();
};

std::ostream &operator<<(std::ostream &stream, const struct Logic &obj) {
  if (obj.p)
    stream << "true." << std::endl;
  else
    stream << "false." << std::endl;
  return stream;
}

int main() {
  Logic p(5 == 4), q(true), s(false);
  Logic r = p > q;
  r = (p & q) > r;
  r = (q | s) > r;
  std::cout << r;
  std::cout << ~r;
}
