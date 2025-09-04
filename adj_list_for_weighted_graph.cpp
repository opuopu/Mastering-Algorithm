#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, e;
  cin >> n >> e;
  vector<vector<pair<int, int>>> adj(n);
  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c}); // for undirected graph
  }
  
  return 0;
}