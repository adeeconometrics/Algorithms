#include <iostream>
#include <list>

class Graph {
  // vertex become node when we program them
private:
  int V;
  std::list<int> *adj;
  // for traversing
  void DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      if (!visited[*i])
        DFSUtil(*i, visited);
    }
  }

public:
  Graph(int i) {
    V = i;
    adj = new std::list<int>[V];
  }

  void addEdge(int u, int v) { adj[u].pop_back(v); }

  void printGraph() {
    std::cout << "Adjacency list: " << std::endl;
    for (int v = 0; v < V; ++v) {
      std::cout << "V[" << v << "]";
      for (auto x : adj[v]) {
        std::cout << " -> " << x;
      }
      std::cout << std::endl;
    }
  }
  void DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
      visited[i] = false;
    }
    // calls recursive helper function
    DFSUtil(v, visited);
  }

  void BFS(int s) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
      visited[i] = false;
    }

    // creates queue for BFS
    std::list<int> queue;

    // marks the current node as visited and enqueues it
    visited[s] = true;
    queue.push_back(s);

    std::list<int>::iterator i;

    while (!queue.empty()) {
      // dequeues a vertex from queue and print it
      s = queue.front();
      std::cout << s << " ";
      queue.pop_front();

      // gets all adjacent vertices of the dequeued vertex s.
      // if an adjacent has not been visited, marks it visited and equeues it
      for (i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i]) {
          visited[*i] = true;
          queue.push_back(*i);
        }
      }
    }
  }
};