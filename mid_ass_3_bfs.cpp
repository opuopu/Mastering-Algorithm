#include <bits/stdc++.h>
using namespace std;
  int n,e;
int dist_arr[1005][1005];
bool vis[1005][1005];
int dist;
vector<pair<int,int>> dir = {
    {-2,-1}, {-2,1}, {-1,-2}, {-1,2},
    {1,-2}, {1,2}, {2,-1}, {2,1}
};
int k1,k2;
int q1,q2;
int steps;
  bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < e);
}
void bfs(int k1, int k2) {
  queue<pair<int, int>> q;
  if(k1  == q1 && k2 ==q2){
  steps  =  dist_arr[k1][k2];
  return;
  }
  q.push({k1, k2});
  vis[k1][k2] = true;
  dist_arr[k1][k2] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto d : dir) {
      int nx = x + d.first;
      int ny = y + d.second;

      if (valid(nx, ny) && !vis[nx][ny]) {
        vis[nx][ny] = true;
        dist_arr[nx][ny] = dist_arr[x][y] + 1;
  if(nx == q1 && ny == q2){
    steps = dist_arr[nx][ny];
    return;
}
        q.push({nx, ny});
      }  
    }
  }
}
int main() {


  int t;
cin >> t;

while(t--){
  memset(vis, false, sizeof(vis));
memset(dist_arr, 0, sizeof(dist_arr));
steps = -1;
    cin >> n >> e;
  cin >> k1 >> k2 >> q1 >> q2;
  bfs(k1, k2);
  cout << steps << endl;

}


} 