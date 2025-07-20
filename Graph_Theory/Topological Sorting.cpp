#include <bits/stdc++.h>

using namespace std;

#define N 1000

vector <int> G[N];

int indegree[N];

vector <int> top_sort(int node) {
    vector <int> ans;
    queue <int> q;
    for (int i = 1; i <= node; i++) {
       if (indegree[i] == 0) {
          q.push(i);
       }
    }
    while (!q.empty()) {
       int cur = q.front();
       q.pop();
       ans.push_back(cur);
       for (int x : G[cur]) {
          indegree[x]--;
	  if (indegree[x] == 0) {
	     q.push(x);
	  }
       }
    }
    return ans;
}

int main() {
    int node , edge;
    cin >> node >> edge;
    while (edge--) {
        int x , y;
	cin >> x >> y;
	G[x].push_back(y);
	indegree[y]++;
    }
    vector <int> a = top_sort(node);
    for (int x : a) {
       cout << x << " ";
    }
    cout << "\n";
    return 0;

}
