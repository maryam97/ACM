//#define Q11875
#ifdef Q11875

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        cout << "Case " << tc << ": " << vec[n/2] << endl;
    }

    return 0;
}

#endif