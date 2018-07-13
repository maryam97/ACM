//#define Q10888
#ifdef Q10888

#include "bits/stdc++.h"
using namespace std;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
    int n = int(cost.size());

    // construct dual feasible solution
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++) {
        u[i] = cost[i][0];
        for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++) {
        v[j] = cost[0][j] - u[0];
        for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }

    // construct primal solution satisfying complementary slackness
    Lmate = VI(n, -1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Rmate[j] != -1) continue;
            if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
                Lmate[i] = j;
                Rmate[j] = i;
                mated++;
                break;
            }
        }
    }

    VD dist(n);
    VI dad(n);
    VI seen(n);

    // repeat until primal solution is feasible
    while (mated < n) {

        // find an unmatched left node
        int s = 0;
        while (Lmate[s] != -1) s++;

        // initialize Dijkstra
        fill(dad.begin(), dad.end(), -1);
        fill(seen.begin(), seen.end(), 0);
        for (int k = 0; k < n; k++)
            dist[k] = cost[s][k] - u[s] - v[k];

        int j = 0;
        while (true) {

            // find closest
            j = -1;
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;

            // termination condition
            if (Rmate[j] == -1) break;

            // relax neighbors
            const int i = Rmate[j];
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }

        // update dual variables
        for (int k = 0; k < n; k++) {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];

        // augment along path
        while (dad[j] >= 0) {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;

        mated++;
    }

    double value = 0;
    for (int i = 0; i < n; i++)
        value += cost[i][Lmate[i]];

    return value;
}
vi vis;
vvi adj;
int sz;
#define inf 1e9
int bfs(int s, int d){
   vi dist(sz,(int)inf);
    dist[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for (int i = 0; i < adj[v].size(); ++i) {
            int u = adj[v][i];
            if(dist[u] == inf){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[d];
}
int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        int h, w; cin >> h >> w;
        sz = h * w + 2;
        vvc grid(h, vc(w));
        adj.assign(sz, vi());
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        int dx[] = {1 , 0 , -1, 0}, dy[] = {0, 1, 0, -1};
        vi left, right;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(grid[i][j] != '#') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#') {
                            adj[i * w + j].push_back(x * w + y);
                            adj[x * w + y].push_back(i * w + j);
                        }
                    }
                    if(grid[i][j] == 'B') left.push_back(i * w + j);
                    if(grid[i][j] == 'X') right.push_back(i * w + j);
                }
            }
        }
        VVD cost(right.size(), VD(left.size()));
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                cost[i][j] = bfs(left[i], right[j]);
                //cout << cost[i][j] << endl;
            }
        }
        cout << (long long)MinCostMatching(cost, left, right) << endl;

    }
    return 0;
}

#endif