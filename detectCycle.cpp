#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
bool visited[MAX];
vector<int> adj[MAX];
int parent[MAX];
long long cycle  = 0;
void bfs(int src ){
queue<int> q;
q.push(src);
visited[src] = true;
while(!q.empty()){
    int node = q.front();
    q.pop();
 for(auto it: adj[node]){
    if(visited[it] && parent[node] != it){cycle +=1;}
        if(!visited[it]){
            q.push(it);
            visited[it] = true;
            parent[it] = node;
          
        }
  }
}

}
int main() {
int n,e;
cin>>n>>e;
memset(visited,0,sizeof(visited));
memset(parent,-1,sizeof(parent));
for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
for(int i = 0; i < n; i++){
    if(!visited[i]){
        bfs(i);
    }
}

  if(cycle >0){
    cout << cycle/2 << endl;
  }
  return 0;
}