#include <bits/stdc++.h>
using namespace std;
int parent[1005];

int find(int a) {
  if (parent[a] == -1) {
    return a;
  }
  int leader = find(parent[a]);
  return leader;
}
int main() {
  memset(parent, -1, sizeof(parent));
  parent[0] = 1;
  parent[1] = -1;
  parent[2] = 1;
  parent[3] = 1;
  parent[4] = 5;
  parent[5] = 3;

  cout << find(0) << endl;
  return 0;
}