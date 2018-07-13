//#define Q314
#ifdef Q314
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
//north : 0 , east : 1 , west : 2 , south : 3
int dxw[] = {0,0,0,1,-1}, dyw[] = {-1,-2,-3,0,0};
int dxe[] = {0,0,0,1,-1}, dye[] = {1,2,3,0,0};
int dxs[] = {1,2,3,0,0}, dys[] = {0,0,0,1,-1};
int dxn[] = {-1,-2,-3,0,0}, dyn[] = {0,0,0,1,-1};

map <iii,viii> mp;
int n,m;
int BFS(ii s, ii d, int dir){
    int si = s.first, sj = s.second, di = d.first, dj = d.second;
    vvvi dist(m,vvi(n,vi(4,inf))), vis(m,vvi(n,vi(4,0)));
    dist[si][sj][dir] = 0; vis[si][sj][dir] = 1;
    queue<iii> q; q.push(iii(dir,ii(si,sj)));
    int dd = dir;
    while(!q.empty()){
        iii fr = q.front(); q.pop();
        int x = fr.first, yi = fr.second.first, yj = fr.second.second;
        //if(dd != x) {dist[yi][yj][x]++, dd = x;}
        if(di == yi && dj == yj) return dist[yi][yj][x];
        for (int i = 0; i < mp[fr].size(); ++i) {
            iii v = mp[fr][i];
            int t = v.first, ui = v.second.first, uj = v.second.second;
            if(dist[ui][uj][t] == inf && !vis[ui][uj][t]) {
                dist[ui][uj][t] = dist[yi][yj][x] + 1;
                //if(t != x) dist[ui][uj][t]++;
                //if(ui == di && uj == dj) return dist[ui][uj][t];
                vis[ui][uj][t] = 1;
                q.push(iii(t,ii(ui,uj)));
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    while(cin >> m >> n && (n || m)){
        vvi grid(m+1,vi(n+1));
        //map <iii,viii> mp;
        mp.clear();
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> grid[i][j];
            }
        }
        string direc;
        int d=0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                d = 0;//north
                for (int k = 0; k < 5; ++k) {
                    if(i+dxn[k] >= 0 && i+dxn[k] < m && j+dyn[k] >= 0 && j+dyn[k] < n){
                        if(grid[i+dxn[k]][j+dyn[k]] != 1){
                            if(k == 3) d = 1; if(k == 4) d = 2;
                            mp[iii(0,ii(i,j))].push_back(iii(d,ii(i+dxn[k],j+dyn[k])));
                        }
                    }
                }

                d = 1;//east
                for (int k = 0; k < 5; ++k) {
                    if(i+dxe[k] >= 0 && i+dxe[k] < m && j+dye[k] >= 0 && j+dye[k] < n){
                        if(grid[i+dxe[k]][j+dye[k]] != 1){
                            if(k == 3) d = 0; if(k == 4) d = 3;
                            mp[iii(1,ii(i,j))].push_back(iii(d,ii(i+dxe[k],j+dye[k])));
                        }
                    }
                }

                d = 2;//west
                for (int k = 0; k < 5; ++k) {
                    if(i+dxw[k] >= 0 && i+dxw[k] < m && j+dyw[k] >= 0 && j+dyw[k] < n){
                        if(grid[i+dxw[k]][j+dyw[k]] != 1){
                            if(k == 3) d = 0; if(k == 4) d = 3;
                            mp[iii(2,ii(i,j))].push_back(iii(d,ii(i+dxw[k],j+dyw[k])));
                        }
                    }
                }

                d = 3;//south
                for (int k = 0; k < 5; ++k) {
                    if(i+dxs[k] >= 0 && i+dxs[k] < m && j+dys[k] >= 0 && j+dys[k] < n){
                        if(grid[i+dxs[k]][j+dys[k]] != 1){
                            if(k == 3) d = 1; if(k == 4) d = 2;
                            mp[iii(3,ii(i,j))].push_back(iii(d,ii(i+dxs[k],j+dys[k])));
                        }
                    }
                }
            }
        }
        int si,sj,di,dj; cin >> si >> sj >> di >> dj >> direc ;
        if(direc == "north") d = 0;
        if(direc == "east") d = 1;
        if(direc == "west") d = 2;
        if(direc == "south") d = 3;

        cout << BFS(ii(si,sj), ii(di,dj), d) << endl;
    }

    return 0;
}


#endif