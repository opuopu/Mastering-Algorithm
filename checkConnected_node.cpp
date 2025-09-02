#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int node){
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
dfs(0);
int q;
cin >> q;
while(q--){
  int node;
  cin >> node;
    if(!adj_list[node].empty()){
      vector<int> temp = adj_list[node];
      sort(temp.begin(), temp.end(), greater<>());
      for(int neighbor: temp){
        cout << neighbor << " ";
      }
  
    }
    else{
      cout << -1 << " ";
    }
     cout << endl;

}




  return 0;
}

