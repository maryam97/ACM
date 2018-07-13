//
// Created by maryam on 9/19/17.
//
//#define Q11053
#ifdef Q11053

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
int n, a, b, m = 1000000;

ll f(ll x){
    return (((((a * x) % n)* x) % n) + b) % n;
    //return (a*(x*x)+b)%m;
}

pll findCycle(ll x0){
    ll t = f(x0), h = f(f(x0));
    while(t!=h){ t = f(t); h = f(f(h)); }
    ll mu = 0;
    h = x0;
    while(t!=h){ t = f(t); h = f(h); mu++;}
    ll lambda = 1;
    h = f(t);
    while(t!=h){ h = f(h); lambda++;}

    return pll(mu, lambda);
}
int main(){
    ios::sync_with_stdio(0);
    while(cin >> n >> a >> b && n){
        cout << n - (findCycle(0).second) << endl;
    }

    return 0;
}

#endif
