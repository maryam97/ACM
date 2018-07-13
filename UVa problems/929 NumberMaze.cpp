#define Q929
#ifdef Q929

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1e9
vvii adjList;
vvi graph,num;
int main(){
    ios::sync_with_stdio(0);
    int N,M,T,n;
    cin >> T;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    while(T--){
        cin >> N >> M;
        int count = -1;
        graph.resize(N,vi(M));
        num.resize(N,vi(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> graph[i][j];
                num[i][j] = ++count;
            }
        }
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < M; ++i) {
                for (int  l= 0;  l<4 ; l++) {
                    if(k+dx[l]>=0 && k+dx[l]<N && i+dy[l]>=0 && i+dy[l]<M){
                        adjList[num[k][i]].push_back(ii(graph[k][i],num[k+dx[l]][i+dy[l]]));
                    }
                }

            }
        }

        vi dist(count, inf);
        priority_queue<ii,vii,greater<ii>> pq;
        pq.push(0,0);
        while(!pq.empty()){
            ii front = pq.top();pq.pop();
            int d = front.first, u = front.second;
            if(dist[u] < d) continue;
            for (int i = 0; i < adjList[u].size(); ++i) {
                ii v = adjList[u][i];
                if(dist[u] + v.second > dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first] , v.first));
                }
            }
        }
    }

    return 0;
}

#endif