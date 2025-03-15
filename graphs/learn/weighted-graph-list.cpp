#include <iostream>
#include <vector>
using namespace std;

class Pair {
 public:
  int node;
  int edge;

  // Constructor
  Pair(int node, int weight) {
    this->node = node;
    this->edge = weight;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  // Each linked item will store a pair and ege and a node
  vector<vector<Pair>> adjList(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adjList[u].push_back(Pair(v, w));
    adjList[v].push_back(Pair(u, w));  // Undirected Graph comment for directed
  }

  // Printing the list

  // Print adjacency list
  for (int i = 0; i < n; i++) {
    cout << "Node " << i << ": ";
    for (auto &p : adjList[i]) {
      cout << "(" << p.node << ", " << p.edge << ") ";
    }
    cout << "\n";
  }

  return 0;
}