#include <bits/stdc++.h>
using namespace std;

// Edge ক্লাস যা একটি এজের সূচনা নোড, গন্তব্য নোড এবং ওজন রাখে
class Edge {
public:
  int a, b, c; // a = start node, b = end node, c = weight
  Edge(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};

int main() {
  vector<Edge> edge_list; // এজগুলোর তালিকা রাখার জন্য
  int distance[1005];     // প্রতিটি নোড পর্যন্ত দূরত্ব রাখার জন্য
  int n, e;               // n = নোড সংখ্যা, e = এজ সংখ্যা
  cin >> n >> e;

  // এজ ইনপুট নেওয়া
  while(e--) {
    int a, b, c;
    cin >> a >> b >> c;
    edge_list.push_back(Edge(a, b, c)); // এজ লিস্টে যোগ করা
  }

  // প্রতিটি নোডের দূরত্ব ইনিশিয়ালাইজ করা (INT_MAX = অসীম)
  for(int i = 0; i < n; i++) distance[i] = INT_MAX;
  distance[0] = 0; // স্টার্ট নোডের দূরত্ব 0

  // Bellman-Ford অ্যালগরিদম: n-1 বার সব এজ রিল্যাক্স করা
  for(int i = 0; i < n - 1; i++) {
    for(auto edge: edge_list) {
      int a = edge.a;
      int b = edge.b;
      int c = edge.c;

      // যদি নোড a পৌঁছানো যায় এবং distance আপডেট করা যায়
      if(distance[a] != INT_MAX && distance[a] + c < distance[b]) {
        distance[b] = distance[a] + c; // দূরত্ব আপডেট
      }
    }
  }

  // সকল নোডের দূরত্ব প্রিন্ট করা
  for(int i = 0; i < n; i++) {
    if(distance[i] == INT_MAX) 
      cout << "INF "; // যদি নোডটি পৌঁছানো যায়নি
    else 
      cout << distance[i] << " ";
  }
  cout << endl;

  return 0;
}
