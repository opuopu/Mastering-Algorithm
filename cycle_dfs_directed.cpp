#include <bits/stdc++.h>
using namespace std;
  int n,e;
vector<int> adj[105];
bool visited[105];
bool path[105];
bool cycle = false;
void dfs(int src){
visited[src] = true;
path[src] = true;
    for(auto child : adj[src]){
      if(path[child] && visited[child]){
        cycle = true;
        return;
      }
    if(!visited[child]){
           dfs(child);
    }
}
path[src] = false;
}

int main() {
  

  cin >> n >> e;
  memset(visited, false, sizeof(visited));
  memset(path, false, sizeof(path));
  cycle = false;
  while(e--){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
for(int i = 1; i <= n; i++){
    if(!visited[i]){
        dfs(i);
    }
  }

  return 0;
}