//#define Q558
#ifdef Q558

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1000000

int main(){
    ios::sync_with_stdio(0);
    int tc,n,m,x,y,t; cin >> tc;
    while(tc--){
        cin >> n >> m;
        vvii adjmat(n);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> t;
            adjmat[x].push_back(ii(y,t));
        }
        vi dist(n,inf); dist[0]=0;
        for (int v = 0; v < n - 1; ++v) {
            bool up = false;
            for (int j = 0; j < n; ++j) {
                for(auto &i:adjmat[j]){
                    if(dist[i.first] > dist[j] + i.second){
                        dist[i.first] = dist[j] + i.second;
                        up = true;
                    }
                }
            }
            if(!up) break;
        }
        bool hasnegcir = false;
        for (int i = 0; i < n && !hasnegcir; ++i) {
            for(auto &e:adjmat[i]){
                if(dist[e.first] > dist[i] + e.second){
                    hasnegcir = true;
                    break;
                }
            }
        }
        if(hasnegcir) cout << "possible\n";
        else cout << "not possible\n";
    }


    return 0;
}

#endif