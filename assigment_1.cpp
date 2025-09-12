#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long distances[1005];  
int n, e;  
int src;     
bool cycle = false;

vector<Edge> edge_list; 

void bellman_ford() {
    for(int i = 0; i < n - 1; i++) {
        for(auto edge: edge_list) {
            int a = edge.a;  
            int b = edge.b;
            int c = edge.c;

            if(distances[a] != INT_MAX && distances[a] + c < distances[b]) {
                distances[b] = distances[a] + c; 
            }
        }
    }
    
    for(auto edge: edge_list) {
        int a = edge.a;  
        int b = edge.b;
        long long c = edge.c;

        if(distances[a] != INT_MAX && distances[a] + c < distances[b]) {
            cycle = true;
            return;  
        }
    }
}

int main() {
    cin >> n >> e;

    while(e--) {
        int a, b;
        long long c;
        
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c)); 
    }

    cin >> src;

    for(int i = 1; i <= n; i++) distances[i] = INT_MAX;
    distances[src] = 0; 

    bellman_ford();

    int t;
    cin >> t;

    if(cycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    while(t--){
        int dest;
        cin >> dest;

        if(distances[dest] == INT_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << distances[dest] << endl;
        }
    }

    return 0;
}
