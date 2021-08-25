#include <iostream>

class String {
public:
  String() = default;
  String(const char *string) {
    std::cout << "string is created \n";
    m_size = strlen(string);
    m_data = new char[m_size];
    memcpy(m_data, string, m_size);
  }

  // move constructor -- shallow copy
  String(String &&other) noexcept {
    printf("moved\n");
    m_size = other.m_size;
    m_data = other.m_data; // modifies the pointer
    // sets to a hollow object so destructor destroys the hollow object
    other.m_data = nullptr;
    other.m_size = 0;
  }
  // copy constructor -- deep copy
  String(const String &other) {
    std::cout << "copied \n";
    m_size = strlen(other.m_size);
    m_data = new char[m_size];
    memcpy(m_data, other.m_data, m_size);
  }

  ~String() { delete m_data; }

  void println() {
    for (uint32_t i = 0; i < m_size; ++i)
      printf("%c", m_data[i]);

    printf("\n");
  }

private:
  char *m_data;
  uint32_t m_size;
};

class Entity {
public:
  Entity(const String &name) : m_name(name) {}
  Entity(String &&name)
      : m_name(std::move(name)) {} // rvalue reference constructor
  void print_name() { m_name.println(); }

private:
  String m_name;
};

int main() {
  Entity entity(String("Bean"));

  return 0;
}