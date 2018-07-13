//#define Q10913
#ifdef Q10913

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef unsigned long long llu;
#define inf 1000000000
int n,k;
vvi grid, memo, adj;
vi num,vis;
int sol(int cur, int rem){

    if(rem < 0) return -inf;
    vis[cur] = 1;
    if(cur == (n)*(n)-1) return 0;
    if(memo[cur][rem] != -inf) return memo[cur][rem];
    //int ans = inf - 1;
    int & t = memo[cur][rem], ans;
    if(t != -inf) return t;
    t = -inf - 1;
    for(auto &e : adj[cur]){
        if(!vis[e]) {
            ans = sol(e, ((num[cur] < 0) ? (rem - 1) : rem));
            if (ans > -inf) t = max(ans + num[cur], t);
        }
    }

    return t;/*memo[cur][rem] = ans;*/
}
int main(){
    ios::sync_with_stdio(0);
    int tc = 0;
    int dx[] = {0,1,0};
    int dy[] = {-1,0,1};
    while(cin >> n >> k && (n||k)){
        grid.clear();
        grid.resize(n,vi(n));
        memo.clear();
        memo.resize((n+1)*(n+1),vi(6,-inf));
        adj.clear(); adj.resize((n+1)*(n+1));
        num.clear();num.resize((n+1)*(n+1));
        vis.clear();vis.resize((n+1)*(n+1),0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                num[n*i+j] = grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if(i+dx[k] >=0 && i+dx[k]<n && j+dy[k] >= 0 && j+dy[k]<n){
                        adj[n*i+j].push_back(n*(i+dx[k])+j+dy[k]);
                    }
                }
            }
        }
        /*
        for (int i = 0; i < (n)*(n); ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                cout << adj[i][j] << " ";
            }cout << endl;
        }
        cout << "---------------\n";*/
        cout << "Case "<< ++tc << ": ";
        int ans = sol(0,(num[0] < 0 ) ? k-1 : k);
        if(ans <= -inf) cout << "impossible\n";
        else cout << ans << endl;

    }

    return 0;
}

#endif
/*
 4 1
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1
4 0
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1
0 0
 */