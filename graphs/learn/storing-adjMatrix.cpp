#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // How it actually works is the edge is at the intersection on row or colum
  // Say there is an edge btw 1 and 2 then int he matrix[1][2] mark as 1
  //  :)

  // If 0 based indexing
  // Intilize a 2d array with 0 as all values
  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));  // Using vector

  // Storing O(n2)
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    // Mark the intersectiona s 1
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << adjMatrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}