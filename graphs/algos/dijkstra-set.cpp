#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int INF = 1e9;

void dijkstra(int start, vector<vector<pair<int, int>>> &adjList,
              vector<int> &distance) {
  set<pair<int, int>> s;  // {distance, node}

  // Source to source will always be 0
  distance[start] = 0;
  s.insert({0, start});  // distance and node

  while (!s.empty()) {
    auto it = s.begin();  // Get the node with the smallest distance
    int currDist = it->first;
    int currNode = it->second;
    s.erase(it);  // Remove it from the set

    // If a better approcah exists
    if (currDist > distance[currNode]) continue;

    // Go through all the neighbours
    for (auto &edge : adjList[currNode]) {
      int neighbor = edge.first;
      int weight = edge.second;

      // If the new distance is better than rewrite
      if (distance[currNode] + weight < distance[neighbor]) {
        // If the node is already in the set, remove it
        s.erase({distance[neighbor], neighbor});

        distance[neighbor] = distance[currNode] + weight;
        s.insert({distance[neighbor], neighbor});
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