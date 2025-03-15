#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Completes one branch to the end and backtracks
void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
  /*
   * IN comparison to dfs it does not look at the next neighbour at the same
   * time instead we take one neighbour and its one child and keep calling until
   * we reach end then we backtrack and do it for the other node
   */
  cout << node << " ";
  visited[node] = true;

  // Visit all unvisited neighbors
  for (int neighbor : adjList[node]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adjList, visited);
    }
  }
}

int main() {
  int m, n;
  cin >> n >> m;

  vector<vector<int>> adjList(n);

  vector<bool> visited(n, false);

  // Store the graph
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);  // Undirected graph
  }

  int start;
  cin >> start;

  cout << "DFS Traversal: ";
  dfs(start, adjList, visited);

  return 0;
}