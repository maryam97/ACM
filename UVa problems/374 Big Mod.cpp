//
// Created by maryam on 8/28/17.
//
//#define Q374
#ifdef Q374
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll fast_pow(ll a, ll p,ll m){
    ll result = 1, power = p, value = a;
    while(power > 0){
        if(power & 1){
            result = result * value;
            result = result % m;
        }
        value *= value;
        value %= m;
        power /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    ll b,p,m;
    while(cin >> b >> p >> m){
        cout << fast_pow(b, p, m)<< endl;
    }

    return 0;
}

#endif
