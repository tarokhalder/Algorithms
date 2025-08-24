#include <bits/stdc++.h>

using namespace std;

const int N = 100;

vector <int> G[N];

int vis[N] , low[N] , in[N];

int timer = 0;

void dfs(int node , int par) {
     vis[node] = 1;
     low[node] = in[node] = ++timer;
     int cnt = 0;
     for (int x : G[node]) {
         if (x == par) {
	    continue;
	 }
	 if (vis[x] == 1) {
	      low[node] = min(low[node] , in[x]);
	 } else{
	      dfs(x , node);
	      cnt += 1;
	      low[node] = min(low[node] , low[x]);
	      if (low[x] >= in[node] && par != -1) {
	          cout << node << "\n";
	      }
	 }
     }
     if (par == -1 && cnt > 1) {
        cout << node << "\n";
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
    //print lowest time and end time
    //for (int i = 1; i <= node; i++) {
       // cout << i << " " << low[i] << " " <<in[i] << "\n";
    //}
    return 0;
}
