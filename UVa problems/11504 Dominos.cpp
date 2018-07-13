//#define Q11504
#ifdef Q11504

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef unsigned long long llu;
#define inf 1000000000

vvi adjlist;
vi dfs_num, dfs_low, visited, S;
int dfsNumcounter, numSCC;
void tarjan(int u){
    dfs_low[u] = dfs_num[u] = dfsNumcounter++;
    S.push_back(u);
    visited[u] = 1;
    for (int i = 0; i < adjlist[u].size(); ++i) {
        int v = adjlist[u][i];
        if (dfs_num[v] == 0)
            tarjan(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]) {
        ++numSCC;
        while (1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            if (v == u) break;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        int n,m,a,b;
        cin >> n >> m;
        adjlist.clear(); adjlist.resize(n);

        while(m--){
            cin >> a >> b;
            a--, b--;
            adjlist[a].push_back(b);
            //adjlist[b].push_back(a);
        }
        dfs_num.assign(n,0); dfs_low.assign(n,0);visited.assign(n,0);
        dfsNumcounter = numSCC = 0;
        for (int i = 0; i < n; ++i) {
            if(dfs_num[i] == 0)
                tarjan(i);
        }
        cout << numSCC << endl;
    }
    return 0;
}

#endif