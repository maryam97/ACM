//#define Q10653
#ifdef Q10653

#include <bits/stdc++.h>
using namespace std;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define INF 1e9
vvi grid;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int R,C;
int BFS(ii s, ii d){
    queue<ii>q; q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(u == d) break;
        for (int i = 0; i < 4; ++i) {
            if(u.first+dx[i]>0 && u.first+dx[i]<R && u.second+dy[i]>0 && u.second+dy[i]<C) {
                if (grid[u.first + dx[i]][u.second + dy[i]] != -1) {
                    grid[u.first + dx[i]][u.second + dy[i]] = grid[u.first][u.second] + 1;
                    q.push(make_pair(u.first + dx[i], u.second + dy[i]));
                }
            }
        }
    }
    return grid[d.first][d.second];
}

int main(){
    ios::sync_with_stdio(0);
    int r,n,c,sc,sr,dc,dr;
    while(cin >> R >> C && (R||C)){
        grid.clear();
        grid.resize(R,vi(C,0));
        cin >> r;
        for (int i = 0; i < R; ++i) {
            cin >> r >> n;
            for (int j = 0; j < n; ++j) {
                cin >> c;
                grid[r][c] = -1;
            }
        }
        cin >> sr >> sc >> dr >> dc;
        cout << BFS(make_pair(sr,sc),make_pair(dr,dc)) << endl;

    }
    return 0;
}

#endif