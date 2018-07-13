//
// Created by maryam on 8/29/17.
//
//
// Created by maryam on 8/29/17.
//
//#define Q498
#ifdef Q498

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll Pow(ll x, ll y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}
int main(){
    ios::sync_with_stdio(0);

    ll x;
    while(cin >> x){
        string coefs;
        cin.get();
        vector<ll> coef;
        getline(cin, coefs);
        stringstream ss(coefs);
        ll c;
        while(ss >> c){
            coef.push_back(c);
        }
        ll sz = coef.size() - 1;
        //cout << sz << endl;
        ll ans = 0;
        for (int j = 0; j < sz; ++j) {
            ans += (coef[j] *(sz - j)* (Pow(x, sz - j - 1)));
        }
        cout << ans << endl;
    }

    return 0;
}

#endif

