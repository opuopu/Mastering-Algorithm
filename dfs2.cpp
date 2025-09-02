#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1005][1005];  
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}}; // 4 directions

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, vector<vector<int>>& grid) {
    vis[x][y] = true;

    for(auto [dx, dy] : d) {
        int nx = x + dx;
        int ny = y + dy;
        if(valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == 1) {
            dfs(nx, ny, grid);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int components = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                dfs(i, j, grid);
                components++; // count connected component
            }
        }
    }

    cout << "Number of connected components: " << components << "\n";
    return 0;
}
