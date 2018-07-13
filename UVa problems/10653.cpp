//#define Q10653
#ifdef Q10653

#include <bits/stdc++.h>
using namespace std;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<vector<ii>> vvii;
#define INF 1000000000
vvi grid;
vvii adj;
int dX[]={-1,1,0,0};
int dY[]={0,0,1,-1};
int R,C,N;
int BFS(ii s, ii d){
    vvi dist(R , vi(C,INF));
    int sx = s.first, sy = s.second, dx = d.first, dy = d.second;
    dist[sx][sy] = 0;
    queue<ii>q; q.push(ii(sx,sy));
    while(!q.empty()){
        ii u = q.front(); q.pop();
        int ux = u.first, uy = u.second;

        for (int k = 0; k < 4; ++k) {
            if (ux + dX[k] >= 0 && ux + dX[k] < R && uy + dY[k] >= 0 && uy + dY[k] < C) {
                if (grid[ux + dX[k]][uy + dY[k]] == 1 && dist[ux + dX[k]][ uy + dY[k]] == INF) {
                    dist[ux + dX[k]][ uy + dY[k]] = dist[ux][uy] + 1;
                    if ((ux + dX[k] == dx) && (uy + dY[k] == dy)) return dist[dx][dy];
                    q.push(ii(ux + dX[k], uy + dY[k]));
                }
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    int r,n,c,a,sc,sr,dc,dr;
    while(cin >> R >> C && (R||C)){
        N = R*C;
        grid.clear();
        grid.resize(R,vi(C,1));
        cin >> r;
        for (int i = 0; i < r; ++i) {
            cin >> a >> n;
            for (int j = 0; j < n; ++j) {
                cin >> c;
                grid[a][c] = 0;
            }
        }
        cin >> sr >> sc >> dr >> dc;
        cout << BFS(ii(sr,sc),ii(dr,dc)) << endl;

    }
    return 0;
}

#endif