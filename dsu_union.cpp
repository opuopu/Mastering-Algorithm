#include <bits/stdc++.h>
using namespace std;
int parent[1005];
int sizes[1005];
int find(int a) {
  if (parent[a] == -1) {
    return a;
  }
  int leader = find(parent[a]);
  parent[a] = leader; // Path compression optimization
  return leader;
}
void dsu_union(int a, int b) {
  int leaderA = find(a);
  int leaderB = find(b);
  if (sizes[leaderA] > sizes[leaderB]) {
   parent[leaderB] = leaderA;
   sizes[leaderA] += sizes[leaderB];
  } else {
   parent[leaderA] = leaderB;
   sizes[leaderB] += sizes[leaderA];
  }
}
int main() {
  memset(parent, -1, sizeof(parent));
  memset(sizes, 1, sizeof(sizes));
  dsu_union(0, 1);

  cout << find(5) << endl;
  return 0;
}