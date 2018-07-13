//#define Q11396
#ifdef Q11396

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF 1e9
vvi adj;


int checkBip(int v){
    vi color(v,INF);
    queue<int>q; q.push(0);
    bool isBip = true;
    color[0] = 0;
    while(!q.empty() && isBip){
        int u = q.front(); q.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int V = adj[u][i];
            if(color[V] == INF) color[V] = 1 - color[u], q.push(V);
            else if(color[u] == color[V]) {
                isBip = false;
                break;
            }
        }
    }
    return isBip;
}

int main(){
    ios::sync_with_stdio(0);
    int V,a,b;
    while(cin >> V && V){
        adj.clear();
        adj.resize(V);
        while(cin >> a >> b && (a||b)){
            a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = checkBip(V);
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

#endif