//#define Q988
#ifdef Q988

#include "bits/stdc++.h"
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1000000000
vvi graph;
vi vis,order;

void toposort(int v){
    vis[v] = 1;
    for(auto & i : graph[v]) if(!vis[i]) toposort(i);
    order.push_back(v);
}

int main(){
    ios::sync_with_stdio(0);
    int n,w,a,tc =0;
    while(cin >> n && n){
        if(tc++) cout << endl;
        graph.clear();graph.resize(n);
        vis.clear(); vis.resize(n,0);
        order.clear();
        for (int i = 0; i < n; ++i) {
           cin >> w;
            while(w--){
                cin >> a;
                graph[i].push_back(a);
            }
        }
        for (int j = 0; j < n; ++j) {
            if(!vis[j]) toposort(j);
        }

        vi ways(n,0);
        ways[0] = 1;
        int ans = 0;
        for (int i = order.size()-1; i >= 0; i--) {
            int n = order[i];
            if(graph[n].size()==0) ans+=ways[n];
            for(auto &a: graph[n])  {
                ways[a] += ways[n];
               // cout <<"a: " << a << "ways: " << ways[a] << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
#endif