#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution<int> distribution(1000, 4000);

unsigned int gcd(const unsigned int &x, const unsigned int &y) {
  if (y == 0)
    return x;
  gcd(y, x % y);
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

int random_prime() {
  while (true) {
    int random = distribution(generator);
    if (is_prime(random))
      return random;
  }
}

int p() { return random_prime(); }
int q() { return random_prime(); }

unsigned int totient() { return (p() - 1) * (q() - 1); }
unsigned int n() { return p() * q(); }
unsigned int e() {
  while (true) {
    int random = generator();
    if (is_coprime(random, totient() - 1))
      return random;
  }
}

unsigned int d() { return (unsigned int)pow(e(), -1) % totient(); }

unsigned int _d = d();
unsigned int _e = e();
unsigned int _n = n();

class A {
  A *m_ptr;
  unsigned int e;
  unsigned int d;
  unsigned int n;

public:
  A() {
    e = _e;
    d = _d;
    n = _n;
  }

  std::string encrypt(const std::string &_msg) {
    std::vector<int> ascii = to_vec(_msg);
    std::stringstream ss;

    for (std::vector<int>::iterator it = ascii.begin(); it != ascii.end();
         ++it) {
      ss << (char)(((int)pow(*it, e) % n) % 127);
    }
    return ss.str();
  }

  std::string decrypt(const std::string &_msg, const unsigned int &d) {
    std::vector<int> ascii = to_vec(_msg);
    std::stringstream ss;

    for (std::vector<int>::iterator it = ascii.begin(); it != ascii.end(); ++it) {
      ss << (char)(((int)pow(*it, e * d) % n) % 127);
    }
    return ss.str();
  }

  std::vector<int> to_vec(const std::string &str) {
    std::vector<int> v;
    std::string _str(str);
    for (std::string::iterator it = _str.begin(); it != _str.end(); ++it) {
      v.push_back((int)(*it));
    }
    return v;
  }
};

int main() {
  A a;
  std::cout << a.encrypt("encrypt sample string") << "\n";
  std::cout << a.decrypt(a.encrypt("sample string"), d());
}
