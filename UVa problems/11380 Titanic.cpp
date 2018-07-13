//#define Q11380
#ifdef Q11380

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef unsigned long long llu;
#define inf 1000000000
vvi adjlist, res;
vi p,vis;
int s ,t,f,mf,n;

void augment(int v, int minEdge){
    if(v == s) {f = minEdge;return;}
    else if(p[v]!= -1)
    {
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}

void edmondKarp(){
    mf = 0;
    while(1){
        f = 0;
        p.clear(); p.resize(n+1,-1);
        vis.clear(); vis.resize(n+1,0);
        vis[s] = 1;
        queue <int> q; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(auto & e:adjlist[u] )
                if(res[u][e] > 0 && !vis[e]) vis[e] = 1, q.push(e), p[e] = u;
        }
        augment(t,inf);
        if(!f) break;
        mf+=f;
    }
}

int main(){
    ios::sync_with_stdio(0);
    int x,y,p;
    int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
    vvi mp(210 , vi(210 , 0));
    mp['.']['.'] = mp['.']['@'] = mp['.']['#'] = 1;
    mp['*']['.'] = mp['*']['@'] = mp['*']['#'] = 1;
    mp['@']['@'] = mp['@']['#'] = inf; mp['@']['.'] = 1;
    mp['#']['#'] = mp['#']['@'] = inf; mp['#']['.'] = 1;
    while(cin >> x >> y >> p){
        vvc grid(x,vc(y));
        adjlist.clear();
        res.clear();
        adjlist.resize(2*x*y+2 , vi(2*x*y+2));
        res.resize(2*x*y+2 , vi(2*x*y+2));
        s = 0, t = 2 * x * y + 1, n = 2 * x * y + 2;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                cin >> grid[i][j] ;
            }
        }

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if(grid[i][j] != '~'){
                    adjlist[i*y + j+1].push_back(i*y + x*y + j+1);
                    adjlist[i*y + x*y + j+1].push_back(i*y + j+1);
                    res[i*y + j+1][i*y + x*y + j+1] = ((grid[i][j] == '.') || (grid[i][j] == '*')) ? 1 : 1000;

                    for (int k = 0; k < 4; ++k) {
                        if(i+dx[k]>=0 && i+dx[k]<x && j+dy[k]>=0 && j+dy[k]<y){
                            if(grid[i+dx[k]][j+dy[k]] != '~'){
                                if(mp[grid[i][j]][grid[i+dx[k]][j+dy[k]]]) {
                                    res[i * y + x * y + j + 1][y * (i + dx[k]) + (j + dy[k]) + 1] = mp[grid[i][j]][grid[i+dx[k]][j+dy[k]]];
                                    adjlist[i * y + x * y + j + 1].push_back(y * (i + dx[k]) + (j + dy[k]) + 1);
                                    adjlist[y * (i + dx[k]) + (j + dy[k]) + 1].push_back(i * y + x * y + j + 1);

                                }
                                /*if(grid[i][j] == '#' || grid[i][j] == '@'){
                                    if(grid[i+dx[k]][j+dy[k]] == '#' || grid[i+dx[k]][j+dy[k]] == '@') res[i*y + x*y + j+1][y*(i+dx[k])+(j+dy[k])+1] = inf;
                                }*/

                            }
                        }
                    }
                    if(grid[i][j] == '*') {
                        adjlist[s].push_back(y*i+j+1);
                        adjlist[i*y+j+1].push_back(s);
                        res[s][i*y+j+1] = 1;
                    }
                    if(grid[i][j] == '#'){
                        adjlist[i*y + x*y + j+1].push_back(t);
                        adjlist[t].push_back(i*y + x*y + j+1);
                        res[i*y + x*y + j+1][t] = p;
                    }
                }

            }
        }
        edmondKarp();
        cout << mf << endl;

    }

    return 0;
}
/*
3 4 2
*~~#
...@
.~.*

3 5 1
~~*~~
#.@.#
~~*~~

1 4 2
**#~
*/

#endif