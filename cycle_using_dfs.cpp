#include <bits/stdc++.h>
using namespace std;
  int n,e;
vector<int> adj[105];
bool visited[105];
int parent[105];
bool cycle = false;
void dfs(int src){
visited[src] = true;

    for(auto child : adj[src]){
   if(visited[child] && parent[src] != child){
        cycle = true;
        return;
      }
    if(!visited[child]){
        parent[child] = src;
           dfs(child);
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
        dfs(i);
    }
  }

  return 0;
}