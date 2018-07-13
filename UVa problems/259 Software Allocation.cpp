//#define Q259
#ifdef Q259

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef unsigned long long llu;
#define inf 1000000000

vvi res,graph;
vi p,vis;
int mf=0,f,s = 0,t = 37;
vi ans;
void augment(int v, int minEdge){
    if(v == s) {f = minEdge; return ;}
    else if(p[v] != -1) {
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}

/*int edmondKarp(){
    mf = 0;
    while(1){
        vis.clear();vis.resize(38,0); vis[0] = 1;
        p.clear();p.resize(38,-1);
        queue<int> q; q.push(0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(auto v: graph[u])
                if(res[u][v] > 0 && !vis[v]) vis[v] = 1, q.push(v), p[v] = u;
        }
        augment(t,inf);
        if(f == 0) break;
        mf += f;

    }
    return mf;
}*/
int main(){
    ios::sync_with_stdio(0);
    string str;
    while(1){
        res.clear();res.resize(38,vi(38,0));
        graph.clear(); graph.resize(38);
        int count=0;
        for(int i = 27; i < 37; i++) {
            graph[i].push_back(t);
            graph[t].push_back(i);
            res[i][t] = 1;
        }
        while(getline(cin, str) && cin && !str.empty()){
            //if(str.empty()) break;
            res[0][(int)(str[0])-64] = (int)(str[1])-48;//source to apps = users
            graph[0].push_back((int)str[0]-64);
            graph[(int)str[0]-64].push_back(0);
            count += (int)(str[1])-48;

            for (int i = 3; i < str.size()-1; ++i) {
                //res[(int)(str[i])-21][37] = 1;//comps to sink = 1
                graph[(int)(str[i])-21].push_back((int)(str[0])-64);
                graph[(int)(str[0])-64].push_back((int)(str[i])-21);
                res[(int)str[0]-64][(int)(str[i])-21] = 1;

            }
            /*for (int j = 27; j < 37; ++j) {
                res[(int)(str[0])-64][j] = inf;//between apps & comps
                graph[(int)(str[0])-64].push_back(j);
            }*/
        }
        //cerr << count << endl;
        mf = 0;
        while(1){
            f=0;
            vis.clear();vis.resize(38,0); vis[0] = 1;
            p.clear();p.resize(38,-1);
            queue<int> q; q.push(0);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u == t) break;
                for(auto v: graph[u])
                    if(res[u][v] > 0 && !vis[v]) vis[v] = 1, q.push(v), p[v] = u;
            }
            augment(t,inf);
            if(f == 0) break;
            mf += f;

        }

        int maxflow = mf;
        vi comps(37,0);
        bool ok = false;
        if(maxflow == count){
            for (int i = 27; i < 37; ++i) {
                for (int j = 1; j < 27; ++j) {
                    if(res[i][j]) {
                        comps[i] = j + 64;
                        ok= true;
                        break;
                    }
                }
            }
            for(int i = 27; i < 37; i++) {
                if(comps[i] == 0) cout << "_";
                else cout << (char)(comps[i]);
            }cout << endl;

        }
        else cout << "!\n";
    if(!cin) break;

    }

    return 0;
}

#endif