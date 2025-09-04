#include <bits/stdc++.h>
using namespace std;

int n, m;
int s1, s2, d1, d2;   // শুরু (R) আর গন্তব্য (D) এর coordinate
char grid[1005][1005];
bool vis[1005][1005];
pair<int,int> current;
pair<int,int> parent[1005][1005];

// Right, Left, Up, Down order
vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

// coordinate valid কিনা তা চেক করার ফাংশন
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// BFS দিয়ে shortest path খুঁজে বের করা
void bfs(int s1, int s2) {
    queue<pair<int, int>> q;

    // যদি শুরু পজিশনই Destination হয়
    if(grid[s1][s2] == 'D'){
        d1 = s1; d2 = s2;
        return;
    }

    q.push({s1, s2});
    vis[s1][s2] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // চারদিকে move করার চেষ্টা
        for (auto d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;

            if (valid(nx, ny) && !vis[nx][ny]) {
                if (grid[nx][ny] == 'D') {
                    // Destination পাওয়া গেলে parent ট্র্যাক করে রাখি
                    parent[nx][ny] = {x, y};
                    d1 = nx; d2 = ny;
                    return;
                }
                if (grid[nx][ny] == '.') {
                    // এখনো visit হয়নি এমন খালি cell
                    vis[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    // Input নেওয়া
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){  
                // Rezia-এর starting position save করা
                s1 = i;
                s2 = j;
            }
        }
    }

    // BFS চালানো
    bfs(s1, s2);

    // এখন destination থেকে শুরু করে path reconstruct করা হবে
    current = {d1, d2};

    // যদি সত্যিই কোনো path পাওয়া যায় (destination পাওয়া গেছে)
    if (grid[d1][d2] == 'D') {
        while (current.first != s1 || current.second != s2) {
            // '.' হলে সেটাকে path হিসেবে 'X' মার্ক করে দিই
            if (grid[current.first][current.second] == '.') {
                grid[current.first][current.second] = 'X';
            }
            // এক ধাপ পেছনে parent এর দিকে move করি
            current = parent[current.first][current.second];
        }
    }

    // Final maze print করা
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
