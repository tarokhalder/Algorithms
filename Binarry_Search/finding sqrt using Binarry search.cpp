#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int main() {
    double x;
    cin >> x;
    double lo = 1 , hi = x;
    while (hi - lo > eps) {
         double mid = (lo + hi) / 2;
	 if (mid * mid < x) {
	     lo = mid;
	 }else {
	     hi = mid;
	 }
    }
    cout << hi << "\n";
}
