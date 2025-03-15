#include <iostream>
#include <vector>
using namespace std;

int main() {
  // nodes, edges
  int n, m;
  cin >> n >> m;

  // How it actually works is the edge is at the intersection on row or colum
  // Say there is an edge btw 1 and 2 then int he matrix[1][2] mark as 1
  //  :)

  // Correct way to initialize a 2D adjacency matrix
  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));  // Using vector

  // Storing O(n2)
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    // Mark the intersectiona s 1
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << adjMatrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}