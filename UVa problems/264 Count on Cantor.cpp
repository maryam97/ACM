//
// Created by maryam on 9/22/17.
//
//#define Q264
#ifdef Q264

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        int f = (int)((sqrt(8*n-7) + 1)/2);
        int s = (f*(f-1))/2 + 1;
        if(f % 2 == 0)
            cout << "TERM " << n << " IS " << 1 + n - s <<"/" << f - (n - s) <<"\n";
        else
            cout << "TERM " << n << " IS " << f - (n - s) <<"/" << 1 + n - s <<"\n";
    }
    return 0;
}

#endif
