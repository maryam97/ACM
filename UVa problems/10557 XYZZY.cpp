//#define Q10557
#ifdef Q10557

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1e9
vi dist;
vi vis;
vvii adjlist;
int n;
void bellmanFord(){
    dist.clear();dist.resize(n,-inf);
    dist[0] = 100;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto & e:adjlist[j]) {
                if(dist[j] + e.second > 0) {
                    dist[e.first] = max(dist[e.first] , dist[j] + e.second);
                }
            }
        }
    }

}
void dfs(int u){
    vis[u] = 1;
    for (int i = 0; i < adjlist[u].size(); ++i) {
        int v = adjlist[u][i].first;
        if(!vis[v]) dfs(v);
    }

}
int main(){


    ios::sync_with_stdio(0);
    int door,w,a;
    while(cin >> n && (n!=-1)){
        adjlist.clear();
        adjlist.resize(n);
        vis.clear(); vis.resize(n,0);
        for (int i = 0; i < n; ++i) {
            cin >> w >> door;
            while(door--){
                cin >> a;
                adjlist[i].push_back(ii(a-1,w));
            }
        }
        bellmanFord();

        if(dist[n-1] > 0) cout << "winnable\n";
        else{
            bool haspos = false;
            for (int i = 0; i < n && !haspos; ++i) {
                for(auto & e: adjlist[i]){
                    if(dist[i] + e.second > 0 && dist[e.first] < dist[i] + e.second){
                        vis.clear(); vis.resize(n,0);
                        dfs(i);
                        if(vis[n-1] ){
                            haspos = true;
                            break;
                        }
                    }
                }
            }
            if(haspos) cout << "winnable\n";
            else cout << "hopeless\n";
        }
    }

    return 0;
}

#endif