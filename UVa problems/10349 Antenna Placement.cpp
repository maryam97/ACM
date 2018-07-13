//#define Q10349
#ifdef Q10349

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

bool check(int a , int b){
    if(a >= 0 && a < n && b >= 0 && b < m)
        return 1;
    return 0;
}

vi match , vis;
vvi graph;

int aug(int l){
    if(vis[l]) return 0;
    vis[l] =1;
    for (int i = 0; i < graph[l].size(); ++i) {
        int r = graph[l][i];
        //if (!vis[r]) {
          //  vis[r] = 1;
            if (match[r] == -1 || aug(match[r])) {
                match[r] = l/*, match[l] = r*/;
                return 1;
            }
        //}
    }
    return 0;
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        cin >> n >> m;
        vvc vec(n , vc(m));
        int sum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> vec[i][j];
        graph.clear(); graph.resize(50 * 50);
        int dx[] = {0 , -1 , 0 , 1};
        int dy[] = {1 , 0 , -1 , 0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vec[i][j] == '*' ){
                    sum++;
                    for (int k = 0; k < 4; ++k) {
                        int x  = i + dx[k] , y = j + dy[k];
                        if (check(x, y)) {
                            if (vec[x][y] == '*') {
                                graph[i * m + j].push_back(x * m + y);
                            }
                        }
                    }
                }
            }
        }
        int mc = 0;
        match.assign(50 * 50, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vec[i][j] == '*' && match[i * m + j] == -1) {
                    vis.assign(50 * 50, 0);
                    mc += aug(i * m + j);
                }
            }
        }
        /*for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vec[i][j] == '*' && match[i * m + j] == -1) {
                    mc++;
                }
            }
        }*/
        cout << sum - mc << endl;
    }

    return 0;
}

#endif