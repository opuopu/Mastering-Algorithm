#include <bits/stdc++.h>
using namespace std;

int main() {
  
int n,e;
cin >> n >> e;
vector<int> adj_list[n];
while(e--) {
  int u,v;
  cin >> u >> v;
  adj_list[u].push_back(v);
  adj_list[v].push_back(u);
}
return 0;
}