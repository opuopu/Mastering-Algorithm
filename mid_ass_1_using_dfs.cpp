#include <bits/stdc++.h>
using namespace std;
char  adj_list[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}}; 

  int n,e;
  int s1,s2;
  int d1,d2;
  bool flag;

  bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < e);
}
void dfs(int s1,int s2){
if(s1==d1 && s2==d2) {
  flag = true;
  return;
}
  vis[s1][s2] = true;
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
  cin >> d1 >> d2;
  dfs(s1,s2);

  if(flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}