#include <iostream>
#include <list>
#include <string>

template <typename T> class graph {
private:
  int vertex_size;
  std::list<T> *adj;
  void DFS_traverse(const T &v, bool visited[]) {
    visited[v] = true;
    for (std::list<T>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
      if (!visited[*it])
        DFS_traverse(*it, visited);
    }
  }

public:
  graph(int size) {
    vertex_size = size;
    adj = new std::list<T>[size];
  }

  void print() {
    for (int i = 0; i < vertex_size; ++i) {
      std::cout << "v[" << i << "]: ";
      for (std::list<T>::iterator it = adj[i].begin(); it != adj[i].end();
           ++it) {
        std::cout << adj[*it].front() << " -> ";
      }
    }
  }

  void DFS(const T &v) {
    bool *visited = new bool[vertex_size];
    for (int i = 0; i < vertex_size; i++) {
      visited[i] = false;
    }
    DFS_traverse(v, visited);
  }

  void BFS(const T &v) {}
  void add_edge(const T &v, const int &u) { adj[v].push_back(u); }
  void add_vertex();
  void remove_vertex();
  void add_edge();
  void remove_edge();
  void set_vertex_value();

  int get_vertex_value();
  int path_lenght();

  bool is_adjacent(const T &G, const int &x, const int &y);
  bool is_cyclic();
  bool is_complete();
  bool is_connected();
};