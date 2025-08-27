#include <bits/stdc++.h>

using namespace std;

string findsquare(string a) {
     int n = int(a.size());
     string ans = "-1";
     for (int i = 1; i < (1 << n); i++) {
         string d ="";
	 for (int j = 0; j < n; j++) {
	     if ((i >> j) & 1) {
	        d += a[j];
	     }
	 }
	 if (d[0] != 0) {
	    int s = stoi(d);
	    int r = sqrt(s);
	    if (r * r == s) {
	      if (ans == "-1") {
	         ans = d;
	      }	    
	      else if (d.size() > int(ans.size())) {
	         ans = d;
	      }
	    }
	 }
     }
     return ans;
}

int main() {
    string a;
    cin >> a;
    string d = findsquare(a);
    cout << d << "\n";
}
