#include <bits/stdc++.h>

using namespace std;

vector <int> G[1000];

int vis[1000];

bool dfs(int node , int par) {
    vis[node] = 1;
    for (int x : G[node]) {
        if (vis[x] == 0) {
	   if (dfs(x , node) == true) {
	       return true;
	   }
	} else {
	   if (x != par) {
	      return true;
	   }
	}
    }
    return false;

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
     if (dfs(1 , -1)) {
         cout << "Cycle" << "\n";
     } else {
         cout << "No cycle" << "\n";
     }
}
