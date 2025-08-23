#include <bits/stdc++.h>
using namespace std;
  vector<int> adj_list[1005];
  vector<bool> visited(1005, false);
  int level[1005]={-1};
void bfs(int sourceNode, int destinationNode){
queue<int> q;
q.push(sourceNode);
level[sourceNode] = 0;
while(!q.empty()){
  int currentNode = q.front();
  q.pop();
  if(visited[currentNode]) continue;
  visited[currentNode] = true;
  for(int neighbor : adj_list[currentNode]){
    if(!visited[neighbor]){
      q.push(neighbor);
      level[neighbor] = level[currentNode] + 1;
    }
  }
}

cout << level[destinationNode] << endl;
}


int main() {
  int n, e;
  cin >> n >> e;

  while(e--) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  bfs(0,6);
  return 0;
}