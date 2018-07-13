//
// Created by maryam on 9/25/17.
//
//#define Q10161
#ifdef Q10161

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define inf 2000000001
int main(){
    ios::sync_with_stdio(0);
    ll n;
    map<ll,ll> sqr;
    for (ll i = 1; i*i < inf; i+=2) {
        sqr[i*i] = i;
    }
    while(cin >> n && n){
        if(sqr.find(n) != sqr.end()) cout << "1 " << sqr[n] << endl;
        else {
            ll odd1, odd2, ev, num;
            ll sq = (ll) sqrt(n);
            if (sq % 2) odd1 = sq, odd2 = sq + 2, ev = sq + 1;
            else odd1 = sq - 1, odd2 = sq + 1, ev = sq;
            num = odd1*odd1;
            ll y = odd1, x = 1;
            bool ok = false;
            for (int i = 0; i <= (odd2*odd2 - odd1*odd1) ; ++i) {
                y++; num++;
                if(num == n) break;
                for (int j = 0; j < ev - 1; ++j) {
                    x++; num++;
                    if(num == n) {
                        ok = true;
                        break;
                    }

                }
                if(ok) break;
                for (int j = 0; j < ev - 1; ++j) {
                    y--; num++;
                    if(num == n) {
                        ok = true;
                        break;
                    }

                }
                if(ok) break;
                x++; num++;
                if(num == n) break;

                for (int j = 0; j < ev; ++j) {
                    y++; num++;
                    if(num == n) {
                        ok = true;
                        break;
                    }

                }
                if(ok) break;
                for (int j = 0; j < ev - 1; ++j) {
                    x--; num++;
                    if(num == n) {
                        ok = true;
                        break;
                    }

                }
                if(ok) break;
            }
            cout << x << " " << y << endl;
        }
    }

    return 0;
}

#endif
