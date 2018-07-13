//
// Created by maryam on 9/29/17.
//

#define Q11231
#ifdef Q11231

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,m,c;
    while(cin >> n >> m >> c && (n || m || c)){
        int a = n - 8 + 1, b = m - 8 + 1;
        double ans = (a * b)/2.0;
        cout << (c? (int)ceil(ans) : (int)floor(ans)) << endl;
    }

    return 0;
}

#endif