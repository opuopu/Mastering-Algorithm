#include <bits/stdc++.h>
using namespace std;

int n, e;
long long adj_mat[105][105];

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX) {
                    if (adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j]) {
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) adj_mat[i][j] = 0;
            else adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (e--) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        if (adj_mat[a][b] > w) {
            adj_mat[a][b] = w;
        }
    }

    floydWarshall();

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        if (adj_mat[a][b] == LLONG_MAX) {
            cout << "-1" << endl;
        } else {
            cout << adj_mat[a][b] << endl;
        }
    }

    return 0;
}
