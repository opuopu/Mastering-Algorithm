#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];

void bfs(int sourceNode, int destinationNode) {
  memset(visited, false, sizeof(visited));
  memset(level, -1, sizeof(level));
  memset(parent, -1, sizeof(parent));

  queue<int> q;
  q.push(sourceNode);
  level[sourceNode] = 0;

  while (!q.empty()) {
    int currentNode = q.front();
    q.pop();
    if (visited[currentNode]) continue;
    visited[currentNode] = true;1;
    for (int neighbor : adj_list[currentNode]) {
      if (!visited[neighbor]) {
        q.push(neighbor);
        level[neighbor] = level[currentNode] + 1;
        parent[neighbor] = currentNode;
      }
    }
  }

  cout << level[destinationNode] << endl;
}

int main() {
  int n, e;
  cin >> n >> e;

  while (e--) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  bfs(0, 6);
  vector<int> path;
  int node = 6;
  while (node != -1) {
    path.push_back(node);
    node = parent[node];
  }
  reverse(path.begin(), path.end());
  for (int n : path) {
    cout << n << " ";
  }
  cout << endl;

  return 0;
}