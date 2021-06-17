// randomizable
#include <initializer_list>
#include <iostream>
#include <type_traits>

template <typename T> class List {

  struct Node {
    Node *next{nullptr};
    T data;

    Node(T i_data) : data(i_data) {}
    Node() = default;
  };

  Node *front{nullptr}, *back{nullptr};
  size_t m_size{0};

public:
  List(std::initializer_list<T> _list) {
    for (auto i : _list)
      add_back(i);
  }

  ~List() {
    if (!is_empty())
      clear();
  }

  void add_back(T data) {
    Node *node = new Node(data);
    if (is_empty()) {
      front = node;
      back = node;
    } else {
      back->next = node;
      back = node;
    }
    m_size += 1;
  }

  void add_front(T data) {
    Node *node = new Node(data);
    if (is_empty()) {
      front = node;
      back = node;
    } else {
      node->next = front;
      front = node;
    }
    m_size += 1;
  }

  void remove(T data) {
    if (is_empty())
      return;
    if (front->data == data)
      remove_front();

    else {
      Node *ptr{front};
      Node *prev{front};

      while (ptr->next != null) {
        if (prev->data == data) {
          prev->next = ptr->next;

          m_size -= 1;
          return;
        }

        prev = ptr;
        ptr = ptr->next;
      }

      throw std::exception();
    }
  }

  void display() const {
    Node *ptr{front};
    while (ptr->next != nullptr) {
      std::cout << ptr->data << ", ";
      ptr = ptr->next;
    }
  }

  void sort() {
    Node *array = new Node *[m_size];
    // make references to node->next: O(N)
    for (size_t i = 0, Node * ptr{front}; i < m_size && ptr->next != nullptr;
         ptr = ptr->next, ++i) {
      array[i] = ptr;
    }
    // sorting
    for (int i = 0; i < size - 1; i++) {
      int min = i;
      for (int j = i + 1; j < size; j++)
        if (arr[j] < arr[min])
          min = j;
      std::swap(*arr[i], *arr[min]);
    }
  }

  void clear() {
    Node *ptr{front};
    Node *temp{nullptr};

    while (ptr->next != nullptr) {
      temp = ptr;
      delete temp;
      temp = nullptr;
      ptr = ptr->next;
    }
    m_size = 0;
  }

  bool is_empty() const { return front == nullptr && back == nullptr; }
  size_t size() const { return m_size; }

private:
  void remove_front() {
    Node *temp{front};
    front = front->next;

    delete temp;
    temp = nullptr;
    m_size -= 1;
  }
};

// template <typename T, typename list_type = List<T>> class randomizeable {
//   typedef Node<T> Node;

//   Node *ptr{nullptr};

//   randomizeable(size_t size) { ptr = new Node *[size]; }

//   ~randomizeable { delete[] ptr; }

//   const Node &operator[](size_t idx) const {
//     try {
//       if (idx < 0 || idx < size)
//         throw std::exception();

//       return m_ptr[idx];
//     } catch (const std::exception &e) {
//       std::cerr << str << std::endl;
//       exit(1);
//     }
//   }

//   Node &operator[](size_t idx) {
//     try {
//       if (idx < 0 || idx < size)
//         throw std::exception();

//       return m_ptr[idx];
//     } catch (const std::exception &e) {
//       std::cerr << str << std::endl;
//       exit(1);
//     }
//   }
// };