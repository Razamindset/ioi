#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int u, v, w;
};
const int INF = 1e9;

void bellmanFord(int n, int m, vector<Edge> &edges, int start) {
  // Each index corresponds to the u and v values
  vector<int> distance(n, INF);
  distance[start] = 0;

  for (int i = 0; i < n - 1; i++) {
    // Go across all edges in each iteration
    for (auto edge : edges) {
      // Very imp: If you haven't reached a edge yet there is no point in
      // checking its distance
      // Check if dist is not inf and the new weight is better
      if (distance[edge.u] != INF &&
          distance[edge.u] + edge.w < distance[edge.v]) {
        // The new distance to reach v is better than the prev one
        distance[edge.v] = distance[edge.u] + edge.w;
      }
    }
  }

  // We can check for negative weight cycles here
  // If we add the edge weight to already computed shorter ditance and the
  // value decreases this means that there is a negative weight cycle
  for (auto edge : edges) {
    if (distance[edge.u != INF && edge.w + edge.u < distance[edge.v]]) {
      cout << "Detected a negative weight cylce \n";
    }
  }

  // Print distances
  for (int i = 0; i < n; i++) {
    cout << "To " << i << " : " << (distance[i] == INF ? -1 : distance[i])
         << "\n";
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  // m number of edges
  vector<Edge> edges(m);

  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  // Starting node is the position where the process begins
  int start;
  cin >> start;

  bellmanFord(n, m, edges, start);

  return 0;
}