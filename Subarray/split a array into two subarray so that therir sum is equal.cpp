#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    int left_sum = 0;
    for (int i = 0; i < n; i++) {
        left_sum += a[i];
    }
    int right_sum = 0;
    bool ok = true;
    for (int i = n-1; i >= 0; i--) {
        right_sum += a[i];
	left_sum -= a[i];
	if (left_sum == right_sum) {
	    cout << "find" << "\n";
	    ok = false;
	}
    }
    if (ok) {
       cout << "NO" << "\n";
    }
    return 0;
}
