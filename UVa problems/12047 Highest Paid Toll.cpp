//#define Q12047
#ifdef Q12047

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

vvii adjlist1,adjlist2;
int n,m,s,t,p,u,v,c;
vi dist1, dist2;
void dijkstra(int st, vi & dist , vvii & adjlist){
    dist[st] = 0;
    priority_queue<ii , vii, greater<ii> > pq; pq.push(ii(0,st));
    while(!pq.empty()){
        ii fr = pq.top(); pq.pop();
        int d = fr.first, u = fr.second;
        if(d > dist[u]) continue;
        for(auto &e: adjlist[u]){
            if(dist[e.first] > e.second + dist[u]) {
                dist[e.first] = e.second + dist[u];
                pq.push(ii(dist[e.first],e.first));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int tc;cin >> tc;


    while(tc--){
        cin >> n >> m >> s >> t >> p;
        adjlist1.clear(); adjlist1.resize(n+1);
        adjlist2.clear(); adjlist2.resize(n+1);
        while(m--){
            cin >> u >> v >> c;
            adjlist1[u].push_back(ii(v,c));
            adjlist2[v].push_back(ii(u,c));
        }
        dist1.clear(); dist1.resize(n+1,inf);

        dijkstra(s, dist1,adjlist1);


        dist2.clear(); dist2.resize(n+1,inf);
        dijkstra(t, dist2,adjlist2);


        int mx = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < adjlist1[i].size(); ++j) {
                ii v = adjlist1[i][j];
                if(dist1[i] + v.second + dist2[v.first] <= p)
                    if(mx < v.second) mx = v.second;
            }
        }
        cout << mx << endl;

    }
    return 0;
}
#endif