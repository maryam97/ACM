//#include <bits/stdc++.h>
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


int n,m;
int i1, i2, l1, l2;
vii domino;
map<int, int> vis;
bool sol(int x, int space){
    if(space == 0 && x == l1) return true;
    if(space == 0 && x != l1) return false;
    for (int i = 0; i < domino.size(); ++i) {
        if(domino[i].first == x ) {
            if (!vis[i]) {
                vis[i] = 1;
                if (sol( domino[i].second, space - 1))
                    return true;
                vis[i] = 0;
            }
        }
        else if(domino[i].second == x) {
            if (!vis[i]) {
                vis[i] = 1;
                if(sol(domino[i].first, space - 1))
                    return true;
                vis[i] = 0;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n && n){
        cin >> m;
        cin >> i1 >> i2;
        cin >> l1 >> l2;
        vis.clear();
        domino.clear();
        int x,y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            domino.push_back(make_pair(x,y));
        }
        bool f = sol(i2, n);
        if(f) cout << "YES\n";

        else cout << "NO\n";
    }
    return 0;
}