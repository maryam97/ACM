//#define Q11292
#ifdef Q11292

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m && (n||m)){
        vector<int>dragons(n);
        vector<int>knights(m);
        for (int i = 0; i < n; ++i) {
            cin >> dragons[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> knights[j];
        }
        sort(dragons.begin(),dragons.end());
        sort(knights.begin(),knights.end());
        int k=0,t=0;
        int ans=0;
        for (; k < n && t < m; ++k) {
            while(dragons[k] > knights[t] && t < m) t++;
            if(t==m) break;
            ans+=knights[t];
            t++;
        }
        if(k==n) cout << ans << endl;
        else cout << "Loowater is doomed!\n";
    }
    return 0;
}

#endif