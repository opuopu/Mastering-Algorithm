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
for(int i = 0; i < e; i++) {
  for(int j = 0; j < 2; j++) {
 if(i==j){
adj_mat[i][j] = 1;
 }
  }
}

  int a,b;
  cin >> a >> b;
  adj_mat[a][b] = 1;
  adj_mat[b][a] = 1; 


  
  return 0;
}