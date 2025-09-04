#include <bits/stdc++.h>
using namespace std;
char  adj_list[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}}; 
vector<int> component_sizes;
int component_size = 0;
  int n,e;
  int s1,s2;
  bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < e);
}
void dfs(int s1,int s2){
  vis[s1][s2] = true;
  component_size++;
  for(auto [x,y]:d){
    int sx = s1 + x;
    int sy = s2 + y;
    if(valid(sx,sy) && !vis[sx][sy] && adj_list[sx][sy] == '.') {
      dfs(sx,sy);
    }
  }
}

int main() {

  memset(vis, false, sizeof(vis));
  cin >> n >> e;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < e; j++) {
      char x;
      cin >> x;
      adj_list[i][j] = x;
    }
  }
  cin >> s1 >> s2;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < e; j++) {

     if(!vis[i][j] && adj_list[i][j] == '.') {
        component_size = 0;
        dfs(i,j);
        component_sizes.push_back(component_size);
      }
    }
  }
sort(component_sizes.begin(), component_sizes.end());
if(!component_sizes.empty()) {
  cout << component_sizes[0] << endl;
}
else {
  cout << -1 << endl;

}

}