//
// Created by maryam on 9/4/17.
//
//#define Q10940
#ifdef Q10940

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n){
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        int a = n - pow(2.0,(int)log2(n));
        if(!a) a = n / 2;
        cout << a*2 << endl;
    }

    return 0;
}


#endif
