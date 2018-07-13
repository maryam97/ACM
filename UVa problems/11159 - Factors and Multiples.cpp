//#define Q11159
#ifdef Q11159
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
#define inf 1e9
#define sup 1e-9

int n , m;
vvi adj;
vi match, vis;

int aug(int l){
    if(vis[l]) return 0;
    vis[l] = 1;
    for (int i = 0; i < adj[l].size(); ++i) {
        int r = adj[l][i];
        if(match[r] == -1 || aug(match[r])){
            match[r] = l; return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vi N(n);
        for (int k = 0; k < n; ++k) {
            cin >> N[k];
        }
        cin >> m;
        vi M(m);
        for (int j = 0; j < m; ++j) {
            cin >> M[j];
        }
        adj.clear(); adj.resize(n + m + 2);
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if(( N[k] && M[j] % N[k] == 0) || (M[j] ==0)) {
                    adj[j].push_back(k + m);
                    adj[k + m].push_back(j);
                }
            }
        }
        int MCBM = 0;
        match.assign(n + m + 2, -1);
        for (int l = 0; l < m; ++l) {
            vis.assign(m, 0);
            MCBM += aug(l);
        }
        cout << "Case " << i + 1 << ": " <<  MCBM << endl;
    }

    return 0;
}


#endif