#include <bits/stdc++.h>

using namespace std;

const int N = 100;
vector <int> G[N];
int vis[N] , low[N] , dis[N];

int timer = 1;

void dfs(int node, int par) {
     vis[node] = 1;
     low[node] = dis[node] = timer++;
     for (int x : G[node]) {
        if (x == par) {
	   continue;
	}
	if (vis[x] == 1) {
	   low[node] = min(low[node] , dis[x]);
	} else{
	   dfs(x , node);
	   if (low[x] > dis[node]) {
	      cout << node << " " << x << "\n";
	   }
	   low[node] = min(low[node] , low[x]);
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
    dfs(1 , -1);
}
