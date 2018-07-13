//#define Q796
#ifdef Q796

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
vi dfs_num, dfs_low, dfs_par;
vii bridge;
int dfsNumberCounter;

void find_bridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int i = 0; i < adjlist[u].size(); ++i) {
        int v = adjlist[u][i];
        if(dfs_num[v] == 0){
            dfs_par[v] = u;
            find_bridge(v);
            if(dfs_num[u] < dfs_low[v]) bridge.push_back(ii(min(u,v),max(u,v)));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_par[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int num;
    while(cin >> num){
         adjlist.clear();
         adjlist.resize(num);
         for (int i = 0; i < num; ++i) {
             char c;
             int a, n, b; cin >> a >> c >> n >> c;
             for (int j = 0; j < n; ++j) {
                 cin >> b;
                 adjlist[a].push_back(b);
                 adjlist[b].push_back(a);
             }
         }
    dfs_num.assign(num,0); dfs_low.assign(num,0); dfs_par.assign(num,0);
        dfsNumberCounter = 0; bridge.clear();
        for (int k = 0; k < num; ++k) {
            if(dfs_num[k] == 0){
                find_bridge(k);
            }
        }
        sort(bridge.begin(), bridge.end());
        cout << bridge.size() << " critical links\n";
        for (int l = 0; l < bridge.size(); ++l) {
            cout << bridge[l].first << " - " << bridge[l].second << endl;
        }cout << endl;
    }


    return 0;
}

#endif