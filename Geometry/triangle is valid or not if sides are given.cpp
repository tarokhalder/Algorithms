#include <bits/stdc++.h>

using namespace std;

int main() {
    int a , b , c;
    cin >> a >> b >> c;
    if (a + b <= c || b + c <= a || c + a <= b){
       cout << "No" << "\n";
    } else {
       cout << "Yes\n";
    }
    return 0;
}
