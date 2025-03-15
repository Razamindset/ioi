#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // 1 based indexing
  vector<vector<int>> adjList(n + 1);

  //* Each index store all its relatives

  //* Say 4 has edge to 1 so the list at 4 pushes 1
  //* If indeirected list at 1 also stores 4 as relative

  // Storing 0(N) space complexity-> ?
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    // for a directed graph from u to v only store once
    adjList[u].push_back(v);

    // Store the reverse for an indirected graphs only
    // adjList[v].push_back(u);
  }

  //* Print the list
  for (int i = 0; i < adjList.size(); i++) {
    cout << i << ": ";  // Print the vertex
    for (int j : adjList[i]) {
      cout << j << " ";  // Print its adjacent
    }
    cout << endl;
  }
  return 0;
}