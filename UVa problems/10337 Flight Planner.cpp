#define Q110337
#ifdef Q110337

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
#define inf 10000000
#define sup 1e-9
#define pi acos(-1)
vvi wind, memo;
int col;
int sol(int x, int y){
    //if(x < 0 || x > 9 || y > col - 1) return inf;
    if(y == col) if(x == 9) return 0; else return inf;
    if(memo[x][y] != inf) return memo[x][y];
    //int ans = inf;
    //if(y + 1 <= col)
    memo[x][y] = min(memo[x][y], sol(x, y + 1) + 30 - wind[x][y]); // forward
    if(x - 1 >= 0)
        memo[x][y] = min(memo[x][y], sol(x - 1, y + 1)+ 60 - wind[x][y]); // up
    if(x + 1 <= 9)
        memo[x][y] = min(memo[x][y], sol(x + 1, y + 1)+ 20  - wind[x][y]); // down

    return memo[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    int t, x; cin >> t;
    while(t--){
        wind.clear();
        cin >> x;
        col = x / 100;
        wind.resize(10, vi(col));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> wind[i][j];
            }
        }
        memo.clear(); memo.resize(11, vi(1010,inf));
        //memo[9][0] = 0;
        cout << sol(9, 0) << endl << endl;
    }
    return 0;
}




#endif