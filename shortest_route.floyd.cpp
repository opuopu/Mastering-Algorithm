#include <bits/stdc++.h>
using namespace std;
long long int adj_mat[1005][1005];
long long int n,e,q;


void floyd_warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j] && adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX) {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }
}

int main() {
cin>>n>>e;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j) adj_mat[i][j]=0;
        else adj_mat[i][j]=LLONG_MAX;
    }
}
while(e--){

    int a,b,c;
    cin>>a>>b>>c;
   if(adj_mat[a][b]>c){
    adj_mat[a][b]=c;
    adj_mat[b][a]=c;
}
}
floyd_warshall();
cin>>q;
while(q--){
long long int s,d;
cin>>s>>d;
if(adj_mat[s][d]==LLONG_MAX) cout<<"-1\n";
else cout<<adj_mat[s][d]<<"\n";
}


  return 0;
}