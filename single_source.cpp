#include <bits/stdc++.h>
using namespace std;

// Adjacency list to store the graph
vector<int> adj_list[1005];

// Visited array to keep track of visited nodes during BFS
vector<bool> visited(1005, false);

// Level array to store the shortest distance from source to each node
int level[1005] = {-1};

// Breadth-First Search function to find shortest path from sourceNode to destinationNode
void bfs(int sourceNode, int destinationNode) {
  queue<int> q;
  q.push(sourceNode);
  level[sourceNode] = 0; // Level of source node is 0

  while(!q.empty()) {
    int currentNode = q.front();
    q.pop();

    // Skip if already visited
    if(visited[currentNode]) continue;
    visited[currentNode] = true;

    // Traverse all neighbors of currentNode
    for(int neighbor : adj_list[currentNode]) {
      if(!visited[neighbor]) {
        q.push(neighbor);
        level[neighbor] = level[currentNode] + 1; // Update level (distance)
      }
    }
  }

  // Output the shortest distance from sourceNode to destinationNode
  cout << level[destinationNode] << endl;
}

int main() {
  int n, e;
  cin >> n >> e; // Read number of nodes and edges

  // Read all edges and build the adjacency list
  while(e--) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u); // Since the graph is undirected
  }

  // Find shortest path from node 0 to node 6 using BFS
  bfs(0, 6);

  return 0;
}