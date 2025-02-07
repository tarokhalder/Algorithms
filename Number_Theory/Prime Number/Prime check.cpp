#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
   cin >> n;
   bool ok = true;
   for(int i = 2; i < n; i++) {
      if(n % i == 0) {
         ok = false;                //O(N) solution
	 break;
      }
   }

   cout << ( ok ? "YES" : "NO" ) << endl;
   return 0;
}
