#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;  
int parent[MAX];
int sizes[MAX];
long long cycles = 0;

// parent array ব্যবহার করা হচ্ছে যেটা Union-Find এর জন্য
int find(int a) {
    if (parent[a] == -1)
        return a; // যদি node নিজেই leader হয়, তাহলে return করি
    return parent[a] = find(parent[a]); // path compression
}

// দুটি node কে union করা এবং cycle check করা
void dsu_union(int a, int b) {
    int leaderA = find(a);
    int leaderB = find(b);

    if (leaderA == leaderB) {
        // যদি একই leader হয়, তাহলে এই edge একটি cycle তৈরি করবে
        cycles++; 
        return;
    }

    // Union by size: ছোট tree কে বড় tree এর সাথে merge করি
    if (sizes[leaderA] > sizes[leaderB]) {
        parent[leaderB] = leaderA;
        sizes[leaderA] += sizes[leaderB];
    } else {
        parent[leaderA] = leaderB;
        sizes[leaderB] += sizes[leaderA];
    }
}

int main() {
    // parent এবং sizes array initialize করা
    memset(parent, -1, sizeof(parent)); // -1 means node is its own leader
    memset(sizes, 1, sizeof(sizes));    // initially each component size = 1

    int n, e;
    cin >> n >> e; // n = node সংখ্যা, e = edge সংখ্যা

    // প্রতিটি edge পড়ে union করি এবং cycle count করি
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b); // main logic: cycle detection + union
    }

    // মোট cycle তৈরি করা edge সংখ্যা print করা
    cout << cycles << endl;
    return 0;
}
