#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 , M = 20;

vector <int> G[N];

int Par[N][M] , dep[N];

void dfs(int node , int par) {	
      dep[node] = dep[par] + 1;
      Par[node][0] = par;
      for (int j = 1; j < M; j++) {
          Par[node][j] = Par[Par[node][j - 1]][j - 1];
      }
      for (int x : G[node]) {
          if (x != par) {
	     dfs(x , node);
	  }
      }
}

int LCA(int x , int y) {
    if (x == y) {
       return x;
    }
    if (dep[x] > dep[y]) {
        swap(x , y);
    }
    int dif = dep[y] - dep[x];
    for (int j = M - 1; j >= 0; j--) {
        if ((dif >> j) & 1) {
	   y = Par[y][j];
	}
    }
    for (int j = M - 1; j >= 0; j--) {
        if (Par[x][j] != Par[y][j]) {
	    x = Par[x][j];
	    y = Par[y][j];
	}
    }
    return Par[x][0];

}

int main() {
    int node ,edge;
    cin >> node >> edge;
    while (edge--) {
        int x , y;
	cin >> x >> y;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(1 , 0);
    
    return 0;

}
