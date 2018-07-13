//
// Created by maryam on 9/18/17.
//
//#define Q941
#ifdef Q941

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    vector<long long> f(21);
    f[0] = f[1] = 1;
    for (int i = 2; i <= 20; ++i) {
        f[i] = f[i-1] * i;
    }
    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        long long x; cin >> x;
        for (int i = 0; i < s.size(); ++i) {
            sort(s.begin() + i, s.end());
            //swap(s[i],s[i + x / f[s.size() - i - 1]]);
            swap(s[i] , s[i + x / f[s.size() - 1 - i]]);
            //swap(a[i] , a[i + per / vec[a.size() - 1 - i]]);
            x %= f[s.size() - i -1];
        }
        cout << s << endl;
    }

    return 0;
}

#endif
