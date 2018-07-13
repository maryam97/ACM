
//#define Q10746
#ifdef Q10746
#include <bits/stdc++.h>

using namespace std;
//typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vll;
//typedef vector<vi> vvi;
//typedef vector<vll> vvll;
//typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
//typedef pair<int,int> ii;
//typedef pair<int,ii> iii;
//typedef vector<iii> viii;
//typedef vector<ii> vii;
//typedef vector<viii> vviii;
//typedef vector<vii> vvii;
//typedef  stack<int> si;
typedef queue<int> qi;
typedef map<int,int> mii;
#define inf 1e9
#define sup 1e-9

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef double L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
using namespace std;
const L INF = numeric_limits<L>::max() / 4;


struct MinCostMaxFlow {
    int N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;

    MinCostMaxFlow(int N) :
            N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
            found(N), dist(N), pi(N), width(N), dad(N) {}

    void AddEdge(int from, int to, L cap, L cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(int s, int k, L cap, L cost, int dir) {
        L val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k]) {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }

    L Dijkstra(int s, int t) {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;

        while (s != -1) {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++) {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }

        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }

    pair<L, L> GetMaxFlow(int s, int t) {
        L totflow = 0, totcost = 0;
        while (L amt = Dijkstra(s, t)) {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first) {
                if (dad[x].second == 1) {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                } else {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};

// BEGIN CUT
// The following code solves UVA problem #10594: Data Flow



// END CUT

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m && (n || m) ){

        MinCostMaxFlow mcmf(m + n + 2);
        for(int i = 1; i <= n ; i++) mcmf.AddEdge(0, i, 1, 0);
        for(int i = n + 1; i <= n + m ; i++) mcmf.AddEdge(i, n + m + 1, 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                double a; cin >> a;
                mcmf.AddEdge(i + 1, j + n + 1, 1,a);
            }
        }
        pair<L, double> res = mcmf.GetMaxFlow(0, m + n + 1);
        //double ans = floor(res.second * 100 + 1e-9 + 0.5) / 100.0;
        cout << fixed << setprecision(2) << (res.second / n + 1e-6) << endl;
    }
    return 0;
}

#endif