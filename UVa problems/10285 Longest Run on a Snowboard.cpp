//#define Q10285
#ifdef Q10285

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1000000
vvi graph;
vvi vis;
vii order;
int r,c;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void toposort(int i,int j){
    vis[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        if(i+dx[k] >=0 && i+dx[k] < r && j+dy[k] >= 0 && j+dy[k] < c)
            if(!vis[i+dx[k]][j+dy[k]] && graph[i][j] > graph[i+dx[k]][j+dy[k]]) toposort(i+dx[k], j+dy[k]);
    }
    order.push_back(ii(i,j));
}

int main(){
    ios::sync_with_stdio(0);
    int t; cin >> t;
    string  name;
    while(t--){
        cin >> name >> r >> c;
        graph.clear();graph.resize(r+1,vi(c+1));
        vis.clear(); vis.resize(r,vi(c,0));
        order.clear();
        vvi dist(r,vi(c,0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i < r ; ++i) {
            for (int j = 0; j < c; ++j) {
                if(!vis[i][j]) toposort(i,j);
            }
        }
        vii revOrder;
        for (int i = order.size()-1; i >= 0; i--) {
            revOrder.push_back(order[i]);
        }
        int mx = -1;
        for (auto & e : revOrder) {
            int i = e.first, j = e.second;
            for (int k = 0; k < 4; ++k) {
                if(i+dx[k] >=0 && i+dx[k] < r && j+dy[k] >= 0 && j+dy[k] < c) {
                    if(graph[i][j] > graph[i+dx[k]][j+dy[k]]) {
                        dist[i + dx[k]][j + dy[k]] = max(dist[i + dx[k]][j + dy[k]], dist[i][j] + 1);
                        mx = max(mx, dist[i + dx[k]][j + dy[k]]);
                   }
                }
            }
        }

        cout << name <<": " << mx+1 << endl;
    }

    return 0;
}

#endif