//
// Created by maryam on 8/28/17.
//
//#define Q10104
#ifdef Q10104

#include "bits/stdc++.h"
using namespace std;

int x, y, d;
void extendedEuclid(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    } // base case
    extendedEuclid(b, a % b); // similar as the original gcd
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    ios::sync_with_stdio(0);
    int a,b;
    while(cin >> a >> b){
        extendedEuclid(a, b);
        cout << x << " " << y << " " << d << endl;
    }

    return 0;
}

#endif
