#include <bits/stdc++.h>
using namespace std;

int main() {
int n,e;
cin >> n >> e;
int adj_mat[n][e];
for(int i = 0; i < n; i++) {
  for(int j = 0; j < e; j++) {
    adj_mat[i][j] = 0; 
  }
}
while(e--){
  int a,b;
  cin >> a >> b;
  adj_mat[a][b] = 1;
  adj_mat[b][a] = 1; 
}
  
  return 0;
}