#define Q119117
#ifdef Q119117

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int n; cin >> n;
        map<string, int> m;

        for (int j = 0; j < n; ++j) {
            string s; cin >> s;
            int h; cin >> h;
            m[s] = h;
        }
        int D; cin >> D;
        string q; cin >> q;
        if(m[q] <= D && m[q] != 0) cout << "Case " << i + 1 << ": Yesss\n";
        else if(m[q] > D && m[q] <= D + 5) cout << "Case " << i + 1 << ": Late\n";
        else cout << "Case " << i + 1 << ": Do your own homework!\n";
    }


    return 0;
}

#endif