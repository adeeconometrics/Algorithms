#include <iostream>

class Abstract {
public:
  Abstract() {
    std::cout << "Abstract class constructor is called." << std::endl;
  }

  virtual ~Abstract() {
    std::cout << "Abstract class desctructor is called." << std::endl;
  }

  void virtual abstract_method() = 0; // pure abstract method
  void virtual default_method() {
    std::cout << "default_method is called from Abstract class." << std::endl;
  }
};

class Base : public Abstract {
public:
  Base() { std::cout << "Base class constructor is called." << std::endl; }

  ~Base() { std::cout << "Base class desctructor is called." << std::endl; }

  void abstract_method() override {
    std::cout << "abstract_method is implemented in the Base class."
              << std::endl;
  }

  void base_method() {
    std::cout << "base_method is called from Base class." << std::endl;
  }
};

class Derived : public Base {
public:
  Derived() {
    std::cout << "Derived class constructor is called." << std::endl;
  }
  ~Derived() {
    std::cout << "Derived class destructor is called." << std::endl;
  }

  void abstract_method() override {
    std::cout << "abstract_method is implemented in the Derived class "
              << std::endl;
  }

  void derived_method() {
    std::cout << "derived_method is called from Derived class." << std::endl;
  }
};

void function(Abstract &obj) {
  obj.abstract_method();
  obj.default_method();
}

int main() {
  Base b;
  Derived d;
  function(b);
  function(d);
}