//#define Q11506
#ifdef Q11506
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
typedef queue<int> qi;
typedef map<int,int> mii;
#define inf 1000000000
#define sup 1e-9
vvi res, graph;

int s, t, f, mf; //s is start node, t is destination, fill s and t in main. mf will hold the max flow.
vi p;
void augment(int v, int minEdge) {
    if(v == s) {
        f = minEdge; return;
    }
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
void edmonsKarp(int n) { // n is the graph size. answer is in mf after calling this method.
    //mf = 0;
    while (1) {
        f = 0;
        vector<bool> vis(n, false);
        vis[s] = true;
        p.clear();
        p.resize(n, -1);
        queue<int> queue1;
        queue1.push(s);
        while (!queue1.empty()) {
            int u = queue1.front();
            queue1.pop();
            if (u == t) break;
            for (auto &e : graph[u]) {
                if (res[u][e] > 0 && !vis[e]) vis[e] = true, queue1.push(e), p[e] = u;
            }
        }
        augment(t, inf);
        if (f == 0) break;
        mf += f;
    }
}

int main(){
    ios::sync_with_stdio(0);
    int m, w;
    while(cin >> m >> w && (m||w)){
        int n = 2 * m;
        mf = 0;
        graph.clear();
        graph.resize(n + 2);
        res.clear();
        res.resize(n + 2,vi(n + 2 , 0));
        s = 0, t = n - 1;
        //res[0][m] = res[m-1][n - 1] = inf;
        res[s][s+m] = inf;
        graph[s].push_back(s+m); graph[s+m].push_back(s);
        res[m-1][m+m-1] = inf;
        graph[m-1].push_back(m+m-1); graph[m+m-1].push_back(m-1);

        int id,c,j,k,d;
        for (int i = 0; i < m - 2; ++i) {
            cin >> id >> c;
            id--;
            res[id][id + m] = c;
            graph[id].push_back(id + m); graph[id + m].push_back(id);
        }
        for (int i = 0; i < w; ++i) {
            cin >> j >> k >> d;
            j--, k--;
            res[j + m][k] = res[k + m][j] = d;
            graph[j + m].push_back(k); graph[k].push_back(j + m);
            graph[k + m].push_back(j); graph[j].push_back(k + m);
        }
        edmonsKarp(n+2);
        cout << mf << endl;
    }


    return 0;
}


#endif