//
// Created by maryam on 9/3/17.
//
//#define Q10784
#ifdef Q10784

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    long long n;
    int tc = 0;
    while(cin >> n && n){
        double delta = 9 + 8*(n);
        cout << "Case " << ++tc << ": " << (long long)ceil((3 + sqrt(delta) )/2.0 ) << endl;
        //cout << (3 + sqrt(delta))/2.0 << "  " << 3.5 + sqrt(delta) << endl;
    }

    return 0;
}

#endif
