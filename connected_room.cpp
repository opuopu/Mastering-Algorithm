#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m;
vector<int> rooms;
int counts = 0;
vector<pair<int, int>> moveMents = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool valid(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}
void dfs(int x, int y){
vis[x][y] = true;
counts++;
for(int i = 0; i < 4; i++){
 int ci = x + moveMents[i].first;
 int cj = y + moveMents[i].second;
if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#'){
dfs(ci, cj);

}
}

}

int main() {

memset(vis, false, sizeof(vis));
cin >> n >> m;
for (int i = 0; i < n; i++) {

  for (int j = 0; j < m; j++) {
    cin >> grid[i][j];

  }
}

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(!vis[i][j] && grid[i][j] == '.'){
            counts = 0;
            dfs(i, j);
    rooms.push_back(counts);
        }
    }
  }
sort(rooms.begin(), rooms.end());
if (rooms.size() == 0) {
  cout << 0 << endl;
} else {
  for (int i = 0; i < rooms.size(); i++) {
    cout << rooms[i] << " ";
  }
  cout << endl;
}
  return 0;
}