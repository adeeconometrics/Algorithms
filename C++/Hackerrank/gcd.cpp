#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

template <typename T> struct pair {
  T first;
  T second;
  pair(const T &a, const T &b) : first(a), second(b) {}
  pair();
};

std::default_random_engine generator(std::time(nullptr));
// std::uniform_int_distribution<int> distribution(const int a = 1000, const int
// b = 4000);

class RSA {
private:
  static int e;
  unsigned int p;
  unsigned int q;
  unsigned int n;
  unsigned int d;
  unsigned int totient;
  static RSA *m_ptr;

public:
  RSA() {
    set_p();
    set_q();
    set_n();
    set_d();
    set_totient();
    e = 17;
  }

  std::string encrypt(const std::string &_msg) {
    std::vector<int> ascii = to_vec(_msg);
    std::stringstream ss;

    for (std::vector<int>::iterator it = ascii.begin(); it != ascii.end();
         ++it) {
      ss << (char)((int)pow(*it, e) % n) % 127;
    }
    return ss.str();
  }

  std::string decrypt(const std::string &_msg, const unsigned int &d) {
    std::vector<int> ascii = to_vec(_msg);
    std::stringstream ss;

    for (std::vector<int>::iterator it = ascii.begin(); it != ascii.end();
         ++it) {
      ss << (char)((int)pow(*it, e * d) % n) % 127;
    }
    return ss.str();
  }

  pair<std::string> get_private_key() {
    pair<std::string> p(std::to_string(n), std::to_string(d));
    return p;
  }

  static pair<std::string> get_public_key() {
    pair<std::string> p(std::to_string(m_ptr->n), std::to_string(e));
    return p;
  }

  void update_e() {
    while (true) {
      int random = generator();
      if (is_coprime(random, totient - 1)) {
        e = random;
        return;
      }
    }
  }

private:
  //  unsigned seed =
  //  std::chrono::system_clock::now().time_since_epoch().count();

  std::string ascii_to_string(std::vector<int> v) {
    std::stringstream ss;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
      ss << (char)*it;
    }

    return ss.str();
  }

  std::vector<int> to_vec(const std::string &str) {
    std::vector<int> v;
    std::string _str(str);
    for (std::string::iterator it = _str.begin(); it != _str.end(); ++it) {
      v.push_back(int(*it));
    }
    return v;
  }

  bool is_prime(const unsigned int &x) {
    if (x <= 3)
      return x > 1;
    if (x % 2 == 0 || x % 3 == 0)
      return false;

    int i = 5;
    while (i * i <= x) {
      if (x % 2 == 0 || x % 3 == 0)
        return false;
      i += 6;
    }
    return true;
  }

  bool is_coprime(const unsigned int &x, const unsigned int &y) {
    if (gcd(x, y) == 1)
      return true;
    return false;
  }

  unsigned int gcd(const unsigned int &x, const unsigned int &y) {
    if (y == 0)
      return x;
    gcd(y, x % y);
  }

  int random_prime() {
    while (true) {
      int random = generator();
      if (is_prime(random))
        return random;
    }
  }

  void set_q() { q = random_prime(); }
  void set_p() { p = random_prime(); }
  void set_n() { n = p * q; }
  void set_totient() { totient = (p - 1) * (q - 1); }
  void set_d() { d = (unsigned int)pow(e, -1) % totient; }
};

int main() {
  RSA r;
  //  r.update_e();
  std::cout << r.encrypt("test string");
}
