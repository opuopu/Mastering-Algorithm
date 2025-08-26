#include <bits/stdc++.h>
using namespace std;
  int n,e;
vector<int> adj[105];
bool visited[105];
int parent[105];
bool cycle = false;
void bfs(int src){
queue<int> q;
q.push(src);
visited[src] = true;
while(!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";
    for(auto child : adj[node]){
      if(visited[child] && parent[node] != child){
        cycle = true;
      }
    if(!visited[child]){
        q.push(child);
        visited[child] = true;
        parent[child] = node;
    }
}
}
}
int main() {
  
  // your code here
  cin >> n >> e;
  memset(visited, false, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  cycle = false;
  while(e--){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
for(int i = 1; i <= n; i++){
    if(!visited[i]){
        bfs(i);
    }
  }

  return 0;
}