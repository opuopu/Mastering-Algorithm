#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m;

vector<pair<int, int>> moveMents = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ac, ar, bc,br;
bool Flag  = false;
bool valid(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}
void dfs(int x, int y){
vis[x][y] = true;
if(x == bc && y == br){
  Flag = true;
  return;
}
for(int i = 0; i < 4; i++){
 int ci = x + moveMents[i].first;
 int cj = y + moveMents[i].second;
if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#'){
dfs(ci, cj);
}
}
}
int main() {
  

cin >> n >> m;

for (int i = 0; i < n; i++) {

  for (int j = 0; j < m; j++) {
    cin >> grid[i][j];
    if (grid[i][j] == 'A') {
      ac = i;
      ar = j;
    } else if (grid[i][j] == 'B') {
      bc = i;
      br = j;
    }
  }
}

  dfs(ac, ar);

  if(Flag){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}