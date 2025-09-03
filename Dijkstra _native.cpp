#include <bits/stdc++.h>
using namespace std;

// গ্রাফের অ্যাডজাসেন্সি লিস্ট
vector<pair<int, int>> adj[1005];
// প্রতিটি নোডের দূরত্ব
int dist[1005];

// ডাইকস্ট্রা অ্যালগরিদম
void dijkstra(int src) {
  // মিন-হিপ ব্যবহার করা উচিত, এখানে queue ব্যবহার করা হয়েছে, যা ঠিক নয়
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, src}); // {দূরত্ব, নোড}

  dist[src] = 0;

  while (!q.empty()) {
    auto node = q.top();
    q.pop();
    int pare_dist = node.first;
    int pare_node = node.second;

    // যদি বর্তমান দূরত্ব বড় হয়, তাহলে স্কিপ করুন
    if (pare_dist > dist[pare_node]) continue;

    for (auto child : adj[pare_node]) {
      int child_node = child.first;
      int child_dist = child.second;

      // যদি নতুন দূরত্ব ছোট হয়, আপডেট করুন
      if (pare_dist + child_dist < dist[child_node]) {
        dist[child_node] = pare_dist + child_dist;
        q.push({dist[child_node], child_node});
      }
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;

  // এজ ইনপুট নিচ্ছে
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  // সব নোডের দূরত্ব ইনিশিয়ালাইজ করছে
  for (int i = 0; i < n; i++) dist[i] = INT_MAX;

  int src;
  cin >> src; // সোর্স নোড ইনপুট নিন

  dijkstra(src);

  // প্রতিটি নোডের দূরত্ব প্রিন্ট করুন
  for (int i = 0; i < n; i++) {
    cout << "Node " << i << " Distance: " << dist[i] << endl;
  }

  return 0;
}