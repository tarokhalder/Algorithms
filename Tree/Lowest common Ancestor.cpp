#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector <int> G[N];

int Par[N] , dep[N];

void dfs(int node ,int par) {
     Par[node] = par;
     dep[node] = dep[par] + 1;
     for (int x : G[node]) {
         if (x != par) {
	    dfs(x , node);
	 }
     }
}

int LCA(int u , int v){
    if (u == v) {
       return u;
    }
    if (dep[u] > dep[v]) {
       swap(u , v);
    }
    int dif = dep[v] - dep[u];
    while (dif--){ 
        u = Par[u];
    }
    while (u != v) {
       u = Par[u];
       v = Par[v];
    }
    return u;
}
int main() {
    int node ,edge;
    cin >> node >> edge;
    while (edge--){ 
        int x , y;
	cin >> x >> y;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(1 , 0);
    cout << LCA(8 , 9) << "\n";
}
