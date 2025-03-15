#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Level wise traversal
void bfs(int start, vector<vector<int>> &adjList, vector<bool> &visited) {
  queue<int> q;
  q.push(start);

  visited[start] = true;

  // Say we started from the parent that had 2 neighbours
  // We first visit those two neigbours and mark as visited
  // The we push them into the queue so we can check their neighbours
  // the next oiteration we check one of the neighbours that we pushed prev
  // Keep repeating until all the nodes are visited

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";  // Processing the node

    for (int neig : adjList[node]) {
      if (!visited[neig]) {
        visited[neig] = true;
        q.push(neig);
      }
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

  cout << "BFS Traversal: ";
  bfs(start, adjList, visited);

  return 0;
}