#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m;
int apartmentCount = 0;
vector<pair<int, int>> moveMents = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool valid(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}
void dfs(int x, int y){
vis[x][y] = true;

for(int i = 0; i < 4; i++){
 int ci = x + moveMents[i].first;
 int cj = y + moveMents[i].second;
if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#'){
dfs(ci, cj);
}
}

}
/**
 * @brief Main function to count the number of connected rooms (apartments) in a grid.
 *
 * This program reads a grid of size n x m, where each cell can be either '.' (empty space) or another character (wall).
 * It uses depth-first search (DFS) to find and count all connected components of empty spaces, treating each as a separate apartment.
 * The grid and a visitation matrix are initialized, and for each unvisited empty cell, DFS is performed to mark all reachable cells.
 * The total number of connected apartments is printed at the end.
 *
 * Steps:
 * 1. Initialize the visitation matrix to false.
 * 2. Read the grid dimensions and the grid itself.
 * 3. For each cell, if it is an unvisited empty space, perform DFS and increment the apartment count.
 * 4. Output the total number of apartments found.
 *
 * @return int Returns 0 upon successful completion.
 */
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
            dfs(i, j);
            apartmentCount++;
        }
    }
  }
  cout << apartmentCount << endl;
  return 0;
}