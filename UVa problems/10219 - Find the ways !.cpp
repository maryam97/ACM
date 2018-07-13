//
// Created by maryam on 9/3/17.
//
//#define Q10219
#ifdef Q10219

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,k;
    while(cin >> n >> k){
        k = max(n-k,k);
        double a = 0, b = 0;
        for (int i = n; i > k ; --i)  a += log10(i);
        for (int i = 1; i <= n - k; ++i)  b += log10(i);
        cout << floor(a - b + 1) << endl;
    }

    return 0;
}

#endif
