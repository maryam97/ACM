//
// Created by maryam on 8/28/17.
//
//#define Q11526
#ifdef Q11526

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    int t;cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(!n) cout << 0 << endl;
        else if(n == 1) cout << 1 << endl;
        else if(n == 2) cout << 3 << endl;
        else if(n == 3) cout << 5 << endl;
        else {
            ll sum = n;
            ll num = n, pre = 0;
            ll i = 2, mul = 0;
            ll till = (ll) sqrt(n) - 1;
            for (int tt = 0; tt < till; tt++) {
                pre = n / (i++);
                num -= pre;
                sum += (num * (++mul));
                sum += pre;
                num = pre;
            }
            sum += ((mul + 1) * (pre - till - 1));
            cout << sum << endl;
        }
    }

    return 0;
}

#endif
