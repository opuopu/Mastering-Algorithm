#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool visited[1005][1005];
char grid[1005][1005];
// child index order - down, up, right, left
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// check if the cell is valid or not
bool valid(int i, int j){
if(i < 0 || i >= 1005 || j < 0 || j >= 1005) return false;
  return true;
}

void dfs(int si, int sj) {
  cout << si << sj << " ";
  visited[si][sj] = true;
for(int i = 0; i < 4; i++) {
    int ci = si + directions[i].first;
    int cj = sj + directions[i].second;
  if(valid(ci,cj) && !visited[ci][cj]) {
      dfs(ci, cj);
    }
  }
}
int main() {
  
int n, m;
cin >> n >> m;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
    }
  }
  //  getting source coordinates
  int si, sj;
  cin >> si >> sj;
  dfs(si, sj);
  return 0;
}