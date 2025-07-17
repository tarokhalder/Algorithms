#include <bits/stdc++.h>

using namespace std;

float area(int  a, int b , int c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s -c));
}

int main() {
     int a , b , c;
     cin >> a >> b >> c;
     cout <<  area(a , b , c) << "\n";
     return 0;
}
