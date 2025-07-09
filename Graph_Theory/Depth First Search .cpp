#include <bits/stdc++.h>

using namespace std;

vector <int> G[1000];

int vis[1000];

void dfs(int node) {
    vis[node] = 1;
    cout << node << " ";
    for (int x : G[node]) {
        if (vis[x] == 0) {
	   dfs(x);
	}
    }

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
}
