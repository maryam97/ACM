//#define Q11463
#ifdef Q11463

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1000000
vvi adjmat;
int V,d,s;
void warshall(){
    int ans = 0;
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if(adjmat[i][j] > adjmat[i][k] + adjmat[k][j]) {
                    adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int t,E,a,b; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> V >> E;
        adjmat.clear();adjmat.resize(V+1,vi(V+1,inf));

        for (int i = 0; i < E; ++i) {
            cin >> a >> b;
            adjmat[a][b] = adjmat[b][a] = 1;
        }
        for (int i = 0; i < V; ++i) {
            adjmat[i][i] = 0;
        }
        warshall();
        int ans = -inf;

        cin >> s >> d;
        for (int j = 0; j < V; ++j) {
            ans = max(ans , adjmat[s][j]+adjmat[j][d]);
        }
        cout << "Case " << tc << ": " << ans <<endl;
    }

    return 0;
}


#endif