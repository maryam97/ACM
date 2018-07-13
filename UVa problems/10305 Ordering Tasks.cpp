//#define Q10305
#ifdef Q10305

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>vis;
vector<int>topo;
void dfs(int u){
    vis[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if(!vis[v])
            dfs(v);
    }
    topo.push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    int n,m,i,j;
    while(cin >> n >> m &&(m||n)){
        adj.clear();vis.clear();
        adj.resize(n);
        vis.resize(n,0);
        topo.clear();
        for (int k = 0; k < m; ++k) {
            cin >> i >> j;
            i--;j--;
            adj[i].push_back(j);
        }
        for (int l = 0; l < n; ++l) {
            if(!vis[l])
                dfs(l);
        }
        cout << topo.back()+1;
        for (int f = topo.size()-2; f >= 0; f--) {
            cout <<" " << topo[f]+1 ;
        }cout << endl;
    }

    return 0;
}

#endif