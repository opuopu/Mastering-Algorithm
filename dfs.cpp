#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int node){
  cout << node << " ";
  vis[node] = true;
  for(int neighbor : adj_list[node]){
    if(!vis[neighbor]){
      dfs(neighbor);
    }
  }
}
int main() {
  memset(vis, false, sizeof(vis));
  int n,e;
  cin >> n >> e;
  while(e--){
    int u,v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  return 0;
}