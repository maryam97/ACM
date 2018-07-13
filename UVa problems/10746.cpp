//#define Q107
#ifdef Q107

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
typedef queue<ii> qii;
typedef pair<int , double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned long long ull;
typedef pair<double , double > dd;
typedef vector<dd> vdd;
#define inf 1e9
#define sup 1e-9
#define pi acos(-1)
int n_node;
int n_edge;
#define INT_MAX 1e9
double cost[405][405]; // cost[i][j] = -cost[j][i]
int residual[405][405];

bool bellman_ford(int& flow_sum, double&cost_sum) { // 0: start, n_node - 1: end
    double min_cost[405]; for (int i = 0; i < n_node; i++) min_cost[i] = inf; min_cost[0] = 0;
    int pre_node[405]; pre_node[0] = 0;
    int max_flow[405];
    int in_queue[405]; memset(in_queue, 0, sizeof(in_queue));

    queue<int> q;
    q.push(0);
    while (q.size()) {
        int cur = q.front(); q.pop();
        in_queue[cur] = 0;

        for (int i = 0; i < n_node; i++) {
            if (residual[cur][i] > 0 && min_cost[i] > min_cost[cur] + cost[cur][i]) {
                min_cost[i] = min_cost[cur] + cost[cur][i];
                pre_node[i] = cur;
                max_flow[i] = min(max_flow[cur], residual[cur][i]);

                if (in_queue[i] == 0) {
                    in_queue[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    if (min_cost[n_node - 1] == inf)
        return false;
    flow_sum += max_flow[n_node - 1];
    cost_sum += max_flow[n_node - 1] * min_cost[n_node - 1];
    for (int cur = n_node - 1; cur != 0; cur = pre_node[cur]) {
        residual[pre_node[cur]][cur] -= max_flow[n_node - 1];
        residual[cur][pre_node[cur]] += max_flow[n_node - 1];
    }
    return true;
}

void min_cost_max_flow() {
    int flow_sum = 0;
    double cost_sum = 0;
    while (bellman_ford(flow_sum, cost_sum));
    cout << flow_sum << " " << cost_sum << endl;
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m && (n || m) ){
        n_node = m + n + 2;
        //memset(residual, 0, sizeof(residual));
        //memset(cost, INT_MAX, sizeof(cost));
        for(int i = 1; i <= n ; i++) residual[0][i] = 1, cost[0][i] = 0;
        for(int i = n + 1; i <= n + m ; i++) residual[i][m + n + 1] = 1, cost[i][m + n + 1] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                double a; cin >> a;
                residual[i][j] = 1, cost[i][j] = a;
            }
        }
        //pair<L, double> res = mcmf.GetMaxFlow(0, m + n + 1);
        //double ans = floor(res.second * 100 + 1e-9 + 0.5) / 100.0;
        //cout << fixed << setprecision(2) << (res.second / n + 1e-6) << endl;
        min_cost_max_flow();
    }
    return 0;
}


#endif