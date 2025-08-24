#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
int adj[1001][1001];
  memset(adj, 0, sizeof(adj));
  for(int i = 0; i < r; i++) adj[i][i] = 1;
  for(int i = 0; i < c; i++) {
  int a,b;
  cin >> a >> b;
  adj[a][b] = 1;
  }
  
int q;
cin >> q;
while(q--) {
int x, y;
cin >> x >> y;
if(adj[x][y] == 1) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

}
  return 0;
}