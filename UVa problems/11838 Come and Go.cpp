//#define Q11838
#ifdef Q11838


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
            int x = S.back();
            S.pop_back();
            visited[x] = 0;
            if (x == u) break;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m && (n||m)){
        int v,w,p;
        adjlist.clear(); adjlist.resize(n);
        while(m--){
            cin >> v >> w >> p;
            v--, w--;
            adjlist[v].push_back(w);
            if(p == 2) adjlist[w].push_back(v);
        }
        dfs_num.assign(n,0); dfs_low.assign(n,0);visited.assign(n,0);
        dfsNumcounter = numSCC = 0;
        for (int i = 0; i < n; ++i) {
            if(dfs_num[i] == 0)
                tarjan(i);
        }
        if(numSCC == 1) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}

#endif