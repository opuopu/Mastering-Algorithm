#include <bits/stdc++.h>
using namespace std;
class Edge {
public:
  int a, b, c; // a = start node, b = end node, c = weight
  Edge(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};

  int distances[1005];     // প্রতিটি নোড পর্যন্ত দূরত্ব রাখার জন্য
  int n, e;  
  int src;         // n = নোড সংখ্যা, e = এজ সংখ্যা
  bool cycle = false; // নেগেটিভ সাইকেল আছে কিনা তা চেক করার জন্য
// Edge ক্লাস যা একটি এজের সূচনা নোড, গন্তব্য নোড এবং ওজন রাখে
  vector<Edge> edge_list; // এজগুলোর তালিকা রাখার জন্য

void bellman_ford() {

    for(int i = 0; i < n - 1; i++) {
        for(auto edge: edge_list) {
            int a = edge.a;  
            int b = edge.b;
            int c = edge.c;

            // যদি নোড a পৌঁছানো যায় এবং distance আপডেট করা যায়
            if(distances[a] != INT_MAX && distances[a] + c < distances[b]) {
                distances[b] = distances[a] + c; // দূরত্ব আপডেট
            }
        }
    }

            for(auto edge: edge_list) {
            int a = edge.a;  
            int b = edge.b;
            int c = edge.c;

            // যদি নোড a পৌঁছানো যায় এবং distance আপডেট করা যায়
            if(distances[a] != INT_MAX && distances[a] + c < distances[b]) {
               cycle = true; // নেগেটিভ সাইকেল পাওয়া গেছে
            }
        }
}
int main() {

  cin >> n >> e;

  // এজ ইনপুট নেওয়া
  while(e--) {
    int a, b, c;
    cin >> a >> b >> c;
    edge_list.push_back(Edge(a, b, c)); 
  }

cin >> src;
  // প্রতিটি নোডের দূরত্ব ইনিশিয়ালাইজ করা (INT_MAX = অসীম)
  for(int i = 0; i < n; i++) distances[i] = INT_MAX;
  distances[src] = 0; // স্টার্ট নোডের দূরত্ব 0
  int t;
  cin >> t;
 bellman_ford();
  while(t--){
    int distance;
    cin >> distance;
    if(cycle) {
      cout << "Negative Cycle Detected" << endl;
      continue;
    }
    if(src == distance) {
      cout << 0 << endl;
    } else {
      if(distances[distance] == INT_MAX) {
        cout << "Not Possible" << endl;
      } else {
        cout << distances[distance] << endl;
      }
}
  }


  // // সকল নোডের দূরত্ব প্রিন্ট করা


  return 0;
}
