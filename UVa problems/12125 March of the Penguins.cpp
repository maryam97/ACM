#define Q12125
#ifdef Q12125
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

double dist(ii d1, ii d2){
    int x = d1.first, xx = d2.first;
    int y = d1.second, yy = d2.second;
    return (sqrt(((x-xx)*(x-xx)) + ((y-yy)*(y-yy))));
}

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        int n; double d; cin >> n >> d;
        int m = (n + 1), sum = 0;
        res.assign(m * 2, vi(m * 2, 0));
        graph.clear(); graph.resize(m * 2);
        vii cor, tmp(n + 1);
        s = 0;
        for (int i = 1; i <= n; ++i) {
            int x, y, num, mx;
            cin >> x >> y >> num >> mx;
            tmp[i].first = num, tmp[i].second = mx;
            if(num) {
                res[s][i] = num;
                graph[s].push_back(i);
                //graph[i].push_back(s);
            }
            graph[i].push_back(i + n);
            res[i][i + n] = mx;
            cor.push_back(ii(x, y));
            sum += num;
        }
        for (int j = 1; j <= n; ++j) {
            for (int i = j + 1; i <= n; ++i) {
                //double dd = dist(cor[i - 1], cor[j - 1]);
                int xx = cor[j - 1].first, yy = cor[j - 1].second;
                int x = cor[i - 1].first, y = cor[i - 1].second;
                double dis = sqrt(pow(xx - x, 2) + pow(yy - y, 2));
                if( dis <= d){
                    graph[i + n].push_back(j); graph[j + n].push_back(i);
                    res[i + n][j] = res[j + n][i] = inf;
                }
            }
        }
        /*vvi tmp(m * 2, vi(m * 2, 0));
        for (int j = 0; j < res.size(); ++j) {
            for (int i = 0; i < res[j].size(); ++i) {
                tmp[j][i] = res[j][i];
            }
        }*/
        vi ans;
        for (int k = 1; k <= n; ++k) {
            t = k;
            mf = 0;
            for (int p = 1; p <= n; ++p) {
                res[s][p] = tmp[p].first;
                res[p][p+n] = tmp[p].second;
                res[p + n][p] = 0; res[p][s] = 0;
            }
            /*for (int i = 0; i < tmp.size(); ++i) {
                for (int j = 0; j < tmp[i].size(); ++j) {
                    res[i][j] = tmp[i][j];
                }
            }*/
            //res = tmp;
            m = graph.size();
            edmonsKarp(m);
            if(sum == mf) ans.push_back(k - 1);
        }
        if(!ans.size()) cout << "-1\n";
        else {
            cout << ans[0];
            for (int l = 1; l < ans.size(); ++l) {
                cout << " " << ans[l];
            }
            cout << endl;
        }
    }

    return 0;
}

#endif