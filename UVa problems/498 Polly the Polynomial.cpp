//
// Created by maryam on 8/29/17.
//
//#define Q498
#ifdef Q498

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    string coefs, xs;
    while(getline(cin, coefs)){
        vector<ll> coef;
        stringstream ss(coefs);
        ll c;
        while(ss >> c){
            coef.push_back(c);
        }
        getline(cin, xs);
        stringstream s(xs);
        ll x;
        int sz = coef.size();
        //cout << sz << endl;
        vector<ll> X;
        while(s >> x) {
            X.push_back(x);
        }
        vector<ll> answer;
        for (int i = 0; i < X.size(); ++i) {
            ll ans = 0;
            for (int j = 0; j < sz; ++j) {
                ans += (coef[j] * ((ll) pow((double) X[i], sz - j - 1)));
            }
            answer.push_back(ans);
        }
        cout << answer[0];
        for (int j = 1; j < answer.size(); ++j) {
            cout << " " << answer[j];
        }
        cout << endl;
    }

    return 0;
}

#endif
