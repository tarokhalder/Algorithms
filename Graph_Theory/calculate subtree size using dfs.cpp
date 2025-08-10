#include <bits/stdc++.h>

using namespace std;

const int N = 100;

vector <int> G[N];

int Par[N] , vis[N];

int dfs(int node) {
    vis[node] = 1;
    int cnt = 1;
    for (int x : G[node]) {
        if (vis[x] == 0) {
	   cnt += dfs(x);
	}
    }
    Par[node] = cnt;
    return cnt;
}
int main() {
    int node , edge;
    cin >> node >> edge;
    while (edge--) {
        int x , y;
	cin >> x >> y;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= node; i++) {
        cout << i << " " << Par[i] << "\n";
    }
    return 0;
}
