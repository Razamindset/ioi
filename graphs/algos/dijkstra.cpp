#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1e9;

void dijkstra(int start, vector<vector<pair<int, int>>> &adjList,
              vector<int> &distance) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // Source to source will always be 0
  distance[start] = 0;
  pq.push({0, start});  // distance and node

  while (!pq.empty()) {
    int currenDist = pq.top().first;
    int currentNode = pq.top().second;
    pq.pop();

    // If a better approcah exists
    if (currenDist > distance[currentNode]) continue;

    // Go through all the neighbours
    for (auto &edge : adjList[currentNode]) {
      int neighbour = edge.first;
      int weight = edge.second;

      // If the new distance is better than rewrite
      if (distance[currentNode] + weight < distance[neighbour]) {
        distance[neighbour] = distance[currentNode] + weight;
        pq.push({distance[neighbour], neighbour});
      }
    }
  }
}

int main() {
  int n, m;

  cin >> n >> m;

  // Initilize a linked list
  vector<vector<pair<int, int>>> adjList(n);

  // distance array
  vector<int> distance(n, INF);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});  // Undirected graph
  }

  int start;
  cin >> start;

  dijkstra(start, adjList, distance);

  // Print distances
  cout << "Shortest distances from node " << start << ":\n";
  for (int i = 0; i < n; i++) {
    cout << "To " << i << " : " << (distance[i] == INF ? -1 : distance[i])
         << "\n";
  }

  return 0;
}